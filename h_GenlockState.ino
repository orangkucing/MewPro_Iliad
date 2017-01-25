const char timelapse_rate_table[] PROGMEM = {1, 2, 4, 10, 20, 60, 120}; // unit in 0.5 seconds
const int exposure_time_table[] PROGMEM = {19, 20, 50, 100, 150, 200, 300}; // unit in 0.1 second
const int nightlapse_rate_table[] PROGMEM = {20, 30, 40, 60, 120, 240, 600, 3600, 7200, 0, 8, 10}; // unit in 0.5 seconds

unsigned long command_sent;

void checkGenlockState_Video()
{
  switch (recording_state) {
    case STATE_IDLE:
      break;
    case STATE_START:
      command_sent = millis();
      recording_state = STATE_SYNC_ON;
      break;
    case STATE_SYNC_ON:
      if (millis() - command_sent > 2000) {
        SERIAL.print(F("genlock signal start: (resolution, fps) = (0x0"));
        SERIAL.print(setting.p.video.resolution, HEX);
        SERIAL.print(F(", 0x0"));
        SERIAL.print(setting.p.video.fps, HEX);
        SERIAL.println(F(")"));
        switch (setting.p.video.fov) {
          case 0: // WIDE
            StartSyncSignal(setting.p.video.resolution * FPS_TABLE_SIZE + setting.p.video.fps);
            break;
          case 1: // MEDIUM
            switch (setting.p.video.resolution) {
              case 4: // 2.7K 16:9
                StartSyncSignal(SYNC_TIME_2_7K_MEDIUM * FPS_TABLE_SIZE + setting.p.video.fps);
                break;
              case 9: // 1080p
                StartSyncSignal(SYNC_TIME_1080_MEDIUM * FPS_TABLE_SIZE + setting.p.video.fps);
                break;            
              case 12: // 720p
                StartSyncSignal(SYNC_TIME_720_MEDIUM * FPS_TABLE_SIZE + setting.p.video.fps);
                break;
            }
            break;
          case 2: // NARROW
            switch (setting.p.video.resolution) {
              case 9: // 1080p
                StartSyncSignal(SYNC_TIME_1080_NARROW * FPS_TABLE_SIZE + setting.p.video.fps);
                break;            
              case 12: // 720p
                StartSyncSignal(SYNC_TIME_720_NARROW * FPS_TABLE_SIZE + setting.p.video.fps);
                break;
            }
            break;
        }
        recording_state = STATE_RECORDING;
        updateLCD();
      }
      break;
    case STATE_RECORDING:
      break;
    case STATE_STOP:
      command_sent = millis();
      recording_state = STATE_SYNC_OFF;
      break;
    case STATE_SYNC_OFF: 
      if (millis() - command_sent > 2500) {
        SERIAL.println(F("genlock signal stop"));
        StopSyncSignal();
        recording_state = STATE_IDLE;
        updateLCD();
      }
      break;
  }
}

void checkGenlockState_Photo()
{
  switch (recording_state) {
    case STATE_IDLE:
      break;
    case STATE_START:
      command_sent = millis();
      recording_state = STATE_SYNC_ON;
      break;
    case STATE_SYNC_ON: 
      if (millis() - command_sent > 1000) {
        SERIAL.print(F("genlock signal start: resolution = 0x0"));
        SERIAL.println(setting.p.photo.resolution, HEX);
        StartSyncSignal(SYNC_TIME_PHOTO * FPS_TABLE_SIZE); // photo mode is stored at the end of the video mode table
        recording_state = STATE_RECORDING;
      }
      break;
    case STATE_RECORDING:
      switch (setting.p.current_submode[MODE_PHOTO]) {
        case 0: // single
          if (millis() - command_sent > 1900) {
            recording_state = STATE_SYNC_OFF;
          }
          break;
        case 1: // continuous
          break;
        case 2: // night
          if (millis() -command_sent > (unsigned long)(pgm_read_word(exposure_time_table[setting.p.multi_shot.exposure_time]) * 100UL) + 1000) {
            recording_state = STATE_SYNC_OFF;
          }
          break;
      }
      break;
    case STATE_STOP:
      command_sent = millis();
      recording_state = STATE_SYNC_OFF;
      break;
    case STATE_SYNC_OFF: 
      SERIAL.println(F("genlock signal stop"));
      StopSyncSignal();
      recording_state = STATE_IDLE;
      updateLCD();
      break;
  }
}

