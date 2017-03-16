#ifdef USE_LCD

// Iliad Setup Menu
// 
#define ILIAD_SETTING_DATETIME  0
#define ILIAD_SETTING_RESET     1
#define ILIAD_SETTING_MOUNT     2
#define ILIAD_SETTING_IR_LEARN  3
#define ILIAD_SETTING_DONE      4

struct {
  char input_position;
  char menu_level;
  char menu;
} iliad_setting_state;

struct {
  int year;    // 2015 - 2034
  char month;  // 1 - 12
  char day;    // 1 - 31
  char hour;   // 0 - 23
  char minute; // 0 - 59
} tm;

struct Iliad_cursor_position {
  int x;
  int y;
} Iliad_cursor_position;

const struct Iliad_cursor_position cursor_positions_datetime[] = {
  {2, 0}, {5, 0}, {8, 0}, {11, 0}, {14, 0}, {12, 1}
};

const struct Iliad_cursor_position cursor_positions_reset[] = {
  {10, 1}, {0, 1}
};

const struct Iliad_cursor_position cursor_positions_mount[] = {
  {12, 1}, {0, 1}
};

const char iliad_beams_txt_0[] PROGMEM = "SETUP";
const char iliad_beams_txt_1[] PROGMEM = "SHUTTER";
const char iliad_beams_txt_2[] PROGMEM = "MODE";
const char iliad_beams_txt_3[] PROGMEM = "POWER";
const char* const iliad_beams_txt[] PROGMEM = {
  iliad_beams_txt_0, iliad_beams_txt_1, iliad_beams_txt_2, iliad_beams_txt_3,
};

void Iliad_Setting_Begin() {
#ifdef USE_RTC
  {
    DateTime datetime = rtc.now();
    tm.year = datetime.year(); tm.month = datetime.month(); tm.day = datetime.day();
    tm.hour = datetime.hour(); tm.minute = datetime.minute();
  }
#else
  {
    time_t t = now();
    tm.year = year(t) + 1970; tm.month = month(t); tm.day = day(t);
    tm.hour = hour(t); tm.minute = minute(t);
  }
#endif /* USE_RTC */
  iliad_setting_state.menu = iliad_setting_state.menu_level = 0;
}

void Iliad_Setting_End() {
#ifdef USE_RTC
  rtc.adjust(DateTime(tm.year, tm.month, tm.day, tm.hour, tm.minute, 0));
#else
  {
    timeElements tE;
    tE.Year = tm.year - 1970; tE.Month = tm.month; tE.Day = tm.day;
    tE.Hour = tm.hour; tE.Minute = tm.minute; tm.Second = 0;
    setTime(makeTime(tE));
  }
#endif
  pinMode(SECONDARY_RESET, INPUT_PULLUP);
  disp_state = MENU_START;
}

void Iliad_Setting_Shutter() {
  switch (iliad_setting_state.menu_level) {
    case 0: // we are in Date Time/RESET/IR remore learn/DONE menu level
      switch (iliad_setting_state.menu) {
        case ILIAD_SETTING_DATETIME:
        case ILIAD_SETTING_RESET:
        case ILIAD_SETTING_MOUNT:
        case ILIAD_SETTING_IR_LEARN:
          // go down one menu level deeper
          iliad_setting_state.menu_level++;
          iliad_setting_state.input_position = 0;
          break;
        case ILIAD_SETTING_DONE:
          Iliad_Setting_End();
          break;
      }
      break;
    case 1:
      switch (iliad_setting_state.menu) {
        case ILIAD_SETTING_DATETIME:
          switch (iliad_setting_state.input_position) {
            case 0: // year
              if (++tm.year > 2034) {
                tm.year = 2015;
              }
              break;
            case 1: // month
              if (++tm.month > 12) {
                tm.month = 1;
              }
              if (tm.month == 2 && tm.year % 4 != 0 && tm.day == 29) {
                tm.day = 28;
              }
              break;
            case 2: // day
              if ((int)(tm.month * 9 / 8) % 2 == 1) {
                  if (++tm.day > 31) {
                    tm.day = 1;
                  }
              } else {
                if (tm.month == 2) {
                  ++tm.day;
                  if (tm.year % 4 != 0 && tm.day > 28) {
                    tm.day = 1;
                  }
                  if (tm.year % 4 == 0 && tm.day > 29) {
                    tm.day = 1;
                  }
                } else {
                  if (++tm.day > 30) {
                    tm.day = 1;
                  }
                }
              }
              break;
            case 3: // hour
              (++tm.hour) %= 24;
              break;
            case 4: // minute
              (++tm.minute) %= 60;
              break;
            case 5: // DONE
              iliad_setting_state.menu++;
              iliad_setting_state.menu_level = 0;
              break;
          }
          break;
        case ILIAD_SETTING_RESET:
          switch (iliad_setting_state.input_position) {
            case 0: // cancel
              iliad_setting_state.menu++;
              iliad_setting_state.menu_level = 0;
              break;
            case 1: // factory reset
              lcd.clear();
              lcd.noBlink();
              lcd.print(F("Resetting..."));
              EEPROM.write(0, 0);
              wdt_enable(WDTO_15MS);
              while (1) ;
              // never reach here
              break;
          }
          break;
        case ILIAD_SETTING_MOUNT:
          switch (iliad_setting_state.input_position) {
            case 0: // cancel
              iliad_setting_state.menu++;
              iliad_setting_state.menu_level = 0;
              break;
            case 1: // mount
              if (digitalRead(SECONDARY_RESET) == LOW) {
                pinMode(SECONDARY_RESET, INPUT_PULLUP);
              } else {
                digitalWrite(SECONDARY_RESET, LOW);
                pinMode(SECONDARY_RESET, OUTPUT);
              }
              break;
          }
          break;
        case ILIAD_SETTING_IR_LEARN: // cancel
          iliad_setting_state.menu++;
          iliad_setting_state.menu_level = 0;
          learning = false;
          break;
      }
  }
}

