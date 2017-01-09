#define BLINK() do { lcd.setCursor(0, 1); lcd.blink(); } while (0)

void LCDprint_P(int row, char *txt)
{
  char tmp[LCD_SIZE_X + 1];
  int i = 0;
  char c;
  if (txt != NULL) {
    txt++;
    while ((c = (char)pgm_read_byte(txt++)) != 0) {
      tmp[i++] = c;
    }
  }
  for (; i < LCD_SIZE_X; i++) {
    tmp[i] = ' ';
  }
  tmp[i] = 0;
  lcd.setCursor(0, row);
  lcd.print(tmp);
}

void updateLCD()
{
  const char * const *addr;
  lcd.noBlink();
  switch (disp_state) {
    case MENU_START:
      lcd.clear();
      lcd.print(F("MewPro Iliad"));
      lcd.setCursor(0, 1);
      lcd.print(F(__VERSION_STRING__));
      break;
    case MENU_MAIN: // show main
      lcd.clear();
      if (startupSession == STARTUP_HALT) {
        switch (setting.p.mode) {
          case MODE_VIDEO: // video
            lcd.print(F("Video "));
            switch (setting.p.current_submode[MODE_VIDEO]) {
              case 0: break;
              case 1: lcd.print(F("Timelapse")); break;
              case 2: lcd.print(F("+ Photo")); break;
              case 3: lcd.print(F("Looping")); break;
            }
            lcd.setCursor(0, 1);
            switch (recording_state) {
              case STATE_START:
              case STATE_SYNC_ON:
              case STATE_RECORDING:
                lcd.print(F("Recording..."));
                break;
              default:
                switch (setting.p.video.resolution) {
                  case 1: lcd.print(F("4K")); break;
                  case 2: lcd.print(F("4K S")); break;
                  case 4: lcd.print(F("2.7K")); break;
                  case 5: lcd.print(F("2.7K S")); break;
                  case 6: lcd.print(F("2.7K4:3")); break;
                  case 7: lcd.print(F("1440")); break;
                  case 8: lcd.print(F("1080 S")); break;
                  case 9: lcd.print(F("1080")); break;
                  case 10: lcd.print(F("960")); break;
                  case 11: lcd.print(F("720 S")); break;
                  case 12: lcd.print(F("720")); break;
                  case 13: lcd.print(F("WVGA")); break;
                }
                lcd.setCursor(8, 1);
                switch (setting.p.video.fov) {
                  case 0: lcd.print('W'); break;
                  case 1: lcd.print('M'); break;
                  case 2: lcd.print('N'); break;
                }
                lcd.setCursor(10, 1);
                switch (setting.p.current_submode[MODE_VIDEO]) {
                  case 0:
                    switch (setting.p.video.fps) {
                      case 0: lcd.print(F("240fps")); break;
                      case 1: lcd.print(F("120fps")); break;
                      case 2: lcd.print(F("100fps")); break;
                      case 3: lcd.print(F("90fps")); break;
                      case 4: lcd.print(F("80fps")); break;
                      case 5: lcd.print(F("60fps")); break;
                      case 6: lcd.print(F("50fps")); break;
                      case 7: lcd.print(F("48fps")); break;
                      case 8: lcd.print(F("30fps")); break;
                      case 9: lcd.print(F("25fps")); break;
                      case 10: lcd.print(F("24fps")); break;
                      case 11: lcd.print(F("15fps")); break;
                      case 12: lcd.print(F("12.5")); break;
                    }
                    break;
                  case 1:
                    switch (setting.p.video.timelapse_rate) {
                      case 0: lcd.print(F("0.5s")); break;
                      case 1: lcd.print(F("1s")); break;
                      case 2: lcd.print(F("2s")); break;
                      case 3: lcd.print(F("5s")); break;
                      case 4: lcd.print(F("10s")); break;
                      case 5: lcd.print(F("30s")); break;
                      case 6: lcd.print(F("60s")); break;
                    }
                    break;
                  case 2:
                    switch (setting.p.video.piv) {
                      case 1: lcd.print(F("5s")); break;
                      case 2: lcd.print(F("10s")); break;
                      case 3: lcd.print(F("30s")); break;
                      case 4: lcd.print(F("60s")); break;
                    }
                    break;
                  case 3:
                    switch (setting.p.video.looping) {
                      case 0: lcd.print(F("Max")); break;
                      case 1: lcd.print(F("5m")); break;
                      case 2: lcd.print(F("20m")); break;
                      case 3: lcd.print(F("60m")); break;
                      case 4: lcd.print(F("120m")); break;
                    }
                    break;
                }
                break;             
            }
            break;
          case MODE_PHOTO:
            lcd.print(F("Photo "));
            switch (setting.p.current_submode[MODE_PHOTO]) {
              case 0: lcd.print(F("Single")); break;
              case 1: lcd.print(F("Continuous"));
                lcd.setCursor(10, 1);
                switch (setting.p.photo.continuous_rate) {
                  case 0: lcd.print(F("3 fps")); break;
                  case 1: lcd.print(F("5 fps")); break;
                  case 2: lcd.print(F("10 fps")); break;
                }
                break;
              case 2: lcd.print(F("Night"));
                lcd.setCursor(10, 1);
                switch (setting.p.photo.exposure_time) {
                  case 0: lcd.print(F("Auto")); break;
                  case 1: lcd.print(F("2 Sec")); break;
                  case 2: lcd.print(F("5 Sec")); break;
                  case 3: lcd.print(F("10 Sec")); break;
                  case 4: lcd.print(F("15 Sec")); break;
                  case 5: lcd.print(F("20 Sec")); break;
                  case 6: lcd.print(F("30 Sec")); break;
                }
                break;
            }
            lcd.setCursor(0, 1);
            switch (setting.p.photo.resolution) {
              case 0: lcd.print(F("12MP W")); break;
              case 1: lcd.print(F("7MP W")); break;
              case 2: lcd.print(F("7MP M")); break;
              case 3: lcd.print(F("5MP M")); break;
            }
            break;
          case MODE_MULTI_SHOT:
            lcd.print(F("Multi-Shot "));
            switch (setting.p.current_submode[MODE_MULTI_SHOT]) {
              case 0: lcd.print(F("Burst"));
                lcd.setCursor(11, 1);
                switch (setting.p.multi_shot.burst_rate) {
                  case 0: lcd.print(F("3/1s")); break;
                  case 1: lcd.print(F("5/1s")); break;
                  case 2: lcd.print(F("10/1s")); break;
                  case 3: lcd.print(F("10/2s")); break;
                  case 4: lcd.print(F("10/3s")); break;
                  case 5: lcd.print(F("30/1s")); break;
                  case 6: lcd.print(F("30/2s")); break;
                  case 7: lcd.print(F("30/3s")); break;
                  case 8: lcd.print(F("30/6s")); break;
                }
                break;
              case 1: lcd.print(F("T.L."));
                lcd.setCursor(11, 1);
                switch (setting.p.multi_shot.timelapse_rate) {
                  case 0: lcd.print(F("0.5s")); break;
                  case 1: lcd.print(F("1s")); break;
                  case 2: lcd.print(F("2s")); break;
                  case 5: lcd.print(F("5s")); break;
                  case 10:lcd.print(F("10s")); break;
                  case 30:lcd.print(F("30s")); break;
                  case 60:lcd.print(F("60s")); break;
                }
                break;
              case 2: lcd.print(F("N.L."));
                lcd.setCursor(7, 1);
                switch (setting.p.multi_shot.exposure_time) {
                  case 0: lcd.print(F("A")); break;
                  case 1: lcd.print(F("2s")); break;
                  case 2: lcd.print(F("5s")); break;
                  case 3: lcd.print(F("10s")); break;
                  case 4: lcd.print(F("15s")); break;
                  case 5: lcd.print(F("20s")); break;
                  case 6: lcd.print(F("30s")); break;
                }
                lcd.setCursor(11, 1);
                switch(setting.p.multi_shot.nightlapse_rate) {
                  case 9: lcd.print(F("Cont.")); break;
                  case 10:lcd.print(F("4s")); break;
                  case 11:lcd.print(F("5s")); break;
                  case 0: lcd.print(F("10s")); break;
                  case 1: lcd.print(F("15s")); break;
                  case 2: lcd.print(F("20s")); break;
                  case 3: lcd.print(F("30s")); break;
                  case 4: lcd.print(F("1min")); break;
                  case 5: lcd.print(F("2min")); break;
                  case 6: lcd.print(F("5min")); break;
                  case 7: lcd.print(F("30min")); break;
                  case 8: lcd.print(F("60min")); break;                 
                }
                break;
            }
            lcd.setCursor(0, 1);
            switch (setting.p.multi_shot.resolution) {
              case 0: lcd.print(F("12MP W")); break;
              case 1: lcd.print(F("7MP W")); break;
              case 2: lcd.print(F("7MP M")); break;
              case 3: lcd.print(F("5MP M")); break;
            }
            break;
          case MODE_SETUP:
            lcd.print(F("Setup"));
            break;
        }
      } else {
        lcd.print(F("Camera power on."));
        lcd.setCursor(0, 1);
        lcd.print(F("Sync settings..."));
      }
      break;
    case MENU_SUB: // show sub
      LCDprint_P(0, (const char *)pgm_read_word(&widgets[setup_id].title_txt));
      addr = (const char * const *)pgm_read_word(&widgets[setup_id].option_txt);
      while (addr != NULL) {
        const char *txt;
        txt = (const char *)pgm_read_word(addr);
        if ((const char)pgm_read_byte(txt) == setting.b[setup_id]) {
          LCDprint_P(1, (const char *)txt);
          break;
        }
        addr++;
      }
      if (addr == NULL) {
        lcd.setCursor(0, 1);
        lcd.print(F("ERROR           "));
      } else {
        BLINK();
      }
      break;
    case MENU_EXIT: // "EXIT"
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print(F("EXIT"));
      BLINK();
      break;
    case MENU_SETTING: // Iliad setting
      Iliad_updateLCD();
      break;
  }
}

