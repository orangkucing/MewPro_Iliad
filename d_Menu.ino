void loadSetupValue()
{
  char current_submode;
  if (setting.p.mode != MODE_SETUP) {
    current_submode = setting.p.current_submode[setting.p.mode];
    memcpy(&setting.p.video, &storage[current_submode].p.video, sizeof(setting.p.video));
    memcpy(&setting.p.photo, &storage[current_submode].p.photo, sizeof(setting.p.photo));
    memcpy(&setting.p.multi_shot, &storage[current_submode].p.multi_shot, sizeof(setting.p.multi_shot));
    memcpy(&setting.p.v4, &storage[current_submode].p.v4, sizeof(setting.p.v4));
  }
}

void storeDefaultSubMode(char mode, char submode)
{
  switch (mode) {
    case MODE_VIDEO:
      setting.p.video.default_sub_mode = submode;
      for (int i = 0; i < 4; i++) {
        storage[i].p.video.default_sub_mode = submode;
      }
      break;
    case MODE_PHOTO:
      setting.p.photo.default_sub_mode = submode;
      for (int i = 0; i < 3; i++) {
        storage[i].p.photo.default_sub_mode = submode;
      }
      break;
    case MODE_MULTI_SHOT:
      setting.p.multi_shot.default_sub_mode = submode;
      for (int i = 0; i < 3; i++) {
        storage[i].p.multi_shot.default_sub_mode = submode;
      }
      break;
  }
}

void storeSetupValue()
{
  if (setting.p.mode != MODE_SETUP) {
    char current_submode = setting.p.current_submode[setting.p.mode];
    memcpy(&storage[current_submode].p.video, &setting.p.video, sizeof(setting.p.video));
    memcpy(&storage[current_submode].p.photo, &setting.p.photo, sizeof(setting.p.photo));
    memcpy(&storage[current_submode].p.multi_shot, &setting.p.multi_shot, sizeof(setting.p.multi_shot));
    memcpy(&storage[current_submode].p.v4, &setting.p.v4, sizeof(setting.p.v4));
  }
  storeDefaultSubMode(MODE_VIDEO, setting.p.video.default_sub_mode);
  storeDefaultSubMode(MODE_PHOTO, setting.p.photo.default_sub_mode);
  storeDefaultSubMode(MODE_MULTI_SHOT, setting.p.multi_shot.default_sub_mode);
}

void initWidget()
{
  if (setting.p.mode != MODE_SETUP) {
    setup_id = &setting.p.current_submode[setting.p.mode] - setting.b;
  } else {
    setup_id = &setting.p.setup.wireless_mode - setting.b;
  }
}

boolean nextWidget()
{
  char *display_hint, **addr, *txt;
  int i = 0;
  char val, id;
  switch (setting.p.mode) {
    case MODE_VIDEO: // video
      display_hint = GPCAMERA_GROUP_VIDEO;
      break;
    case MODE_PHOTO:
      display_hint = GPCAMERA_GROUP_PHOTO;
      break;
    case MODE_MULTI_SHOT:
      display_hint = GPCAMERA_GROUP_MULTI_SHOT;
      break;
    case MODE_SETUP:
      display_hint = GPCAMERA_GROUP_SETUP;
      break;
  }
  do {
    id = (char)pgm_read_byte(display_hint + i);
    if (id == 0) {
      // current setup_id is not listed in display_hint
      // let's start over
      i = -1;
      break;
    }
    if (id == setup_id) {
      break;
    }
    i++;
  } while (1);
  do {
    i++;
    id = (char)pgm_read_byte(display_hint + i);
    if (id == 0) {
      // no next widget
      return false;
    }
    loadSetupValue();
    addr = (char **)pgm_read_word(&widgets[id].option_txt);
    while ((txt = (char *)pgm_read_word(addr++)) != NULL) {
      val = (char)pgm_read_byte(txt);
      if (!blacklist(id, val)) {
        if (blacklist(id, setting.b[id])) {
          // current value is blacklisted
          setting.b[id] = val;
          if (&setting.b[id] < &setting.p.reserved0 || &setting.b[id] >= &setting.p.v4) {
            storeSetupValue();
          }
        }
        setup_id = id;
        return true;
      }
    }
  } while (1);
}

void setNextValue()
{
  char **addr, *txt, c;
  loadSetupValue();
  addr = (char **)pgm_read_word(&widgets[setup_id].option_txt);
  do {
    txt = (char *)pgm_read_word(addr);
    if (txt == NULL)
      return;
    if ((char)pgm_read_byte(txt) == setting.b[setup_id]) {
      break;
    }
    addr++;
  } while (1);
  do {
    addr++;
    txt = (char *)pgm_read_word(addr);
    if (txt == NULL) {
      addr = (char **)pgm_read_word(&widgets[setup_id].option_txt);
      txt = (char *)pgm_read_word(addr);
      if (txt == NULL) return;
    }
    c = (char)pgm_read_byte(txt);
    if (c == setting.b[setup_id]) {
      return;
    }
    if (!blacklist(setup_id, c)) {
      setting.b[setup_id] = c;
      if (&setting.b[setup_id] < &setting.p.reserved0 || &setting.b[setup_id] >= &setting.p.v4) {
        storeSetupValue();
      }
      return;
    }
  } while (1);
}
