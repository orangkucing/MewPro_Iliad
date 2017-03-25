/*
 * GoPro Genlock signal Generator
 *    for Hero 4 Black and Hero 3+ Black
 *    using ATmega2560 16MHz (Arduino Mega 2560 or Seeeduino Mega) or ATmega328PB
 * copyright (c) 2016 Hisashi ITO (info at mewpro.cc)
 * 
 * if the board runs 5V then a logic level converter to 3.3V such as 74HC4050 is needed for interfacing to the camera.
 * 
 * Connection:
 * Arduino Mega 2560
 * 
 * D7  (OC4B/PH4) ------------------------- HSYNC
 * 
 * D8  (OC4C/PH5) ---+
 *                   |
 * D47 (T5/PL2)   ---+
 * 
 * D45 (OC5B/PL4) ------------------------- VSYNC
 * 
 * ATmega328PB
 * 
 * D2  (OC3B/PD2) ------------------------- HSYNC
 * 
 * D0  (OC3A/PD0) ---+
 *                   |
 * D23 (T4/PE1)   ---+
 * 
 * D1  (OC4A/PD1) ------------------------- VSYNC
 * 
 */
volatile uint16_t clock_stretch;

#define SYNC_SIGNAL_DEFAULT HIGH

#if defined(__AVR_ATmega2560__)

ISR(TIMER5_COMPC_vect) {
  // compare match interrupt service routine (Timer 5 C)
  noInterrupts(); // temporary disable other high priority interrupts
  asm volatile(
    // This part of assembly code is equivalent to
    // TCNT4 -= clock_stretch; // this statement takes AVR microcontroller 10 clock cycles to update TCNT4 I/O location
    //
    "lds     r24, %1"   "\n\t"     // 2 clocks
    "lds     r25, %2"   "\n\t"     // 2 clocks
    "sub     r24, %A0"  "\n\t"     // 1 clock
    "sbc     r25, %B0"  "\n\t"     // 1 clock
    "sts     %2, r25"   "\n\t"     // 2 clocks
    "sts     %1, r24"   "\n\t"     // 2 clocks
    :
    : "r" (clock_stretch), "M" (_SFR_MEM_ADDR(TCNT4L)), "M" (_SFR_MEM_ADDR(TCNT4H))
    : "r24", "r25"
  );
  interrupts(); // enable other interrupts again
}

void StartSyncSignal(int vidmode)
{
  unsigned int hsync, vsync, stretch;
  hsync = (unsigned int)pgm_read_word(&syncTime[vidmode][SYNC_TIME_HSYNC]);
  vsync = (unsigned int)pgm_read_word(&syncTime[vidmode][SYNC_TIME_VSYNC]);
  stretch = (unsigned int)pgm_read_word(&syncTime[vidmode][SYNC_TIME_STRETCH]);
  noInterrupts();
  // Note: ATmega2560's fast PWM is buggy.
  //   1. fast PWM mode 15 doesn't work unless TOP < 256.
  //   2. the first match is ignored under certain conditions (see * and **).

  // Timer 5 (VSYNC)
  // COM5B[1:0] = 2 : clear OC5B on compare match, set OC5B at BOTTOM
  // COM5C[1:0] = 0 : OC5C pin disconnected
  // WGM5[3:0] = 14 : fast PWM mode 14
  TCCR5B = _BV(WGM53) | _BV(WGM52); // set no clock source
  TCCR5A = _BV(WGM51); // disconnect OC5B pin (PORTL & _BV(4) is SYNC_SIGNAL_DEFAULT)
  // the following registers can be set properly only after WGMn is set
  OCR5B = vsync - 2; // MATCH
  OCR5C = vsync - 3; // ADVANCE MATCH
  TCNT5 = vsync - 2; // START
  ICR5 = vsync - 1; // TOP
  TCCR5B |= _BV(CS52) | _BV(CS51); // CS5[2:0] = 6 (external clock source on T5. clock on falling edge)

  // * using an external clock source ATmega2560 has a bug that causes the first match ignored
  // WORKAROUND: toggle T5 to go beyond the first
#if SYNC_SIGNAL_DEFAULT==LOW
  TCCR4C |= _BV(FOC4C); TCCR4C |= _BV(FOC4C);
#endif
  for (int i = 0; i < vsync; i++) {
    TCCR4C |= _BV(FOC4C); TCCR4C |= _BV(FOC4C);
  }
  TCCR5A |= _BV(COM5B1); // connect OC5B pin (the internal OC5B register is SYNC_SIGNAL_DEFAULT)
  
  if (stretch != 0) {
    // number of ticks the last HSYNC before VSYNC longer than others
    clock_stretch = stretch - 9; // updating TCNT4 requires 9 clock cycles (562.5ns)
    TIFR5 = _BV(OCF5C);   // clear output compare C match flag
    TIMSK5 = _BV(OCIE5C); // output compare C match interrupt enable
  }

  // Timer 4 (HSYNC)
  // ** keep COM4B[1:0] == COM4C[1:0] otherwise either of the first matches will be ignored
  // COM4B[1:0] = 2 : clear OC4B on compare match, set OC4B at BOTTOM
  // COM4C[1:0] = 2 : clear OC4C on compare match, set OC4C at BOTTOM
  // WGM4[3:0] = 14 : fast PWM mode 14
  TCCR4B = _BV(WGM43) | _BV(WGM42); // set no clock source
  TCCR4A = _BV(COM4B1) | _BV(COM4C1) | _BV(WGM41);
  // the following registers can be set properly only after WGMn is set
  OCR4B = hsync - 3; // MATCH
  OCR4C = hsync - 5; // ADVANCE MATCH
  TCNT4 = hsync - 7; // START
  ICR4 = hsync - 1; // TOP
  interrupts();
  TCCR4B |= _BV(CS40); // CS4[2:0] = 1 (no prescaling)
}

