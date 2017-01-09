void checkGenlockState()
{
  static unsigned long command_sent;
  switch (recording_state) {
    case STATE_IDLE:
      break;
    case STATE_RECORDING:
      switch (setting.p.mode) {
        case MODE_VIDEO:
          break;
        case MODE_PHOTO:
          if (setting.p.current_submode[MODE_PHOTO] != 1 /* not continuous */ && millis() - command_sent > 3500) {
            recording_state = STATE_SYNC_OFF;
          }
          break;
        case MODE_MULTI_SHOT:
          if (setting.p.current_submode[MODE_MULTI_SHOT] == 0 /* burst */ && millis() - command_sent > 5000) {
            recording_state = STATE_SYNC_OFF;
          }
          break;
      }
      break;
    case STATE_START:
    case STATE_STOP:
      command_sent = millis();
      recording_state++;
      break;
    case STATE_SYNC_ON: 
      switch (setting.p.mode) {
        case MODE_VIDEO:
          if (millis() - command_sent > 2500) {
            SERIAL.print(F("genlock signal start: (resolution, fps) = (0x0"));
            SERIAL.print(setting.p.video.resolution, HEX);
            SERIAL.print(F(", 0x0"));
            SERIAL.print(setting.p.video.fps, HEX);
            SERIAL.println(F(")"));
            StartSyncSignal(setting.p.video.resolution * FPS_TABLE_SIZE + setting.p.video.fps);
            recording_state = STATE_RECORDING;
            updateLCD();
          }
          break;
        case MODE_PHOTO:
        case MODE_MULTI_SHOT:
          if (millis() - command_sent > 2500) {
            SERIAL.print(F("genlock signal start: resolution = 0x0"));
            SERIAL.println(setting.p.photo.resolution, HEX);
            StartSyncSignal(14 * FPS_TABLE_SIZE); // photo mode is stored at the end of the video mode table
            recording_state = STATE_RECORDING;
          }
          break;
      }
      break;
    case STATE_END: // Hero 3+B compatibility
      recording_state = STATE_SYNC_OFF;
      // fall down
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