void checkGenlockState_Burst()
{
  switch (recording_state) {
    case STATE_IDLE:
      break;
    case STATE_START:
      command_sent = millis();
      recording_state = STATE_SYNC_ON;
      break;
    case STATE_SYNC_ON: 
      if (millis() - command_sent > 1000) {
        SERIAL.print(F("genlock signal start: resolution = 0x0"));
        SERIAL.println(setting.p.photo.resolution, HEX);
        StartSyncSignal(SYNC_TIME_PHOTO * FPS_TABLE_SIZE); // photo mode is stored at the end of the video mode table
        recording_state = STATE_RECORDING;
      }
      break;
    case STATE_RECORDING:
      if (millis() - command_sent > 5000) {
        recording_state = STATE_SYNC_OFF;
      }
      break;
    case STATE_SYNC_OFF: 
      SERIAL.println(F("genlock signal stop"));
      StopSyncSignal();
      recording_state = STATE_IDLE;
      updateLCD();
      break;
  }
}

void checkGenlockState_Timelapse()
{
  switch (recording_state) {
    case STATE_IDLE:
      break;
    case STATE_START:
      delay(1000);
      StartTimerInterrupt((int)pgm_read_byte(timelapse_rate_table[setting.p.multi_shot.timelapse_rate]));
      command_sent = millis();
      recording_state = STATE_SYNC_ON;
      break;
    case STATE_SYNC_ON: 
      if (millis() - command_sent > 200) {
        SERIAL.print(F("genlock signal start: resolution = 0x0"));
        SERIAL.println(setting.p.photo.resolution, HEX);
        StartSyncSignal(SYNC_TIME_PHOTO * FPS_TABLE_SIZE); // photo mode is stored at the end of the video mode table
        recording_state = STATE_RECORDING;
      }
    case STATE_RECORDING:
      if (millis() - command_sent > 280) {
        recording_state = STATE_SYNC_OFF;
      }
      break;
    case STATE_SYNC_OFF: 
      SERIAL.println(F("genlock signal stop"));
      StopSyncSignal();
      recording_state = STATE_PAUSE;
      break;
    case STATE_PAUSE:
      break;
    case STATE_RESTART:
      command_sent = millis();
      {
        char tmp[] = "YY00041C0000\n";
        int i = 0;
        while (tmp[i]) {
          WRITE_CHAR(tmp[i++]);
        }
      }
      recording_state = STATE_SYNC_ON;
      break;
    case STATE_STOP:
      SERIAL.println(F("genlock signal stop"));
      StopSyncSignal();
      recording_state = STATE_END;
      break;
    case STATE_END:
      StopTimerInterrupt();
      recording_state = STATE_IDLE;
      updateLCD();
      break;
  }
}

void checkGenlockState_Nightlapse()
{
  unsigned long exposure = (unsigned long)pgm_read_word(exposure_time_table[setting.p.multi_shot.exposure_time]) * 100;
  
  switch (recording_state) {
    case STATE_IDLE:
      break;
    case STATE_START:
      delay(1000);
      StartTimerInterrupt((int)pgm_read_word(nightlapse_rate_table[setting.p.multi_shot.timelapse_rate]));
      command_sent = millis();
      recording_state = STATE_SYNC_ON;
      break;
    case STATE_SYNC_ON: 
      if (millis() - command_sent > 200) {
        SERIAL.print(F("genlock signal start: resolution = 0x0"));
        SERIAL.println(setting.p.photo.resolution, HEX);
        StartSyncSignal(SYNC_TIME_PHOTO * FPS_TABLE_SIZE); // photo mode is stored at the end of the video mode table
        recording_state = STATE_RECORDING;
      }
    case STATE_RECORDING:
      if (millis() - command_sent > exposure + 1500) {
        recording_state = STATE_SYNC_OFF;
      }
      break;
    case STATE_SYNC_OFF: 
      SERIAL.println(F("genlock signal stop"));
      StopSyncSignal();
      recording_state = STATE_PAUSE;
      break;
    case STATE_PAUSE:
      break;
    case STATE_RESTART:
      command_sent = millis();
      {
        char tmp[] = "YY00041C0000\n";
        int i = 0;
        while (tmp[i]) {
          WRITE_CHAR(tmp[i++]);
        }
      }
      recording_state = STATE_SYNC_ON;
      break;
    case STATE_STOP:
      SERIAL.println(F("genlock signal stop"));
      StopSyncSignal();
      recording_state = STATE_END;
      break;
    case STATE_END:
      StopTimerInterrupt();
      recording_state = STATE_IDLE;
      updateLCD();
      break;
  }
}

void checkGenlockState()
{
  switch (setting.p.mode) {
    case MODE_VIDEO:
      checkGenlockState_Video();
      break;
    case MODE_PHOTO:
      checkGenlockState_Photo();
      break;
    case MODE_MULTI_SHOT:
      switch (setting.p.current_submode[MODE_MULTI_SHOT]) {
        case 0:
          checkGenlockState_Burst();
          break;
        case 1:
          checkGenlockState_Timelapse();
          break;
        case 2:
          checkGenlockState_Nightlapse();
          break;
      }
      break;
  }
}
