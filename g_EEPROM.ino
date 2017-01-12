#define EEPROM_ID_LEN 32
#define IR_REMOTE_LEN 32
#define IDSTRING "MewPro 4  "

void ROM_Read()
{
  int base, i, j;
  byte *addr;
  boolean f = true;
  // signature check
  char tmp[EEPROM_ID_LEN + 1] = IDSTRING ":" __VERSION_STRING__;
  
  for (i = 0; i < EEPROM_ID_LEN; i++) {
     f &= (EEPROM.read(i) == tmp[i]);
  }
  if (!f) {
    SERIAL.println("factory reset");
    base = 0;
    for (i = 0; i < EEPROM_ID_LEN; i++) {
      EEPROM.write(i, tmp[i]);
    }
    ROM_write();
    // factory reset doesn't override IR remote settings
    // because these values are garbage initially.
  }
  base = EEPROM_ID_LEN;
  addr = (byte *)IRkey.l;
  for (i = 0; i < sizeof(IRkey); i++) {
    *(addr + i) = EEPROM.read(i + base);
  }
  base += IR_REMOTE_LEN;
  for (i = 0; i < SETUP_LEN; i++) {
    setting.b[i] = EEPROM.read(i + base);
  }
  for (j = 0; j < MAX_SUBMODE_SIZE; j++) {
    base += SETUP_LEN;
    for (i = 0; i < SETUP_LEN; i++) {
      storage[j].b[i] = EEPROM.read(i + base);
    }
  }
  setting.p.mode = setting.p.setup.default_app_mode;
  setting.p.current_submode[MODE_VIDEO] = setting.p.video.default_sub_mode;
  setting.p.current_submode[MODE_PHOTO] = setting.p.photo.default_sub_mode;
  setting.p.current_submode[MODE_MULTI_SHOT] = setting.p.multi_shot.default_sub_mode;
  loadSetupValue();
}

void ROM_write()
{
  int i, j;
  int base = EEPROM_ID_LEN + IR_REMOTE_LEN;
  for (i = 0; i < SETUP_LEN; i++) {
    EEPROM.write(i + base, setting.b[i]);
  }
  for (j = 0; j < MAX_SUBMODE_SIZE; j++) {
    base += SETUP_LEN;
    for (i = 0; i < SETUP_LEN; i++) {
      EEPROM.write(i + base, storage[j].b[i]);
    }
  }
}