void Iliad_Setting_Mode() {
  switch (iliad_setting_state.menu_level) {
    case 0: // we are in Date/Time/RESET/IR remore learn/DONE menu level
      (++iliad_setting_state.menu) %= ILIAD_SETTING_DONE + 1;
      break;
    case 1:
      switch (iliad_setting_state.menu) {
        case ILIAD_SETTING_DATETIME:
          (++iliad_setting_state.input_position) %= sizeof(cursor_positions_datetime) / sizeof(Iliad_cursor_position);
          break;
        case ILIAD_SETTING_RESET:
          (++iliad_setting_state.input_position) %= sizeof(cursor_positions_reset) / sizeof(Iliad_cursor_position);
          break;
        case ILIAD_SETTING_MOUNT:
          (++iliad_setting_state.input_position) %= sizeof(cursor_positions_mount) / sizeof(Iliad_cursor_position);
          break;
        case ILIAD_SETTING_IR_LEARN: // cancel
          iliad_setting_state.menu++;
          iliad_setting_state.menu_level = 0;
          learning = false;
          break;
      }
      break;
  }
}

void Iliad_Setting_Learn(unsigned long code)
{
  if (code != 0xFFFFFFFF) { /* not repeat code */
    IRkey.l[iliad_setting_state.input_position++] = code;
    if (iliad_setting_state.input_position == sizeof(iliad_beams_txt) / sizeof(char *)) {
      // write to EEPROM
      byte *addr = (byte *)IRkey.l;
      for (int i = 0; i < sizeof(IRkey); i++) {
        EEPROM.write(i + EEPROM_ID_LEN, *(addr + i));
      }
      // DONE
      iliad_setting_state.menu++;
      iliad_setting_state.menu_level = 0;
      learning = false;
    }
  }
}

void __printDateTime()
{
  char tmp[5];
  sprintf(tmp, "%04d", tm.year); lcd.print(tmp); lcd.print('-');
  sprintf(tmp, "%02d", tm.month); lcd.print(tmp); lcd.print('-');
  sprintf(tmp, "%02d", tm.day); lcd.print(tmp); lcd.print(' ');
  sprintf(tmp, "%02d", tm.hour); lcd.print(tmp); lcd.print(':');
  sprintf(tmp, "%02d", tm.minute); lcd.print(tmp);
}

void Iliad_updateLCD() {
  char *addr, c;
  char tmp[LCD_SIZE_X + 1];
  lcd.clear();
  lcd.noBlink();
  switch (iliad_setting_state.menu_level) {
    case 0: // we are in Date/Time/RESET/IR remore learn/DONE menu level
      switch (iliad_setting_state.menu) {
        case ILIAD_SETTING_DATETIME:
          lcd.print(F("Date Time"));
          lcd.setCursor(0, 1);
          __printDateTime();
          break;
        case ILIAD_SETTING_RESET:
          lcd.print(F("RESET"));
          break;
        case ILIAD_SETTING_MOUNT:
          lcd.print(F("Mount microSD"));
          break;
        case ILIAD_SETTING_IR_LEARN:
          lcd.print(F("Learn IR code"));
          break;
        case ILIAD_SETTING_DONE:
          lcd.print(F("DONE"));
          break;
      }
      break;
    case 1:
      switch (iliad_setting_state.menu) {
        case ILIAD_SETTING_DATETIME:
          __printDateTime();
          lcd.setCursor(12, 1);
          lcd.print(F("BACK"));
          lcd.setCursor(cursor_positions_datetime[iliad_setting_state.input_position].x, cursor_positions_datetime[iliad_setting_state.input_position].y);
          lcd.blink();
          break;
        case ILIAD_SETTING_RESET:
          lcd.print(F("Reset Iliad?"));
          lcd.setCursor(0, 1);
          lcd.print(F("Reset     Cancel"));
          lcd.setCursor(cursor_positions_reset[iliad_setting_state.input_position].x, cursor_positions_reset[iliad_setting_state.input_position].y);
          lcd.blink();
          break;
        case ILIAD_SETTING_MOUNT:
          lcd.print(F("Mount microSD?"));
          lcd.setCursor(0, 1);
          c = digitalRead(SECONDARY_RESET);
          if (c) {
            lcd.print(F("Mount       BACK"));
          } else {
            lcd.print(F("Unmount     BACK"));
          }
          lcd.setCursor(cursor_positions_mount[iliad_setting_state.input_position].x, cursor_positions_mount[iliad_setting_state.input_position].y);
          lcd.blink();
          break;
        case ILIAD_SETTING_IR_LEARN:
          lcd.print(F("Learn ["));
          addr = (char *)pgm_read_word(&iliad_beams_txt[iliad_setting_state.input_position]);
          strcpy_P(tmp, addr);
          lcd.print(tmp);
          lcd.print(F("]"));
          lcd.setCursor(10, 1);
          lcd.print(F("Cancel"));
          lcd.setCursor(10, 1);
          lcd.blink();
          learning = true;
          break;
      }
      break;
  }
}

#else

void Iliad_Setting_Begin() {
}

void Iliad_Setting_End() {
}

void Iliad_Setting_Shutter() {
}

void Iliad_Setting_Mode() {
}

void Iliad_Setting_Learn(unsigned long code)
{
}

void Iliad_updateLCD() {
}

#endif
