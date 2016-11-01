// these functions are called after camera power on
void startup_delay0()
{
  delay(8000);
}

void startup_delay()
{
  delay(1000);
}
void startup0()
{
  // since MODE_SETUP's options includes video_format (NTSC/PAL), it must be sent before MODE_VIDEO
  Broadcast_ChangeSettings(MODE_SETUP);
}

void startup1()
{
  Broadcast_ChangeSettings(MODE_VIDEO);
}

void startup2()
{
  Broadcast_ChangeSettings(MODE_PHOTO);
}

void startup3()
{
  Broadcast_ChangeSettings(MODE_MULTI_SHOT);
}

void startup4()
{
  // default_app_mode is ignored by the camera so must manually change the start up mode.
  // first, it's impossible to set MODE_SETUP as starting let's change there 
  FIFOCPY_P(0, F("YY000101000100\n"), 15);
  sprintHex(12, MODE_SETUP);
  FIFO_INC(15);
}

void startup5()
{
  // next, change to the desired default_app_mode
  setting.p.mode = setting.p.setup.default_app_mode;
  switch (setting.p.mode) {
    case MODE_VIDEO:
      setting.p.current_submode[MODE_VIDEO] = setting.p.video.default_sub_mode;
      break;
    case MODE_PHOTO:
      setting.p.current_submode[MODE_VIDEO] = setting.p.photo.default_sub_mode;
      break;
    case MODE_MULTI_SHOT:
      setting.p.current_submode[MODE_MULTI_SHOT] = setting.p.multi_shot.default_sub_mode;
      break;
  }
  Broadcast_ChangeSubMode();
}
//

void sprintHex(int index, uint8_t d)
{
  char t;
  char a = 'A';
  t = d >> 4 | '0';
  if (t > '9') {
    t += a - '9' - 1;
  }
  FIFO(index) = t;
  t = d & 0xF | '0';
  if (t > '9') {
    t += a - '9' - 1;
  }
  FIFO(index + 1) = t;
}

void FIFOCPY_P(int index, const __FlashStringHelper *p, int s)
{
  for (int i = 0; i < s; i++) {
    FIFO(index + i) = (char)pgm_read_byte((char *)p + i);
  }
}

void Broadcast_ChangeMode()
{
  // next mode
  switch (setting.p.mode) {
    case MODE_VIDEO:
      setting.p.mode = MODE_PHOTO;
      break;
    case MODE_PHOTO:
      setting.p.mode = MODE_MULTI_SHOT;
      break;
    case MODE_MULTI_SHOT:
      setting.p.mode = MODE_SETUP;
      break;
    case MODE_SETUP:
      setting.p.mode = MODE_VIDEO;
      break;
  }
  if (setting.p.mode == MODE_SETUP) {
    FIFOCPY_P(0, F("YY000101000100\n"), 15);
    sprintHex(12, setting.p.mode);
    FIFO_INC(15);
  } else {
    // there is a firmware bug that doesn't sync current sub mode...
    Broadcast_ChangeSubMode();
  }
}

void Broadcast_ChangeSubMode()
{
  FIFOCPY_P(0, F("YY00010500020000\n"), 17);
  sprintHex(12, setting.p.mode);
  sprintHex(14, setting.p.current_submode[setting.p.mode]);
  FIFO_INC(17);
}