void StopSyncSignal()
{
  // set OC5B = PL4, OC4B = PH4, and OC4C = PH5 to output and set their initial value to SYNC_SIGNAL_DEFAULT (D45, D7, and D8 in Arduino Mega, respectively)
  // Also T5 = PL2 is used to input external clock (D47)

  // initialize the signals to SYNC_SIGNAL_DEFAULT using FOC bits toggle on comapre match, normal mode
  // (cf. ATmega640/V-1280/V-1281/V-2560/V-2561/V [DATASHEET] p.119, 2549Q–AVR–02/2014)

  // Timer 5 (VSYNC)
  TIMSK5 = 0; // disable timer 5 interrupts
  TCCR5B = 0;
  TCCR5A = _BV(COM5B0); // toggle on compare match
#if SYNC_SIGNAL_DEFAULT==LOW
  PORTL &= ~_BV(4);
#else
  PORTL |= _BV(4);
#endif
  DDRL |= _BV(4); // set OC5B to output
  noInterrupts();
#if SYNC_SIGNAL_DEFAULT==LOW
  TCCR5C |= (PINL & _BV(4) ? _BV(FOC5B) : 0); // toggle if HIGH
#else
  TCCR5C |= (PINL & _BV(4) ? 0 : _BV(FOC5B)); // toggle if LOW
#endif
  interrupts();

  // Timer 4 (HSYNC)
  TCCR4B = 0;
  TCCR4A = _BV(COM4B0) | _BV(COM4C0); // toggle on compare match
  DDRH |= _BV(4) | _BV(5); // set OC4B and OC4C to output
  noInterrupts();
#if SYNC_SIGNAL_DEFAULT==LOW
  TCCR4C |= (PINH & _BV(4) ? _BV(FOC4B) : 0) | (PINH & _BV(5) ? _BV(FOC4C) : 0); // toggle if HIGH
#else
  TCCR4C |= (PINH & _BV(4) ? 0 : _BV(FOC4B)) | (PINH & _BV(5) ? 0 : _BV(FOC4C)); // toggle if LOW
#endif
  interrupts();
}

#elif defined(__AVR_ATmega328PB__)

ISR(TIMER4_COMPB_vect) {
  // compare match interrupt service routine (Timer 4 B)
  noInterrupts(); // temporary disable other high priority interrupts
  asm volatile(
    // This part of assembly code is equivalent to
    // TCNT3 -= clock_stretch; // this statement takes AVR microcontroller 10 clock cycles to update TCNT3 I/O location
    //
    "lds     r24, %1"   "\n\t"     // 2 clocks
    "lds     r25, %2"   "\n\t"     // 2 clocks
    "sub     r24, %A0"  "\n\t"     // 1 clock
    "sbc     r25, %B0"  "\n\t"     // 1 clock
    "sts     %2, r25"   "\n\t"     // 2 clocks
    "sts     %1, r24"   "\n\t"     // 2 clocks
    :
    : "r" (clock_stretch), "M" (_SFR_MEM_ADDR(TCNT3L)), "M" (_SFR_MEM_ADDR(TCNT3H))
    : "r24", "r25"
  );
  interrupts(); // enable other interrupts again
}

