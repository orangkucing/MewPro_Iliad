void printHex(uint8_t d, boolean upper)
{
  char t;
  char a = upper ? 'A' : 'a';
  t = d >> 4 | '0';
  if (t > '9') {
    t += a - '9' - 1;
  }
  SERIAL.print(t);
  t = d & 0xF | '0';
  if (t > '9') {
    t += a - '9' - 1;
  }
  SERIAL.print(t);
}

void _printOutPut()
{
  int buflen = buf[0];
  SERIAL.print(F("> "));
  for (int i = 4; i <= buflen; i++) {
    if ((i == 4 || i == 5) && isprint(buf[i])) {
      SERIAL.print(' '); SERIAL.print((char) buf[i]);
    } else {
      printHex(buf[i], false);
    }
    SERIAL.print(' ');
  }
  SERIAL.println("");
}

void parseCameraCommand()
{
  _printOutPut();
  switch (buf[2]) {
    case 2: // two letter commands
      switch ((buf[4] << 8) + buf[5]) {
        case ('Y' << 8) + 'Y':
          YYcommand();
          break;
        case ('Z' << 8) + 'Z':
          ZZcommand();
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}

void YYcommand()
{
  switch (buf[8]) {
    default:
      extendedYYcommand();
      break;
  }
}

int ZZcommand()
{
  switch (buf[8]) {
    case 1: // bacpac capabilities? Dual Hero only
      switch (buf[9]) {
        case 0:
          // capabilities?
          break;
      }
      break;
    case 2: // power on/off by long button press at primary camera
      switch (buf[9]) {
        case 0: // power off
        break;
        case 1: // power on
        break;
      }
      break;
    case 3: // get camera version
      break;
    case 0: // extended command
      extendedZZcommand(); 
      break;
    default:
      break;
  }
}

int extendedYYcommand()
{
  switch (buf[9]) {
    case 1: // mode change
      switch (buf[10]) {
        case 1: // set main mode
          setting.p.mode = buf[13];
          break;
        case 5: // set sub mode
          //                        main       sub
          setting.p.current_submode[buf[13]] = buf[14];
          break;
        default:
          break;
      }
      break;
    case 2: // video
      switch (buf[10]) {
        case 1: // default sub mode
          storeDefaultSubMode(MODE_VIDEO, buf[13]);
          break;
        case 27: // shutter button depressed. start
          break;
        case 28: // sync stop
          break;
        case 38: // all video settings
          for (int i = 0; i < 4; i++) {
            storage[i].p.video.default_sub_mode      = buf[14 + i * 24];
            storage[i].p.video.resolution            = buf[15 + i * 24];
            storage[i].p.video.fps                   = buf[16 + i * 24];
            storage[i].p.video.fov                   = buf[17 + i * 24];
            storage[i].p.video.piv                   = buf[18 + i * 24];
            storage[i].p.video.looping               = buf[19 + i * 24];
            storage[i].p.video.spot_meter            = buf[20 + i * 24];
            storage[i].p.video.low_light             = buf[21 + i * 24];
            storage[i].p.video.timelapse_rate        = buf[22 + i * 24];
            storage[i].p.video.protune               = buf[23 + i * 24];
            storage[i].p.video.protune_color         = buf[24 + i * 24];
            storage[i].p.video.protune_sharpness     = buf[25 + i * 24];
            storage[i].p.video.protune_iso           = buf[26 + i * 24];
            storage[i].p.video.protune_ev            = buf[27 + i * 24];
            storage[i].p.video.protune_white_balance = buf[28 + i * 24];
            storage[i].p.v4.videoExposure_time       = buf[29 + i * 24];
            storage[i].p.v4.videoProtune_iso_mode    = buf[30 + i * 24];
          }
          loadSetupValue();
          break;
        default:
          break;
      }
      break;
    case 3: // photo
      switch (buf[10]) {
        case 1: // default sub mode
          storeDefaultSubMode(MODE_PHOTO, buf[13]);
          break;
        case 23: // shutter button depressed. start
          break;
        case 27: // all photo settings
          for (int i = 0; i < 3; i++) {
            storage[i].p.photo.default_sub_mode      = buf[14 + i * 20];
            storage[i].p.photo.resolution            = buf[15 + i * 20];
            storage[i].p.photo.continuous_rate       = buf[16 + i * 20];
            storage[i].p.photo.spot_meter            = buf[17 + i * 20];
            storage[i].p.photo.exposure_time         = buf[18 + i * 20];
            storage[i].p.photo.protune               = buf[19 + i * 20];
            storage[i].p.photo.protune_color         = buf[20 + i * 20];
            storage[i].p.photo.protune_sharpness     = buf[21 + i * 20];
            storage[i].p.photo.protune_iso           = buf[22 + i * 20];
            storage[i].p.photo.protune_ev            = buf[23 + i * 20];
            storage[i].p.photo.protune_white_balance = buf[24 + i * 20];
            storage[i].p.v4.photoProtune_iso_min     = buf[25 + i * 20];
          }
          loadSetupValue();
          break;
        default:
          break;
      }
      break;
    case 4: // multi-shot
      switch (buf[10]) {
        case 1: // default sub mode
          storeDefaultSubMode(MODE_MULTI_SHOT, buf[13]);
          break;
        case 27: // shutter button depressed. start
          break;
        case 32: // all multi-shot settings
          for (int i = 0; i < 3; i++) {
            storage[i].p.multi_shot.default_sub_mode      = buf[14 + i * 22];
            storage[i].p.multi_shot.resolution            = buf[15 + i * 22];
            storage[i].p.multi_shot.burst_rate            = buf[16 + i * 22];
            storage[i].p.multi_shot.timelapse_rate        = buf[17 + i * 22];
            storage[i].p.multi_shot.nightlapse_rate       = buf[18 + i * 22];
            storage[i].p.multi_shot.spot_meter            = buf[19 + i * 22];
            storage[i].p.multi_shot.exposure_time         = buf[20 + i * 22];
            storage[i].p.multi_shot.protune               = buf[21 + i * 22];
            storage[i].p.multi_shot.protune_color         = buf[22 + i * 22];
            storage[i].p.multi_shot.protune_sharpness     = buf[23 + i * 22];
            storage[i].p.multi_shot.protune_iso           = buf[24 + i * 22];
            storage[i].p.multi_shot.protune_ev            = buf[25 + i * 22];
            storage[i].p.multi_shot.protune_white_balance = buf[26 + i * 22];
            storage[i].p.v4.multi_shotProtune_iso_min     = buf[27 + i * 22];
          }
          loadSetupValue();
          break;
        default:
          break;
      }
      break;
    case 7: // global settings
      switch (buf[10]) {
        case 9: // orientation
          // there's a bug in v4.0.0 firmware that prevents from setting orientation to AUTO
          setting.p.setup.orientation = buf[13];
          break;
        case 11: // default mode
          setting.p.setup.default_app_mode = buf[13];
          break;
        case 13: // quick capture
          setting.p.setup.quick_capture = buf[13];
          break;
        case 15: // LEDs
          setting.p.setup.led = buf[13];
          break;
        case 17: // beeps
          setting.p.setup.beep_volume = buf[13];
          break;
        case 19: // video format
          setting.p.setup.video_format = buf[13];
          break;
        case 21: // OSD
          setting.p.setup.osd = buf[13];
          break;
        case 23: // auto power down
          setting.p.setup.auto_power_down = buf[13];
          break;
        case 27: // date/time (Note: a word data is stored as big-endian)
          // buf[11:12]        buf[13:14] buf[15] buf[16] buf[17] buf[18] buf[19]
          // arglen = 7  args: year       month   day     hour    minute  second
          rtc.adjust(DateTime((int)(buf[13] * 256 + buf[14]), buf[15], buf[16], buf[17], buf[18], buf[19]));
          break;
        case 32: // language
          break;
        case 33: // all global settings
          setting.p.setup.osd = buf[19];
          setting.p.setup.beep_volume = buf[20];
          setting.p.setup.auto_power_down = buf[21];
          setting.p.setup.led = buf[22];
          setting.p.setup.quick_capture = buf[23];
          setting.p.setup.orientation = buf[24];
          // buf[25]; // const 0; unknown
          // buf[26]; // const 1; unknown
          // buf[27]; // const 1; unknown
          // buf[28]; // const 1; unknown
          setting.p.setup.video_format = buf[29];
          // buf[30]; // 0: English, 1: Simplified Chinese
          // buf[31:37] // reserved
          // buf[38]; // const 1; unknown
          setting.p.setup.default_app_mode = buf[39];
          storeDefaultSubMode(setting.p.setup.default_app_mode, buf[40]);
          rtc.adjust(DateTime((int)(buf[41] * 256 + buf[42]), buf[43], buf[44], buf[45], buf[46], buf[47]));         
          break;
        default:
          break;
      }
      break;
    case 9: // delete
      switch (buf[10]) {
        case 9: // delete last
          break;
        case 10: // delete all/format
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}

void extendedZZcommand()
{
  switch (buf[9]) {
    case 0: // protocol revision
      // current protocol revision is 1 0 0
      break;
    case 1: // sync
      switch (buf[10]) {
        case 1: // status request
          switch (buf[11]) {
            case 0:
              break;
            case 1:
              break;
            default:
              break;
          }
          break;
        case 2: // block until writing to microSD complete
          break;
        default:
          break;
      }
      break;
    case 2: // Heartbeat
      break;
    case 3: // power off
      disp_state = MENU_START;
      ROM_write(); // store settings to EEPROM
      break;
    case 5: // bacpac firmware version
      break;
    case 6: // bacpac serial number
      break;
    default:
      break;
  }
}
