#include <Arduino.h>
#include <avr/wdt.h>
#include <EEPROM.h>
#include "Pins.h"
#include "Videomode.h"
// define camera to use with Iliad. if you mix B and S then video modes are restricted to those both can do.
#define HERO_4_BLACK
#undef  HERO_4_SILVER
#include "MenuText.h"

#define __VERSION_STRING__ "v1.2.18"

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

#include <Wire.h>
// using RTClib at
//     https://learn.adafruit.com/adafruit-ds3231-precision-rtc-breakout/wiring-and-test
#include "RTClib.h"
RTC_DS3231 rtc;

// Input from PC or master camera
#define SERIAL Serial

#define MEWPRO_BUFFER_LENGTH 256

byte command_buf[MEWPRO_BUFFER_LENGTH];
int fifo_readindex = 0;
int fifo_writeindex = 0;
#define FIFO(i) (command_buf[(fifo_writeindex + (i)) % MEWPRO_BUFFER_LENGTH])
#define FIFO_INC(n) do { fifo_writeindex = (fifo_writeindex + (n)) % MEWPRO_BUFFER_LENGTH; } while (0)
#define WRITE_CHAR(c) do { BROADCAST.write(c); SERIAL.print(c); } while (0)

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

// menu
#define MENU_START   0
#define MENU_MAIN    1
#define MENU_SUB     2
#define MENU_EXIT    3
#define MENU_SETTING 4
// recording_state
#define STATE_IDLE      0
#define STATE_START     1
#define STATE_SYNC_ON   2
#define STATE_RECORDING 3
#define STATE_STOP      4
#define STATE_END       5
#define STATE_SYNC_OFF  6
#define STATE_RESTART   7
#define STATE_PAUSE     8
char setup_id = 0;
char disp_state = MENU_START;
volatile char recording_state = STATE_IDLE;
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
  startup5,
  NULL
};

