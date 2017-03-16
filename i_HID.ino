// Human interface devices (input)

const char KEY_MENU  = _BV(0);
const char KEY_OK    = _BV(1);
const char KEY_DOWN  = _BV(2);
const char KEY_POWER = _BV(3);

#ifdef USE_SWITCH
// Momentary switch I/F
//    debounce
//    long press

void initSwitch()
{
  pinMode(SETUP_SWITCH, INPUT_PULLUP);
  pinMode(SHUTTER_SWITCH, INPUT_PULLUP);
  pinMode(MODE_SWITCH, INPUT_PULLUP);
}

boolean __checkLongPress(char reading, boolean *ignorenext)
{
  static unsigned long lastDebounceTime;
  static char lastButtonState = 0;
  static char buttonState = 0;

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if (millis() - lastDebounceTime > 1500) {
    if (reading != buttonState) {
      if (reading != 0) { // switch closed
        navigateMenu(KEY_POWER);
        *ignorenext = true; // ignore the next switch open
      }
      buttonState = reading;
    }
  } else if (reading == 0) { // switch opened
    buttonState = reading;
  }
  lastButtonState = reading;
}

void checkSwitchCommands()
{
  static unsigned long lastDebounceTime;
  static char lastButtonState = -1;
  static char buttonState = -1;
  static boolean ignorenext = true;

  // read switch with debounce
  char reading = (digitalRead(SETUP_SWITCH) ? 0 : KEY_MENU) | (digitalRead(SHUTTER_SWITCH) ? 0 : KEY_OK) | (digitalRead(MODE_SWITCH) ? 0 : KEY_DOWN);
  if (recording_state != STATE_IDLE) {
    reading &= KEY_OK;
  }
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if (millis() - lastDebounceTime > 3) {
    if (reading != buttonState) {
      if (reading == 0) { // switch opened
        if (!ignorenext) {
          navigateMenu(buttonState);
        }
        ignorenext = false;
      }
      buttonState = reading;
    }
  }
  lastButtonState = reading;
  __checkLongPress(buttonState & KEY_DOWN, &ignorenext); // check long press only on MODE_SWITCH
}

#else

void initSwitch()
{
}

void checkSwitchCommands()
{
}

#endif /* USE_SWITCH */

#ifdef USE_IR_REMOTE
// IR remote I/F

boolean learning = false; // disable navigation while learning IR code

void initIRremote()
{
  irrecv.enableIRIn();
}

void checkIRremoteCommands()
{
  decode_results IR_results;
  if (irrecv.decode(&IR_results)) {
    if (learning) { // learning IR code
      Iliad_Setting_Learn(IR_results.value);
      updateLCD();
    } else {
      if (IR_results.value == IRkey.p.OK || recording_state == STATE_IDLE) {
        for (int i = 0; i < sizeof(IRkey) / sizeof(unsigned long); i++) {
          if (IR_results.value == IRkey.l[i]) {
            navigateMenu(_BV(i));
            break;
          }
        }
      }
    }
    irrecv.resume(); // Receive the next value
  }
}

#else

void initIRremote()
{
}

void checkIRremoteCommands()
{
}

#endif /* USE_IR_REMOTE */

//
// The following is the state machine that interacts with HID device
//
void navigateMenu(char key)
{
  switch (disp_state) {
    case MENU_START: // camera off
      switch (key) {
        case KEY_POWER:
          Broadcast_PowerOn();
          break;
        case KEY_MENU:
          disp_state = MENU_SETTING;
          Iliad_Setting_Begin();
          break;
        default:
          return;
      }
      break;
    case MENU_MAIN: // main mode
      switch (key) {
        case KEY_POWER:
          Broadcast_PowerOff();
          break;
        case KEY_MENU:
          disp_state = MENU_SUB;
          break;
        case KEY_DOWN:
          Broadcast_ChangeMode();
          break;
        case KEY_OK:
          switch (setting.p.mode) {
            case MODE_SETUP:
              disp_state = MENU_SUB;            // goto setup menu
              break;
            case MODE_VIDEO:
              switch (recording_state) {
                case STATE_IDLE:
                  Broadcast_StartRecording();
                  break;
                case STATE_RECORDING:
                  Broadcast_StopRecording();
                  break;
              }
              break;
            case MODE_PHOTO:
              if (setting.p.current_submode[MODE_PHOTO] == 1 /* continuous */ && recording_state == STATE_RECORDING) {
                Broadcast_StopRecording();
              } else if (recording_state == STATE_IDLE) {
                Broadcast_StartRecording();
              }
              break;
            case MODE_MULTI_SHOT:
              switch (recording_state) {
                case STATE_IDLE:
                  Broadcast_StartRecording();
                  break;
                case STATE_RECORDING:
                  Broadcast_StopRecording();
                  break;
              }
              break;
          }
          break;
        default:
          return;
      }
      initWidget();
      break;
    case MENU_SUB: // sub mode
      switch (key) {
        case KEY_POWER:
          Broadcast_PowerOff();
          break;
        case KEY_MENU:
          disp_state = MENU_MAIN;
          Broadcast_ChangeSettings(setting.p.mode);
          if (setting.p.mode == MODE_SETUP) { // if current mode is Setting then
            Broadcast_ChangeMode();  // goto video mode
          }
          break;
        case KEY_DOWN:
          if (!nextWidget()) {
            disp_state = MENU_EXIT;
          }
          break;
        case KEY_OK:
          setNextValue();
          break;
        default:
          return;
      }
      break;
    case MENU_EXIT: // EXIT menu
      switch (key) {
        case KEY_POWER:
          Broadcast_PowerOff();
          break;
        case KEY_MENU:
        case KEY_OK:
          disp_state = MENU_MAIN;
          Broadcast_ChangeSettings(setting.p.mode);
          if (setting.p.mode == MODE_SETUP) { // if current mode is Setting then
            Broadcast_ChangeMode(); // goto video mode
          }
          break;
        case KEY_DOWN:
          disp_state = MENU_SUB;
          initWidget();
          break;
        default:
          return;
      }
      break;
    case MENU_SETTING: // Iliad setting
      switch (key) {
        case KEY_POWER:
        case KEY_MENU:
          Iliad_Setting_End();
          break;
        case KEY_OK:
          Iliad_Setting_Shutter();
          break;
        case KEY_DOWN:
          Iliad_Setting_Mode();
          break;
        default:
          return;
      }
      break;
  }
  updateLCD();
}