void Broadcast_ChangeSettings(char mode)
{
  DateTime now;
  if (startupSession == STARTUP_HALT) {
    // not within startup sessions
    while (nextWidget()) { // update to permissible options
      ; 
    }
#ifndef BULK_SETTING_TRANSFER
    // default firmware doesn't understand bulk setting transfer unless start up
    return;
#endif
  }
  switch (mode) {
    case MODE_VIDEO:
      FIFOCPY_P(0, F("YY0002260060"), 6 * 2);
      // sub mode: video
      sprintHex((6 + 0) * 2, 0);
      sprintHex((6 + 1) * 2, storage[0].p.video.default_sub_mode);
      sprintHex((6 + 2) * 2, storage[0].p.video.resolution);
      sprintHex((6 + 3) * 2, storage[0].p.video.fps);
      sprintHex((6 + 4) * 2, storage[0].p.video.fov);
      sprintHex((6 + 5) * 2, storage[2].p.video.piv);
      sprintHex((6 + 6) * 2, storage[3].p.video.looping);
      sprintHex((6 + 7) * 2, storage[0].p.video.spot_meter);
      sprintHex((6 + 8) * 2, storage[0].p.video.low_light);
      sprintHex((6 + 9) * 2, storage[1].p.video.timelapse_rate);
      sprintHex((6 + 10) * 2, storage[0].p.video.protune);
      sprintHex((6 + 11) * 2, storage[0].p.video.protune_color);
      sprintHex((6 + 12) * 2, storage[0].p.video.protune_sharpness);
      sprintHex((6 + 13) * 2, storage[0].p.video.protune_iso);
      sprintHex((6 + 14) * 2, storage[0].p.video.protune_ev);
      sprintHex((6 + 15) * 2, storage[0].p.video.protune_white_balance);
      sprintHex((6 + 16) * 2, 0 /* storage[0].p.v4.videoExposure_time */);
      sprintHex((6 + 17) * 2, 0 /* storage[0].p.v4.videoProtune_iso_mode */);
      FIFOCPY_P(48, F("000000000000"), 12); // reserved
      // sub mode: timelapse video
      sprintHex((30 + 0) * 2, 0);
      sprintHex((30 + 1) * 2, storage[1].p.video.default_sub_mode);
      sprintHex((30 + 2) * 2, storage[1].p.video.resolution);
      sprintHex((30 + 3) * 2, storage[1].p.video.fps);
      sprintHex((30 + 4) * 2, storage[1].p.video.fov);
      sprintHex((30 + 5) * 2, storage[2].p.video.piv);
      sprintHex((30 + 6) * 2, storage[3].p.video.looping);
      sprintHex((30 + 7) * 2, storage[0].p.video.spot_meter);
      sprintHex((30 + 8) * 2, storage[0].p.video.low_light);
      sprintHex((30 + 9) * 2, storage[1].p.video.timelapse_rate);
      sprintHex((30 + 10) * 2, storage[0].p.video.protune);
      sprintHex((30 + 11) * 2, storage[0].p.video.protune_color);
      sprintHex((30 + 12) * 2, storage[0].p.video.protune_sharpness);
      sprintHex((30 + 13) * 2, storage[0].p.video.protune_iso);
      sprintHex((30 + 14) * 2, storage[0].p.video.protune_ev);
      sprintHex((30 + 15) * 2, storage[0].p.video.protune_white_balance);
      sprintHex((30 + 16) * 2, 0 /* storage[0].p.v4.videoExposure_time */);
      sprintHex((30 + 17) * 2, 0 /* storage[0].p.v4.videoProtune_iso_mode */);
      FIFOCPY_P(96, F("000000000000"), 12); // reserved
      // sub mode: video + photo
      sprintHex((54 + 0) * 2, 0);
      sprintHex((54 + 1) * 2, storage[2].p.video.default_sub_mode);
      sprintHex((54 + 2) * 2, storage[2].p.video.resolution);
      sprintHex((54 + 3) * 2, storage[2].p.video.fps);
      sprintHex((54 + 4) * 2, storage[2].p.video.fov);
      sprintHex((54 + 5) * 2, storage[2].p.video.piv);
      sprintHex((54 + 6) * 2, storage[3].p.video.looping);
      sprintHex((54 + 7) * 2, storage[2].p.video.spot_meter);
      sprintHex((54 + 8) * 2, storage[2].p.video.low_light);
      sprintHex((54 + 9) * 2, storage[1].p.video.timelapse_rate);
      sprintHex((54 + 10) * 2, storage[0].p.video.protune);
      sprintHex((54 + 11) * 2, storage[0].p.video.protune_color);
      sprintHex((54 + 12) * 2, storage[0].p.video.protune_sharpness);
      sprintHex((54 + 13) * 2, storage[0].p.video.protune_iso);
      sprintHex((54 + 14) * 2, storage[0].p.video.protune_ev);
      sprintHex((54 + 15) * 2, storage[0].p.video.protune_white_balance);
      sprintHex((54 + 16) * 2, 0 /* storage[0].p.v4.videoExposure_time */);
      sprintHex((54 + 17) * 2, 0 /* storage[0].p.v4.videoProtune_iso_mode */);
      FIFOCPY_P(144, F("000000000000"), 12); // reserved
      // sub mode: looping
      sprintHex((78 + 0) * 2, 0);
      sprintHex((78 + 1) * 2, storage[3].p.video.default_sub_mode);
      sprintHex((78 + 2) * 2, storage[3].p.video.resolution);
      sprintHex((78 + 3) * 2, storage[3].p.video.fps);
      sprintHex((78 + 4) * 2, storage[3].p.video.fov);
      sprintHex((78 + 5) * 2, storage[2].p.video.piv);
      sprintHex((78 + 6) * 2, storage[3].p.video.looping);
      sprintHex((78 + 7) * 2, storage[3].p.video.spot_meter);
      sprintHex((78 + 8) * 2, storage[3].p.video.low_light);
      sprintHex((78 + 9) * 2, storage[1].p.video.timelapse_rate);
      sprintHex((78 + 10) * 2, storage[0].p.video.protune);
      sprintHex((78 + 11) * 2, storage[0].p.video.protune_color);
      sprintHex((78 + 12) * 2, storage[0].p.video.protune_sharpness);
      sprintHex((78 + 13) * 2, storage[0].p.video.protune_iso);
      sprintHex((78 + 14) * 2, storage[0].p.video.protune_ev);
      sprintHex((78 + 15) * 2, storage[0].p.video.protune_white_balance);
      sprintHex((78 + 16) * 2, 0 /* storage[0].p.v4.videoExposure_time */);
      sprintHex((78 + 17) * 2, 0 /* storage[0].p.v4.videoProtune_iso_mode */);
      FIFOCPY_P(192, F("000000000000"), 12); // reserved
      //
      FIFO(204) = '\n';
      FIFO_INC(205);
      break;
    case MODE_PHOTO:
      FIFOCPY_P(0, F("YY00031B003C"), 6 * 2);
      // sub mode: single
      sprintHex((6 + 0) * 2, 0);
      sprintHex((6 + 1) * 2, storage[0].p.photo.default_sub_mode);
      sprintHex((6 + 2) * 2, storage[0].p.photo.resolution);
      sprintHex((6 + 3) * 2, storage[1].p.photo.continuous_rate);
      sprintHex((6 + 4) * 2, storage[0].p.photo.spot_meter);
      sprintHex((6 + 5) * 2, storage[2].p.photo.exposure_time);
      sprintHex((6 + 6) * 2, storage[0].p.photo.protune);
      sprintHex((6 + 7) * 2, storage[0].p.photo.protune_color);
      sprintHex((6 + 8) * 2, storage[0].p.photo.protune_sharpness);
      sprintHex((6 + 9) * 2, storage[0].p.photo.protune_iso);
      sprintHex((6 + 10) * 2, storage[0].p.photo.protune_ev);
      sprintHex((6 + 11) * 2, storage[0].p.photo.protune_white_balance);
      sprintHex((6 + 12) * 2, 3 /* storage[0].p.v4.photoProtune_iso_min */);
      FIFOCPY_P(38, F("00000000000000"), 14); // reserved
      // sub mode: continuous
      sprintHex((26 + 0) * 2, 0);
      sprintHex((26 + 1) * 2, storage[1].p.photo.default_sub_mode);
      sprintHex((26 + 2) * 2, storage[1].p.photo.resolution);
      sprintHex((26 + 3) * 2, storage[1].p.photo.continuous_rate);
      sprintHex((26 + 4) * 2, storage[1].p.photo.spot_meter);
      sprintHex((26 + 5) * 2, storage[2].p.photo.exposure_time);
      sprintHex((26 + 6) * 2, storage[1].p.photo.protune);
      sprintHex((26 + 7) * 2, storage[1].p.photo.protune_color);
      sprintHex((26 + 8) * 2, storage[1].p.photo.protune_sharpness);
      sprintHex((26 + 9) * 2, storage[1].p.photo.protune_iso);
      sprintHex((26 + 10) * 2, storage[1].p.photo.protune_ev);
      sprintHex((26 + 11) * 2, storage[1].p.photo.protune_white_balance);
      sprintHex((26 + 12) * 2, 3 /* storage[1].p.v4.photoProtune_iso_min */);
      FIFOCPY_P(78, F("00000000000000"), 14); // reserved
      // sub mode: night
      sprintHex((46 + 0) * 2, 0);
      sprintHex((46 + 1) * 2, storage[2].p.photo.default_sub_mode);
      sprintHex((46 + 2) * 2, storage[2].p.photo.resolution);
      sprintHex((46 + 3) * 2, storage[1].p.photo.continuous_rate);
      sprintHex((46 + 4) * 2, storage[2].p.photo.spot_meter);
      sprintHex((46 + 5) * 2, storage[2].p.photo.exposure_time);
      sprintHex((46 + 6) * 2, storage[2].p.photo.protune);
      sprintHex((46 + 7) * 2, storage[2].p.photo.protune_color);
      sprintHex((46 + 8) * 2, storage[2].p.photo.protune_sharpness);
      sprintHex((46 + 9) * 2, storage[2].p.photo.protune_iso);
      sprintHex((46 + 10) * 2, storage[2].p.photo.protune_ev);
      sprintHex((46 + 11) * 2, storage[2].p.photo.protune_white_balance);
      sprintHex((46 + 12) * 2, 3 /* storage[2].p.v4.photoProtune_iso_min */);
      FIFOCPY_P(118, F("00000000000000"), 14); // reserved
      //
      FIFO(132) = '\n';
      FIFO_INC(133);
      break;
    case MODE_MULTI_SHOT:
      FIFOCPY_P(0, F("YY0004200042"), 6 * 2);
      // sub mode: burst
      sprintHex((6 + 0) * 2, 0);
      sprintHex((6 + 1) * 2, storage[0].p.multi_shot.default_sub_mode);
      sprintHex((6 + 2) * 2, storage[0].p.multi_shot.resolution);
      sprintHex((6 + 3) * 2, storage[0].p.multi_shot.burst_rate);
      sprintHex((6 + 4) * 2, storage[1].p.multi_shot.timelapse_rate);
      sprintHex((6 + 5) * 2, storage[2].p.multi_shot.nightlapse_rate);
      sprintHex((6 + 6) * 2, storage[0].p.multi_shot.spot_meter);
      sprintHex((6 + 7) * 2, storage[2].p.multi_shot.exposure_time);
      sprintHex((6 + 8) * 2, storage[0].p.multi_shot.protune);
      sprintHex((6 + 9) * 2, storage[0].p.multi_shot.protune_color);
      sprintHex((6 + 10) * 2, storage[0].p.multi_shot.protune_sharpness);
      sprintHex((6 + 11) * 2, storage[0].p.multi_shot.protune_iso);
      sprintHex((6 + 12) * 2, storage[0].p.multi_shot.protune_ev);
      sprintHex((6 + 13) * 2, storage[0].p.multi_shot.protune_white_balance);
      sprintHex((6 + 14) * 2, 4 /* storage[0].p.v4.multi_shotProtune_iso_min */);
      FIFOCPY_P(42, F("00000000000000"), 14); // reserved
      // sub mode: timelapse
      sprintHex((28 + 0) * 2, 0);
      sprintHex((28 + 1) * 2, storage[1].p.multi_shot.default_sub_mode);
      sprintHex((28 + 2) * 2, storage[1].p.multi_shot.resolution);
      sprintHex((28 + 3) * 2, storage[0].p.multi_shot.burst_rate);
      sprintHex((28 + 4) * 2, storage[1].p.multi_shot.timelapse_rate);
      sprintHex((28 + 5) * 2, storage[2].p.multi_shot.nightlapse_rate);
      sprintHex((28 + 6) * 2, storage[1].p.multi_shot.spot_meter);
      sprintHex((28 + 7) * 2, storage[2].p.multi_shot.exposure_time);
      sprintHex((28 + 8) * 2, storage[1].p.multi_shot.protune);
      sprintHex((28 + 9) * 2, storage[1].p.multi_shot.protune_color);
      sprintHex((28 + 10) * 2, storage[1].p.multi_shot.protune_sharpness);
      sprintHex((28 + 11) * 2, storage[1].p.multi_shot.protune_iso);
      sprintHex((28 + 12) * 2, storage[1].p.multi_shot.protune_ev);
      sprintHex((28 + 13) * 2, storage[1].p.multi_shot.protune_white_balance);
      sprintHex((28 + 14) * 2, 4 /* storage[1].p.v4.multi_shotProtune_iso_min */);
      FIFOCPY_P(86, F("00000000000000"), 14); // reserved
      // sub mode: night lapse
      sprintHex((50 + 0) * 2, 0);
      sprintHex((50 + 1) * 2, storage[2].p.multi_shot.default_sub_mode);
      sprintHex((50 + 2) * 2, storage[2].p.multi_shot.resolution);
      sprintHex((50 + 3) * 2, storage[0].p.multi_shot.burst_rate);
      sprintHex((50 + 4) * 2, storage[1].p.multi_shot.timelapse_rate);
      sprintHex((50 + 5) * 2, storage[2].p.multi_shot.nightlapse_rate);
      sprintHex((50 + 6) * 2, storage[2].p.multi_shot.spot_meter);
      sprintHex((50 + 7) * 2, storage[2].p.multi_shot.exposure_time);
      sprintHex((50 + 8) * 2, storage[2].p.multi_shot.protune);
      sprintHex((50 + 9) * 2, storage[2].p.multi_shot.protune_color);
      sprintHex((50 + 10) * 2, storage[2].p.multi_shot.protune_sharpness);
      sprintHex((50 + 11) * 2, storage[2].p.multi_shot.protune_iso);
      sprintHex((50 + 12) * 2, storage[2].p.multi_shot.protune_ev);
      sprintHex((50 + 13) * 2, storage[2].p.multi_shot.protune_white_balance);
      sprintHex((50 + 14) * 2, 4 /* storage[2].p.v4.multi_shotProtune_iso_min */);
      FIFOCPY_P(130, F("00000000000000"), 14); // reserved
      //
      FIFO(144) = '\n';
      FIFO_INC(145);  
      break;
    case MODE_SETUP:
      FIFOCPY_P(0, F("YY0007210023"), 12);
      FIFOCPY_P(12, F("201601110000"), 12); // 2016/01/11 mimicking master firmware v4.0.0
      sprintHex(12 * 2, setting.p.setup.osd);
      sprintHex(13 * 2, setting.p.setup.beep_volume);
      sprintHex(14 * 2, setting.p.setup.auto_power_down);
      sprintHex(15 * 2, setting.p.setup.led);
      sprintHex(16 * 2, setting.p.setup.quick_capture);
      sprintHex(17 * 2, setting.p.setup.orientation);
      sprintHex(18 * 2, 0); // unknown
      sprintHex(19 * 2, 1); // unknown
      sprintHex(20 * 2, 1); // unknown
      sprintHex(21 * 2, 1); // unknown
      sprintHex(22 * 2, setting.p.setup.video_format);
      sprintHex(23 * 2, 0); // 0: English, 1: Simplified Chinese
      FIFOCPY_P(48, F("00000000000000"), 14); // reserved
      sprintHex(31 * 2, 1); // unknown
      sprintHex(32 * 2, setting.p.setup.default_app_mode);
      switch (setting.p.setup.default_app_mode) {
        case MODE_VIDEO:
          sprintHex(33 * 2, setting.p.video.default_sub_mode);
          break;
        case MODE_PHOTO:
          sprintHex(33 * 2, setting.p.photo.default_sub_mode);
          break;
        case MODE_MULTI_SHOT:
          sprintHex(33 * 2, setting.p.multi_shot.default_sub_mode);
          break;
      }
      now = rtc.now();
      sprintHex(34 * 2, (uint8_t)(now.year() / 256));
      sprintHex(35 * 2, (uint8_t)(now.year() % 256));
      sprintHex(36 * 2, (uint8_t)now.month());
      sprintHex(37 * 2, (uint8_t)now.day());
      sprintHex(38 * 2, (uint8_t)now.hour());
      sprintHex(39 * 2, (uint8_t)now.minute());
      sprintHex(40 * 2, (uint8_t)now.second());
      FIFO(82) = '\n';
      FIFO_INC(83);
      break;
  }
}

