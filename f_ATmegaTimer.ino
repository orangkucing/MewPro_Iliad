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

ISR(TIMER5_COMPC_vect) {
  // compare match interrupt service routine (Timer 5 C)
  noInterrupts(); // temporary disable other high priority interrupts
  TCNT4 -= clock_stretch; // this statement takes AVR microcontroller 13 clock cycles to update TCNT4 io location
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
  TCCR5A = _BV(COM5B1) | _BV(WGM51);
  // the following registers can be set properly only after WGMn is set
  OCR5B = vsync - 2; // MATCH
  OCR5C = vsync - 3; // ADVANCE MATCH
  TCNT5 = vsync - 3; // START
  ICR5 = vsync - 1; // TOP
  TCCR5B |= _BV(CS52) | _BV(CS51); // CS5[2:0] = 6 (external clock source on T5. clock on falling edge)

  // * using an external clock source ATmega2560 has a bug that causes the first match ignored
  // WORKAROUND: toggle T5 to go beyond the first
  for (int i = 0; i < vsync + 1; i++) {
    TCCR4C |= _BV(FOC4C); TCCR4C |= _BV(FOC4C);
  }

  if (stretch != 0) {
    // number of ticks the 2nd last HSYNC before VSYNC longer than others
    clock_stretch = stretch - 13; // updating TCNT4 requires 13 clock cycles (81.25ns)
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
  // set OC5B = PL4, OC4B = PH4, and OC4C = PH5 to output and set their initial value to HIGH (D45, D7, and D8 in Arduino Mega, respectively)
  // Also T5 = PL2 is used to input external clock (D47)

  // initialize the signals to HIGH using FOC bits toggle on comapre match, normal mode
  // (cf. ATmega640/V-1280/V-1281/V-2560/V-2561/V [DATASHEET] p.119, 2549Q–AVR–02/2014)

  // Timer 5 (VSYNC)
  TIMSK5 = 0; // disable timer 5 interrupts
  TCCR5B = 0;
  TCCR5A = _BV(COM5B0); // toggle on compare match
  DDRL |= _BV(4); // set OC5B to output
  noInterrupts();
  if (!(PINL & _BV(4))) { // toggle if LOW
    TCCR5C |= _BV(FOC5B);
  }
  interrupts();

  // Timer 4 (HSYNC)
  TCCR4B = 0;
  TCCR4A = _BV(COM4B0) | _BV(COM4C0); // toggle on compare match
  DDRH |= _BV(4) | _BV(5); // set OC4B and OC4C to output
  noInterrupts();
  if (!(PINH & _BV(4)) || !(PINH & _BV(5))) { // toggle if LOW
    TCCR4C |= (PINH & _BV(4) ? 0 : _BV(FOC4B)) | (PINH & _BV(5) ? 0 : _BV(FOC4C));
  }
  interrupts();
}

