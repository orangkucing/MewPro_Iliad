#if defined(__AVR_ATmega2560__)
// Arduino Mega Pins
//
//    connect to USB           0; //      PE0 ( RXD0/PCINT8 )
//    connect to USB           1; //      PE1 ( TXD0 )
const int RTC_SQW            = 2; //      PE4 ( OC3B/INT4 )         // reserved
const int IR_RECEIVE         = 3; //      PE5 ( OC3C/INT5 )
//                             4; //      PG5 ( OC0B )
//                             5; //      PE3 ( OC3A/AIN1 )
const int TRIG              =  6; //      PH3 ( OC4A )              // for Hero 3+ Black only
const int HSYNC             =  7; //      PH4 ( OC4B )
const int OC4C_PIN          =  8; //      PH5 ( OC4C ) ----> connect to D47
const int SECONDARY_RESET   =  9; //      PH6 ( OC2B )
const int MODE_SWITCH       = 10; //      PB4 ( OC2A/PCINT4 )
const int SETUP_SWITCH      = 11; //      PB5 ( OC1A/PCINT5 )
const int SHUTTER_SWITCH    = 12; //      PB6 ( OC1B/PCINT6 )
//                            13; //      PB7 ( OC0A/OC1C/PCINT7 )  // on-board LED
//                            14; //      PJ1 ( TXD3/PCINT10 )
//                            15; //      PJ0 ( RXD3/PCINT9 )
//    broadcast to MewPro     16; //      PH1 ( TXD2 )
//                            17; //      PH0 ( RXD2 )
//                            18; //      PD3 ( TXD1/INT3 )
//                            19; //      PD2 ( RXDI/INT2 )
//    connect to RTC          20; //      PD1 ( SDA/INT1 )
//    connect to RTC          21; //      PD0 ( SCL/INT0 )
//                            22; //      PA0 ( AD0 )
//                            23; //      PA1 ( AD1 )
//                            24; //      PA2 ( AD2 )
//                            25; //      PA3 ( AD3 )
//                            26; //      PA4 ( AD4 )
//                            27; //      PA5 ( AD5 )
//                            28; //      PA6 ( AD6 )
//                            29; //      PA7 ( AD7 )
//                            30; //      PC7 ( A15 )
//                            31; //      PC6 ( A14 )
//                            32; //      PC5 ( A13 )
//                            33; //      PC4 ( A12 )
//                            34; //      PC3 ( A11 )
//                            35; //      PC2 ( A10 )
//                            36; //      PC1 ( A9 )
//                            37; //      PC0 ( A8 )
//                            38; //      PD7 ( T0 )
//                            39; //      PG2 ( ALE )
//                            40; //      PG1 ( RD )
//                            41; //      PG0 ( WR )
//                            42; //      PL7
//                            43; //      PL6
//                            44; //      PL5 ( OC5C )
const int VSYNC             = 45; //      PL4 ( OC5B )
//                            46; //      PL3 ( OC5A )
//  connect from D8 ------>   47; //      PL2 ( T5 )
//                            48; //      PL1 ( ICP5 )
//                            49; //      PL0 ( ICP4 )
//                            50; //      PB3 ( MISO/PCINT3 )
//                            51; //      PB2 ( MOSI/PCINT2 )
//                            52; //      PB1 ( SCK/PCINT1 )
//                            53; //      PB0 ( SS/PCINT0 )
const int LCD_RS            = 54; //  A0; PF0 ( ADC0 )
const int LCD_ENABLE        = 55; //  A1; PF1 ( ADC1 )
const int LCD_DATA4         = 56; //  A2; PF2 ( ADC2 )
const int LCD_DATA5         = 57; //  A3; PF3 ( ADC3 )
const int LCD_DATA6         = 58; //  A4; PF4 ( ADC4/TMK )
const int LCD_DATA7         = 59; //  A5; PF5 ( ADC5/TMS )
//                            60; //  A6; PF6 ( ADC6 )
//                            61; //  A7; PF7 ( ADC7 )
//                            62; //  A8; PK0 ( ADC8/PCINT16 )
//                            63; //  A9; PK1 ( ADC9/PCINT17 )
//                            64; // A10; PK2 ( ADC10/PCINT18 )
//                            65; // A11; PK3 ( ADC11/PCINT19 )
//                            66; // A12; PK4 ( ADC12/PCINT20 )
//                            67; // A13; PK5 ( ADC13/PCINT21 )
//                            68; // A14; PK6 ( ADC14/PCINT22 )
//                            69; // A15; PK7 ( ADC15/PCINT23 )
/* Regrettably, the following pins are NOT broken out in Arduino Mega board.
   Didn't Mega's designer aware of importance of Tn pins etc?
   We are very lucky T5 if no Tn pins else is broken out and usable as D47 by accident.
   (Seeeduino Mega has these pins cleverly broken out, but no Arduino pin names used by Arduino IDE.) */
