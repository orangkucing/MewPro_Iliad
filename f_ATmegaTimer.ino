/*
 * GoPro Genlock signal Generator
 *    for Hero 4 Black and Hero 3+ Black
 *    using ATmega2560 16MHz (Arduino Mega 2560 or Seeeduino Mega) 
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
 */
volatile uint16_t clock_stretch;

#define SYNC_SIGNAL_DEFAULT HIGH

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

// For Time Lapse and Night Lapse (Hero 4)
// generating periodic shutter by using Timer3 Compare Match C interrupt

volatile int lapse;
int rate;

// interrupt interval 0.5 second
#define TIMER3_COUNTS (8000000UL / 1024UL) // 16MHz. prescaler divisor 1024

ISR(TIMER3_COMPC_vect) {
  noInterrupts();
  if (++lapse == rate && recording_state == STATE_PAUSE) {
    recording_state = STATE_RESTART;
    lapse = 0;
  }
  interrupts();
}

void StartTimerInterrupt(int r)
{
  rate = r;
  noInterrupts();
  GTCCR = _BV(TSM) | _BV(PSRSYNC); // stop counter. reset prescaler.

  // Timer 3
  // COM3C[1:0] = 0 : OC3C pin disconnected
  // WGM3[3:0] = 12 : Clear Timer on Compare Match (CTC) Mode 12
  TCCR3B = _BV(WGM33) | _BV(WGM32); // set no clock source
  TCCR3A = 0;
  // the following registers can be set properly only after WGMn is set
  ICR3 = TIMER3_COUNTS - 1;       // TOP (0.5s)
  TCNT3 = 0;
  TIFR3 = _BV(OCF3C);   // clear output compare C match flag
  TIMSK3 = _BV(OCIE3C); // output compare C match interrupt enable
  lapse = 0;
  interrupts();
  TCCR3B |= _BV(CS32) | _BV(CS30); // CS3[2:0] = 5 (internal clock source. prescaler divisor 1024)

  GTCCR = 0; // start counting
}

void StopTimerInterrupt()
{
  // stop Timer 3
  TIMSK3 = 0;
  TCCR3B = 0;
  TCCR3A = 0;
}
