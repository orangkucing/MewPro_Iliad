#include <Arduino.h>
#include <avr/wdt.h>
#include "Pins.h"
#include "Videomode.h"
#include "MenuText.h"
#include <EEPROM.h>

#define __VERSION_STRING__ "v1.1.1"

#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
// lcd(RS, Enable, Data4, Data5, Data6, Data7)
LiquidCrystal lcd(LCD_RS, LCD_ENABLE, LCD_DATA4, LCD_DATA5, LCD_DATA6, LCD_DATA7);
#define LCD_SIZE_X 16
#define LCD_SIZE_Y 2

// using IRremote library at
//     https://github.com/z3t0/Arduino-IRremote
// WARNING: The IRremote library conflicts with RobotIRremote library in the standard Arduino IDE.
// So please delete your_IDE_folder/Contents/Java/libraries/RobotIRremote 
#include <IRremote.h>
IRrecv irrecv(IR_RECEIVE);

// Serial commands are broadcasted through the following port
#define BROADCAST Serial2
#define BROADCAST_UART_RECEIVER_DISABLE do { \
  UCSR2B &= (~_BV(RXEN2)); \
} while (0)

// Input from PC
#define SERIAL Serial

#include <Wire.h>
// using RTClib at
//     https://learn.adafruit.com/adafruit-ds3231-precision-rtc-breakout/wiring-and-test
#include "RTClib.h"
RTC_DS3231 rtc;

#define MEWPRO_BUFFER_LENGTH 256

byte command_buf[MEWPRO_BUFFER_LENGTH];
int fifo_readindex = 0;
int fifo_writeindex = 0;
#define FIFO(i) (command_buf[(fifo_writeindex + (i)) % MEWPRO_BUFFER_LENGTH])
#define FIFO_INC(n) do { fifo_writeindex = (fifo_writeindex + (n)) % MEWPRO_BUFFER_LENGTH; } while (0)

byte buf[MEWPRO_BUFFER_LENGTH];
int bufp = 6;
unsigned char session = 0xFF;


int protocol = 1;
int state = 0;

// IR remote
union {
  unsigned long l[4];
  struct {
    unsigned long MENU;
    unsigned long OK;
    unsigned long DOWN;
    unsigned long POWER;
  } p;
} IRkey;
decode_results IR_results;

// menu
#define MENU_START   0
#define MENU_MAIN    1
#define MENU_SUB     2
#define MENU_EXIT    3
#define MENU_SETTING 4
char setup_id = 0;
char disp_state = MENU_START;
char recording_state = 0;
unsigned long start_time;
unsigned int record_time;

// startup
#define STARTUP_HALT (-1)
char startupSession = STARTUP_HALT;
// function prototype declaration required here
// because current Arduino IDE can't automatically do this
void startup_delay0(void);
void startup_delay(void);
void startup0(void);
void startup1(void);
void startup2(void);
void startup3(void);
void startup4(void);
void startup5(void);

void (*startup[])(void) = {
  startup_delay0,
  startup0, startup_delay,
  startup1, startup_delay, 
  startup2, startup_delay, 
  startup3, startup_delay,
  startup4, startup_delay,
  startup5, NULL
};