void __queueIn(char main, char sub, char arg)
{
  FIFOCPY_P(0, F("YY000000000100\n"), 15);
  sprintHex(4, main);
  sprintHex(6, sub);
  sprintHex(12, arg);
  FIFO_INC(15);
}

void Broadcast_ChangeSetting(char id)
{
#ifndef BULK_SETTING_TRANSFER
  switch (id) {
    case &setting.p.video.default_sub_mode - setting.b:
      __queueIn(2, 1, setting.p.video.default_sub_mode); break;
    //
    case &setting.p.video.resolution - setting.b:
    case &setting.p.video.fps - setting.b:
    case &setting.p.video.fov - setting.b:
      if (!blacklist((char)(&setting.p.video.fps - setting.b), setting.p.video.fps) && !blacklist((char)(&setting.p.video.fov - setting.b), setting.p.video.fov)) {
        FIFOCPY_P(0, F("YY0002030003000000\n"), 19);
        sprintHex(12, setting.p.video.resolution);
        sprintHex(14, setting.p.video.fps);
        sprintHex(16, setting.p.video.fov);
        FIFO_INC(19);
      }
      break;
    //
    case &setting.p.video.timelapse_rate - setting.b:
      __queueIn(2, 13, setting.p.video.timelapse_rate); break;
    case &setting.p.video.looping - setting.b:
      __queueIn(2, 7, setting.p.video.looping); break;
    case &setting.p.video.piv - setting.b:
      __queueIn(2, 5, setting.p.video.piv); break;
    case &setting.p.video.low_light - setting.b:
      __queueIn(2, 9, setting.p.video.low_light); break;
    case &setting.p.video.spot_meter - setting.b:
      __queueIn(2, 11, setting.p.video.spot_meter); break;
    case &setting.p.video.protune - setting.b:
      __queueIn(2, 15, setting.p.video.protune); break;
    case &setting.p.video.protune_white_balance - setting.b:
      __queueIn(2, 17, setting.p.video.protune_white_balance); break;
    case &setting.p.video.protune_color - setting.b:
      __queueIn(2, 19, setting.p.video.protune_color); break;
    case &setting.p.video.protune_iso - setting.b:
      __queueIn(2, 23, setting.p.video.protune_iso); break;
    case &setting.p.video.protune_sharpness - setting.b:
      __queueIn(2, 21, setting.p.video.protune_sharpness); break;
    case &setting.p.video.protune_ev - setting.b:  
      __queueIn(2, 25, setting.p.video.protune_ev); break;
    case &setting.p.photo.default_sub_mode - setting.b:
      __queueIn(3, 1, setting.p.photo.default_sub_mode); break;
    case &setting.p.photo.resolution - setting.b:
      __queueIn(3, 3, setting.p.photo.resolution); break;
    case &setting.p.photo.continuous_rate - setting.b:
      __queueIn(3, 5, setting.p.photo.continuous_rate); break;
    case &setting.p.photo.exposure_time - setting.b:
      __queueIn(3, 9, setting.p.photo.exposure_time); break;
    case &setting.p.photo.spot_meter - setting.b:
      __queueIn(3, 7, setting.p.photo.spot_meter); break;
    case &setting.p.photo.protune - setting.b:
      __queueIn(3, 11, setting.p.photo.protune); break;
    case &setting.p.photo.protune_white_balance - setting.b:
      __queueIn(3, 13, setting.p.photo.protune_white_balance); break;
    case &setting.p.photo.protune_color - setting.b:
      __queueIn(3, 15, setting.p.photo.protune_color); break;
    case &setting.p.photo.protune_iso - setting.b:
      __queueIn(3, 19, setting.p.photo.protune_iso); break;
    case &setting.p.photo.protune_sharpness - setting.b:
      __queueIn(3, 17, setting.p.photo.protune_sharpness); break;
    case &setting.p.photo.protune_ev - setting.b:
      __queueIn(3, 21, setting.p.photo.protune_ev); break;
    case &setting.p.multi_shot.default_sub_mode - setting.b:
      __queueIn(4, 1, setting.p.multi_shot.default_sub_mode); break;
    case &setting.p.multi_shot.resolution - setting.b:
      __queueIn(4, 3, setting.p.multi_shot.resolution); break;
    case &setting.p.multi_shot.burst_rate - setting.b:
      __queueIn(4, 5, setting.p.multi_shot.burst_rate); break;
    case &setting.p.multi_shot.timelapse_rate - setting.b:
      __queueIn(4, 7, setting.p.multi_shot.timelapse_rate); break;
    case &setting.p.multi_shot.exposure_time - setting.b:
      __queueIn(4, 13, setting.p.multi_shot.exposure_time); break;
    case &setting.p.multi_shot.nightlapse_rate - setting.b:
      __queueIn(4, 9, setting.p.multi_shot.nightlapse_rate); break;
    case &setting.p.multi_shot.spot_meter - setting.b:
      __queueIn(4, 11, setting.p.multi_shot.spot_meter); break;
    case &setting.p.multi_shot.protune - setting.b:
      __queueIn(4, 15, setting.p.multi_shot.protune); break;
    case &setting.p.multi_shot.protune_white_balance - setting.b:
      __queueIn(4, 17, setting.p.multi_shot.protune_white_balance); break;
    case &setting.p.multi_shot.protune_color - setting.b:
      __queueIn(4, 19, setting.p.multi_shot.protune_color); break;
    case &setting.p.multi_shot.protune_iso - setting.b:
      __queueIn(4, 23, setting.p.multi_shot.protune_iso); break;
    case &setting.p.multi_shot.protune_sharpness - setting.b:
      __queueIn(4, 21, setting.p.multi_shot.protune_sharpness); break;
    case &setting.p.multi_shot.protune_ev - setting.b:
      __queueIn(4, 25, setting.p.multi_shot.protune_ev); break;
    case &setting.p.setup.orientation - setting.b:
      __queueIn(7, 9, setting.p.setup.orientation); break;
    case &setting.p.setup.default_app_mode - setting.b:
      __queueIn(7, 11, setting.p.setup.default_app_mode); break;
    case &setting.p.setup.quick_capture - setting.b:
      __queueIn(7, 13, setting.p.setup.quick_capture); break;
    case &setting.p.setup.led - setting.b:
      __queueIn(7, 15, setting.p.setup.led); break;
    case &setting.p.setup.beep_volume - setting.b:
      __queueIn(7, 17, setting.p.setup.beep_volume); break;
    case &setting.p.setup.video_format - setting.b:
      __queueIn(7, 19, setting.p.setup.video_format); break;
    case &setting.p.setup.osd - setting.b:
      __queueIn(7, 21, setting.p.setup.osd); break;
    case &setting.p.setup.auto_power_down - setting.b:
      __queueIn(7, 23, setting.p.setup.auto_power_down); break;
    //
    case &setting.p.current_submode[MODE_VIDEO] - setting.b:
    case &setting.p.current_submode[MODE_PHOTO] - setting.b:
    case &setting.p.current_submode[MODE_MULTI_SHOT] - setting.b:
      Broadcast_ChangeSubMode(); break;
    //
//  case &setting.p.v4.videoExposure_time - setting.b:
//    __queueIn(2, 40, setting.p.v4.videoExposure_time); break;
//  case &setting.p.v4.videoProtune_iso_mode - setting.b:
//    __queueIn(2, 42, setting.p.v4.videoProtune_iso_mode); break;
//  case &setting.p.v4.photoProtune_iso_min - setting.b:
//    __queueIn(3, 29, setting.p.v4.photoProtune_iso_min); break;
//  case &setting.p.v4.multi_shotProtune_iso_min - setting.b:
//    __queueIn(4, 34, setting.p.v4.multi_shotProtune_iso_min); break;
  }
#endif /* not BULK_SETTING_TRANSFER */
}