void StartSyncSignal(int vidmode)
{
  unsigned int hsync, vsync, stretch;
  hsync = (unsigned int)pgm_read_word(&syncTime[vidmode][SYNC_TIME_HSYNC]);
  vsync = (unsigned int)pgm_read_word(&syncTime[vidmode][SYNC_TIME_VSYNC]);
  stretch = (unsigned int)pgm_read_word(&syncTime[vidmode][SYNC_TIME_STRETCH]);
  noInterrupts();

  // Timer 4 (VSYNC)
  // COM4A[1:0] = 2 : clear OC4A on compare match, set OC4A at BOTTOM
  // COM4B[1:0] = 0 : OC4B pin disconnected
  // WGM4[3:0] = 14 : fast PWM mode 14
  TCCR4B = _BV(WGM43) | _BV(WGM42); // set no clock source
  TCCR4A = _BV(WGM41); // disconnect OC4A pin (PORTD & _BV(1) is SYNC_SIGNAL_DEFAULT) and disconnect OC4B pin
  // the following registers can be set properly only after WGMn is set
  OCR4A = vsync - 2; // MATCH
  OCR4B = vsync - 3; // ADVANCE MATCH
  TCNT4 = vsync - 2; // START
  ICR4 = vsync - 1; // TOP
  TCCR4B |= _BV(CS42) | _BV(CS41); // CS4[2:0] = 6 (external clock source on T4. clock on falling edge)

#if SYNC_SIGNAL_DEFAULT==LOW
  TCCR3C |= _BV(FOC3A); TCCR3C |= _BV(FOC3A);
#endif
  for (int i = 0; i < vsync; i++) {
    TCCR3C |= _BV(FOC3A); TCCR3C |= _BV(FOC3A);
  }
  TCCR4A |= _BV(COM4A1); // connect OC4A pin (the internal OC4A register is SYNC_SIGNAL_DEFAULT)
  
  if (stretch != 0) {
    // number of ticks the last HSYNC before VSYNC longer than others
    clock_stretch = stretch - 9; // updating TCNT3 requires 9 clock cycles (562.5ns)
    TIFR4 = _BV(OCF4B);   // clear output compare B match flag
    TIMSK4 = _BV(OCIE4B); // output compare B match interrupt enable
  }

  // Timer 3 (HSYNC)
  // COM3B[1:0] = 2 : clear OC3B on compare match, set OC3B at BOTTOM
  // COM3A[1:0] = 2 : clear OC3A on compare match, set OC3A at BOTTOM
  // WGM3[3:0] = 14 : fast PWM mode 14
  TCCR3B = _BV(WGM33) | _BV(WGM32); // set no clock source
  TCCR3A = _BV(COM3B1) | _BV(COM3A1) | _BV(WGM31);
  // the following registers can be set properly only after WGMn is set
  OCR3B = hsync - 3; // MATCH
  OCR3A = hsync - 5; // ADVANCE MATCH
  TCNT3 = hsync - 7; // START
  ICR3 = hsync - 1; // TOP
  interrupts();
  TCCR3B |= _BV(CS30); // CS3[2:0] = 1 (no prescaling)
}

void StopSyncSignal()
{
  // set OC4A = PD1, OC3B/OC4B = PD2, and OC3A = PD0 to output and set their initial value to SYNC_SIGNAL_DEFAULT (D1, D2, and D0 in the Arduino terminology, respectively)
  // Also T4 = PE1 is used to input external clock (D23)

  // initialize the signals to SYNC_SIGNAL_DEFAULT using FOC bits toggle on comapre match, normal mode

  // Timer 4 (VSYNC)
  TIMSK4 = 0; // disable timer 4 interrupts
  TCCR4B = 0;
  TCCR4A = _BV(COM4A0); // toggle on compare match
#if SYNC_SIGNAL_DEFAULT==LOW
  PORTD &= ~_BV(1);
#else
  PORTD |= _BV(1);
#endif
  DDRD |= _BV(1); // set OC4A to output
  noInterrupts();
#if SYNC_SIGNAL_DEFAULT==LOW
  TCCR4C |= (PIND & _BV(1) ? _BV(FOC4A) : 0); // toggle if HIGH
#else
  TCCR4C |= (PIND & _BV(1) ? 0 : _BV(FOC4A)); // toggle if LOW
#endif
  interrupts();

  // Timer 3 (HSYNC)
  TCCR3B = 0;
  TCCR3A = _BV(COM3B0) | _BV(COM3A0); // toggle on compare match
  PORTD |= _BV(2);         // set OC3B/OC4B modulator to OR. This operation is mandatory even when OC4B output is disabled
  DDRD |= _BV(2) | _BV(0); // set OC3B and OC3A to output
  noInterrupts();
#if SYNC_SIGNAL_DEFAULT==LOW
  TCCR3C |= (PIND & _BV(2) ? _BV(FOC3B) : 0) | (PIND & _BV(0) ? _BV(FOC3A) : 0); // toggle if HIGH
#else
  TCCR3C |= (PIND & _BV(2) ? 0 : _BV(FOC3B)) | (PIND & _BV(0) ? 0 : _BV(FOC3A)); // toggle if LOW
#endif
  interrupts();
}

#else
#error CPU not supported
#endif
