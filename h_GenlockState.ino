void checkGenlockState()
{
  static unsigned long command_sent;
  switch (recording_state) {
    case 0:
    case 3:
      break;
    case 1:
    case 4:
      command_sent = millis();
      recording_state++;
      break;
    case 2: 
      switch (setting.p.mode) {
        case MODE_VIDEO:
          if (millis() - command_sent > 1500) {
            Serial.print(F("genlock signal start: (resolution, fps) = ("));
            Serial.print(setting.p.video.resolution, HEX);
            Serial.print(F(", "));
            Serial.print(setting.p.video.fps, HEX);
            Serial.println(F(")"));
            StartSyncSignal(setting.p.video.resolution * FPS_TABLE_SIZE + setting.p.video.fps);
            recording_state = 3;
          }
          break;
      } 
      break;
    case 5: 
      switch (setting.p.mode) {
        case MODE_VIDEO:
          if (millis() - command_sent > 1500) {
            Serial.println(F("genlock signal stop"));
            StopSyncSignal();
            recording_state = 0;
          }
          break;
      } 
      break;
  }
}

