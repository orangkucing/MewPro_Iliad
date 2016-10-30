void __emptyInputBuffer()
{
  while (SERIAL.available()) {
    if (SERIAL.read() == '\n') {
      return;
    }
  }
  fifo_readindex = fifo_writeindex = 0;
}

void checkTerminalCommands()
{
  while (SERIAL.available() || fifo_readindex != fifo_writeindex) {
    static boolean shiftable;
    char c;

    if (SERIAL.available()) {
      c = SERIAL.read();
    } else {
      c = command_buf[fifo_readindex];
      ++fifo_readindex %= MEWPRO_BUFFER_LENGTH;
    }
    BROADCAST.write(c);
    SERIAL.print(c);
    
    switch (c) {
      case ' ':
        shiftable = false;
        continue;
      case '\r':
      case '\n':
        if (bufp != 6) {
          buf[0] = bufp - 1;
          buf[1] = 5; buf[2] = 2;
          buf[3] = bufp - 4;
          buf[4] = buf[6]; buf[5] = buf[7];
          buf[6] = ++session;
          buf[7] = buf[4] == 'Y' ? 6 : 4;
          bufp = 6;
          parseSerialWrite();
          updateLCD();
        }
        return;
      case '@':
        bufp = 6;
        session = 0xFF;
        SERIAL.println(F("\ncamera power on"));
        __emptyInputBuffer();
        startupSession = 0; // emit power on sequence
        disp_state = MENU_MAIN;
        setting.p.mode = setting.p.setup.default_app_mode;
        updateLCD();
        return; 
      default:
        if (bufp >= 8 && isxdigit(c)) {
          c -= '0';
          if (c >= 10) {
            c = (c & 0x0f) + 9;
          }    
        }
        if (bufp < 9) {
          shiftable = true;
          buf[bufp++] = c;
        } else {
          if (shiftable) {
            buf[bufp-1] = (buf[bufp-1] << 4) + c;
          } else {
            buf[bufp++] = c;
          }
          shiftable = !shiftable;      
        }
        break;
    }
  }
}

