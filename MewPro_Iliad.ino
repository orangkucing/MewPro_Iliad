#include "Iliad.h"

void setup()
{
  SERIAL.begin(57600);    // baud rate ignored for USB virtual serial
  ROM_Read();


  // setup LCD
  initLCD();

  // setup IR remote
  initIRremote();

  // momentary switches
  initSwitch();

  // RTC
  initRTC();
  
  StopSyncSignal();       // initialize timer
#if defined(__AVR_ATmega2560__)
  BROADCAST.begin(57600); // 57600 is the fastest communication rate for AVR8 8MHz 3.3V on MewPro boards
  BROADCAST_UART_RECEIVER_DISABLE;
#endif

  digitalWrite(SECONDARY_RESET, LOW);
  pinMode(SECONDARY_RESET, OUTPUT);
  delay(100);
  pinMode(SECONDARY_RESET, INPUT_PULLUP);
  digitalWrite(TRIG, LOW); // unused. fix LOW to reduce noise
  pinMode(TRIG, OUTPUT);
}

void loop()
{
  // start up sessions
  if (startupSession != STARTUP_HALT) {
    if (startup[startupSession] != NULL) {
      if ((startup[startupSession])()) { // call the function
        startupSession++; // one function completed
      }
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