//                            N/C; // PH2 ( XCK2 )
//                            N/C; // PH7 ( T4 )
//                            N/C; // PJ2 ( XCK3/PCINT11 )
//                            N/C; // PJ3 ( PCINT12 )
//                            N/C; // PJ4 ( PCINT13 )
//                            N/C; // PJ5 ( PCINT14 )
//                            N/C; // PJ6 ( PCINT15 )
//                            N/C; // PJ7
//                            N/C; // PD4 ( ICP1 )
//                            N/C; // PD5 ( XCK1 )
//                            N/C; // PD6 ( T1 )
//                            N/C; // PG4 ( TOSC1 )
//                            N/C; // PG3 ( TOSC2 )
//                            N/C; // PE7 ( CLKO/ICP3/INT7 )
//                            N/C; // PE6 ( T3/INT6 )
//                            N/C; // PE2 ( XCK0/AIN0 )

// Input from PC or master camera
#define SERIAL Serial

// Serial commands are broadcasted through the following port
#define BROADCAST Serial2
#define BROADCAST_UART_RECEIVER_DISABLE do { \
  UCSR2B &= (~_BV(RXEN2)); \
} while (0)

#define DEBUG_print(...) SERIAL.print(__VA_ARGS__)
#define DEBUG_println(...) SERIAL.println(__VA_ARGS__)

#define WRITE_CHAR(c) do { BROADCAST.write(c); DEBUG_print(c); } while (0)

#define USE_LCD
#define USE_IR_REMOTE
#define USE_SWITCH
#define USE_RTC

#elif defined(__AVR_ATmega328PB__)

// ATmega328pb Pins
//
const int OC3A_PIN          =  0; //      PD0 ( RXD0/OC3A ) ----> connect to D23
const int VSYNC             =  1; //      PD1 ( TXD0/OC4A )
const int HSYNC             =  2; //      PD2 ( OC3B/OC4B/INT0 )
const int GPIO              =  3; //      PD3 ( OC2B/INT1 )
//                             4; //      PD4 ( XCK0/T0 )
const int TRIG              =  5; //      PD5 ( OC0B/T1 )
//                             6; //      PD6 ( OC0A/AIN0 )
//                             7; //      PD7 ( AIN1 )
//                             8; //      PB0 ( ICP1/CLKO )
//                             9; //      PB1 ( OC1A )
//                            10; //      PB2 ( !SS0/OC1B )
//    broadcast to MewPro     11; //      PB3 ( MOSI0/TXD1/OC2A )
//    connect to serial       12; //      PB4 ( MISO0/RXD1 )
const int SECONDARY_RESET   = 13; //      PB5 ( XCK0/SCK0 )
//                                //      PB6 ( XTAL1/TOSC1 )
//                                //      PB7 ( XTAL2/TOSC2 )
//                            14; //      PC0 ( ADC0/MISO1 )
//                            15; //      PC1 ( ADC1/SCK1 )
//                            16; //      PC2 ( ADC2 )
//                            17; //      PC3 ( ADC3 )
//    connect to RTC          18; //      PC4 ( ADC4/SDA0 )
//    connect to RTC          19; //      PC5 ( ADC5/SCL0 )
//                                //      PC6 ( !RESET )
//                            20; //      PE2 ( ADC6/ICP3/!SS1 )
//                            21; //      PE3 ( ADC7/T3/MOSI1 )
//                            22; //      PE0 ( SDA1/ICP4/ACO )
//    connect from D0         23; //      PE1 ( SCL1/T4 )

// use either one if you like
const int RTC_SQW = GPIO;
const int IR_RECEIVE = GPIO;

// Input from PC or master camera
#define SERIAL Serial1

// Serial commands are broadcasted through the following port
#define BROADCAST Serial1

#define DEBUG_print(...)
#define DEBUG_println(...)
//#define DEBUG_print(...) SERIAL.print(__VA_ARGS__)
//#define DEBUG_println(...) SERIAL.println(__VA_ARGS__)

#define WRITE_CHAR(c) do { BROADCAST.write(c); } while (0)

#undef  USE_LCD
#undef  USE_IR_REMOTE
#undef  USE_SWITCH
#undef  USE_RTC

#else
#error CPU not supported
#endif