void Broadcast_StartRecording()
{
  DateTime now;
  switch (setting.p.mode) {
    case MODE_VIDEO:
      // default firmware doesn't need current time info that will be automatically truncated at MewPro
      now = rtc.now();
      FIFOCPY_P(0, F("YY00021B0004"), 12);
      // Omni firmware requires timestamp info
      sprintHex(12, (uint8_t)now.day());
      sprintHex(14, (uint8_t)now.hour());
      sprintHex(16, (uint8_t)now.minute());
      sprintHex(18, (uint8_t)now.second());
      FIFO(20) = '\n';
      FIFO_INC(21);
      break;
    case MODE_PHOTO:
      FIFOCPY_P(0, F("YY0003170000\n"), 13);
      FIFO_INC(13);
      break;
    case MODE_MULTI_SHOT:
      FIFOCPY_P(0, F("YY00041B0000\n"), 13);
      FIFO_INC(13);
      break;
  }
}

void Broadcast_StopRecording()
{
  switch (setting.p.mode) {
    case MODE_VIDEO:
      FIFOCPY_P(0, F("YY00021C0000\n"), 13);
      break;
    case MODE_PHOTO:
      FIFOCPY_P(0, F("YY0003180000\n"), 13);
      break;
    case MODE_MULTI_SHOT:
      FIFOCPY_P(0, F("YY00041C0000\n"), 13);
      break;
  }
  FIFO_INC(13);
}

void Broadcast_PowerOn()
{
  FIFO(0) = '@';
  FIFO(1) = '\n';
  FIFO_INC(2);
}

void Broadcast_PowerOff()
{
  FIFOCPY_P(0, F("ZZ00030101\n"), 11);
  FIFO_INC(11);
}

