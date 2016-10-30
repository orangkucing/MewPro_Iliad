#include "Iliad.h"

void setup()
{
  SERIAL.begin(57600);    // baud rate ignored for USB virtual serial
  ROM_Read();
  // setup LCD
  lcd.begin(LCD_SIZE_X, LCD_SIZE_Y);
  updateLCD();

  // setup IR remote
  irrecv.enableIRIn();

  // RTC
  rtc.begin();
  if (rtc.lostPower()) {
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
  
  StopSyncSignal();       // initialize timer
  BROADCAST.begin(57600); // 57600 is the fastest communication rate for AVR8 8MHz 3.3V on MewPro boards
  BROADCAST_UART_RECEIVER_DISABLE;

  digitalWrite(SECONDARY_RESET, LOW);
  pinMode(SECONDARY_RESET, OUTPUT);
  delay(100);
  digitalWrite(SECONDARY_RESET, HIGH);

  // momentary switches
  pinMode(SETUP_SWITCH, INPUT_PULLUP);
  pinMode(SHUTTER_SWITCH, INPUT_PULLUP);
  pinMode(MODE_SWITCH, INPUT_PULLUP);
}

void loop()
{
  // start up sessions
  if (startupSession != STARTUP_HALT) {
    if (startup[startupSession] != NULL) {
      (startup[startupSession++])(); // call the function
    } else {
      startupSession = STARTUP_HALT;
      updateLCD();
    }
  }
  checkTerminalCommands(); // a finite state machine
  checkIRremoteCommands(); // CUI: IR remote
  checkSwitchCommands();   // CUI: momentary switch
  checkGenlockState();     // start/stop genlock signals
}

