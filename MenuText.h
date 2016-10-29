const char MODE_VIDEO = 0;
const char MODE_PHOTO = 1;
const char MODE_MULTI_SHOT = 2;
const char MODE_PLAYBACK = 4;
const char MODE_SETUP = 5;
const char MODE_AUDIO = 6;

const char GPCAMERA_GROUP_VIDEO[] PROGMEM = { 5, 6, 7, 2, 3, 4, 8, 9, 10, 11, 12, 73, 13, 74, 14, 15, 0 };
const char GPCAMERA_GROUP_PHOTO[] PROGMEM = { 18, 19, 17, 20, 21, 22, 23, 75, 24, 25, 26, 0 };
const char GPCAMERA_GROUP_MULTI_SHOT[] PROGMEM = { 31, 29, 30, 32, 28, 33, 34, 35, 36, 76, 37, 38, 39, 0 };
const char GPCAMERA_GROUP_SETUP[] PROGMEM = { 52, 53, 1, 16, 27, 54, 55, 56, 57, 58, 59, 0 };
const char GPCAMERA_GROUP_DELETE_ID[] PROGMEM = { 0 };
const char GPCAMERA_GROUP_CAMERA_INFO[] PROGMEM = { 0 };
const char GPCAMERA_GROUP_WIRELESS_CONTROLS[] PROGMEM = { 0 };
const char GPCAMERA_GROUP_CAMERA_STATUS[] PROGMEM = { 0 };

//
const char title_txt_0_0[] PROGMEM = "\x01""Default Sub Mode";
const char option_txt_0_0_0[] PROGMEM = "\x00""Video";
const char option_txt_0_0_1[] PROGMEM = "\x01""Time Lapse Video";
const char option_txt_0_0_2[] PROGMEM = "\x02""Video + Photo";
const char option_txt_0_0_3[] PROGMEM = "\x03""Looping";
const char* const option_txt_0_0[] PROGMEM = {
option_txt_0_0_0, option_txt_0_0_1, option_txt_0_0_2, option_txt_0_0_3, NULL
};

const char title_txt_0_1[] PROGMEM = "\x44""Sub Mode";
const char option_txt_0_1_0[] PROGMEM = "\x00""Video";
const char option_txt_0_1_1[] PROGMEM = "\x01""Time Lapse Video";
const char option_txt_0_1_2[] PROGMEM = "\x02""Video + Photo";
const char option_txt_0_1_3[] PROGMEM = "\x03""Looping";
const char* const option_txt_0_1[] PROGMEM = {
option_txt_0_1_0, option_txt_0_1_1, option_txt_0_1_2, option_txt_0_1_3, NULL
};

const char title_txt_0_2[] PROGMEM = "\x02""Resolution";
const char option_txt_0_2_0[] PROGMEM = "\x02""4K SuperView";
const char option_txt_0_2_1[] PROGMEM = "\x01""4K";
const char option_txt_0_2_2[] PROGMEM = "\x05""2.7K SuperView";
const char option_txt_0_2_3[] PROGMEM = "\x04""2.7K";
const char option_txt_0_2_4[] PROGMEM = "\x06""2.7K 4:3";
const char option_txt_0_2_5[] PROGMEM = "\x07""1440";
const char option_txt_0_2_6[] PROGMEM = "\x08""1080 SuperView";
const char option_txt_0_2_7[] PROGMEM = "\x09""1080";
const char option_txt_0_2_8[] PROGMEM = "\x0a""960";
const char option_txt_0_2_9[] PROGMEM = "\x0b""720 SuperView";
const char option_txt_0_2_10[] PROGMEM = "\x0c""720";
const char option_txt_0_2_11[] PROGMEM = "\x0d""WVGA";
const char* const option_txt_0_2[] PROGMEM = {
option_txt_0_2_0, option_txt_0_2_1, option_txt_0_2_2, option_txt_0_2_3, option_txt_0_2_4, option_txt_0_2_5, option_txt_0_2_6, option_txt_0_2_7, option_txt_0_2_8, option_txt_0_2_9, option_txt_0_2_10, option_txt_0_2_11, NULL
};

const char title_txt_0_3[] PROGMEM = "\x03""FPS";
const char option_txt_0_3_0[] PROGMEM = "\x00""240";
const char option_txt_0_3_1[] PROGMEM = "\x01""120";
const char option_txt_0_3_2[] PROGMEM = "\x02""100";
const char option_txt_0_3_3[] PROGMEM = "\x03""90";
const char option_txt_0_3_4[] PROGMEM = "\x04""80";
const char option_txt_0_3_5[] PROGMEM = "\x05""60";
const char option_txt_0_3_6[] PROGMEM = "\x06""50";
const char option_txt_0_3_7[] PROGMEM = "\x07""48";
const char option_txt_0_3_8[] PROGMEM = "\x08""30";
const char option_txt_0_3_9[] PROGMEM = "\x09""25";
const char option_txt_0_3_10[] PROGMEM = "\x0a""24";
const char option_txt_0_3_11[] PROGMEM = "\x0b""15";
const char option_txt_0_3_12[] PROGMEM = "\x0c""12.5";
const char* const option_txt_0_3[] PROGMEM = {
option_txt_0_3_0, option_txt_0_3_1, option_txt_0_3_2, option_txt_0_3_3, option_txt_0_3_4, option_txt_0_3_5, option_txt_0_3_6, option_txt_0_3_7, option_txt_0_3_8, option_txt_0_3_9, option_txt_0_3_10, option_txt_0_3_11, option_txt_0_3_12, NULL
};

const char title_txt_0_4[] PROGMEM = "\x04""Field of View";
const char option_txt_0_4_0[] PROGMEM = "\x00""Wide";
const char option_txt_0_4_1[] PROGMEM = "\x01""Medium";
const char option_txt_0_4_2[] PROGMEM = "\x02""Narrow";
const char* const option_txt_0_4[] PROGMEM = {
option_txt_0_4_0, option_txt_0_4_1, option_txt_0_4_2, NULL
};

const char title_txt_0_5[] PROGMEM = "\x05""Interval";
const char option_txt_0_5_0[] PROGMEM = "\x00""0.5 Seconds";
const char option_txt_0_5_1[] PROGMEM = "\x01""1 Second";
const char option_txt_0_5_2[] PROGMEM = "\x02""2 Seconds";
const char option_txt_0_5_3[] PROGMEM = "\x03""5 Seconds";
const char option_txt_0_5_4[] PROGMEM = "\x04""10 Seconds";
const char option_txt_0_5_5[] PROGMEM = "\x05""30 Seconds";
const char option_txt_0_5_6[] PROGMEM = "\x06""60 Seconds";
const char* const option_txt_0_5[] PROGMEM = {
option_txt_0_5_0, option_txt_0_5_1, option_txt_0_5_2, option_txt_0_5_3, option_txt_0_5_4, option_txt_0_5_5, option_txt_0_5_6, NULL
};

const char title_txt_0_6[] PROGMEM = "\x06""Interval";
const char option_txt_0_6_0[] PROGMEM = "\x00""Max";
const char option_txt_0_6_1[] PROGMEM = "\x01""5 Minutes";
const char option_txt_0_6_2[] PROGMEM = "\x02""20 Minutes";
const char option_txt_0_6_3[] PROGMEM = "\x03""60 Minutes";
const char option_txt_0_6_4[] PROGMEM = "\x04""120 Minutes";
const char* const option_txt_0_6[] PROGMEM = {
option_txt_0_6_0, option_txt_0_6_1, option_txt_0_6_2, option_txt_0_6_3, option_txt_0_6_4, NULL
};

const char title_txt_0_7[] PROGMEM = "\x07""Interval";
const char option_txt_0_7_0[] PROGMEM = "\x01""1 P / 5 Seconds";
const char option_txt_0_7_1[] PROGMEM = "\x02""1 P / 10 Seconds";
const char option_txt_0_7_2[] PROGMEM = "\x03""1 P / 30 Seconds";
const char option_txt_0_7_3[] PROGMEM = "\x04""1 P / 60 Seconds";
const char* const option_txt_0_7[] PROGMEM = {
option_txt_0_7_0, option_txt_0_7_1, option_txt_0_7_2, option_txt_0_7_3, NULL
};

const char title_txt_0_8[] PROGMEM = "\x08""Low Light";
const char option_txt_0_8_0[] PROGMEM = "\x01""ON";
const char option_txt_0_8_1[] PROGMEM = "\x00""OFF";
const char* const option_txt_0_8[] PROGMEM = {
option_txt_0_8_0, option_txt_0_8_1, NULL
};

const char title_txt_0_9[] PROGMEM = "\x09""Spot Meter";
const char option_txt_0_9_0[] PROGMEM = "\x01""ON";
const char option_txt_0_9_1[] PROGMEM = "\x00""OFF";
const char* const option_txt_0_9[] PROGMEM = {
option_txt_0_9_0, option_txt_0_9_1, NULL
};

const char title_txt_0_10[] PROGMEM = "\x0a""Protune";
const char option_txt_0_10_0[] PROGMEM = "\x01""ON";
const char option_txt_0_10_1[] PROGMEM = "\x00""OFF";
const char* const option_txt_0_10[] PROGMEM = {
option_txt_0_10_0, option_txt_0_10_1, NULL
};

const char title_txt_0_11[] PROGMEM = "\x0b""White Balance";
const char option_txt_0_11_0[] PROGMEM = "\x00""Auto";
const char option_txt_0_11_1[] PROGMEM = "\x01""3000K";
const char option_txt_0_11_2[] PROGMEM = "\x05""4000K";
const char option_txt_0_11_3[] PROGMEM = "\x06""4800K";
const char option_txt_0_11_4[] PROGMEM = "\x02""5500K";
const char option_txt_0_11_5[] PROGMEM = "\x07""6000K";
const char option_txt_0_11_6[] PROGMEM = "\x03""6500K";
const char option_txt_0_11_7[] PROGMEM = "\x04""Native";
const char* const option_txt_0_11[] PROGMEM = {
option_txt_0_11_0, option_txt_0_11_1, option_txt_0_11_2, option_txt_0_11_3, option_txt_0_11_4, option_txt_0_11_5, option_txt_0_11_6, option_txt_0_11_7, NULL
};

const char title_txt_0_12[] PROGMEM = "\x0c""Color";
const char option_txt_0_12_0[] PROGMEM = "\x00""GoPro Color";
const char option_txt_0_12_1[] PROGMEM = "\x01""Flat";
const char* const option_txt_0_12[] PROGMEM = {
option_txt_0_12_0, option_txt_0_12_1, NULL
};

const char title_txt_0_13[] PROGMEM = "\x0e""Sharpness";
const char option_txt_0_13_0[] PROGMEM = "\x00""High";
const char option_txt_0_13_1[] PROGMEM = "\x01""Medium";
const char option_txt_0_13_2[] PROGMEM = "\x02""Low";
const char* const option_txt_0_13[] PROGMEM = {
option_txt_0_13_0, option_txt_0_13_1, option_txt_0_13_2, NULL
};

const char title_txt_0_14[] PROGMEM = "\x0f""EV Comp";
const char option_txt_0_14_0[] PROGMEM = "\x08""-2.0";
const char option_txt_0_14_1[] PROGMEM = "\x07""-1.5";
const char option_txt_0_14_2[] PROGMEM = "\x06""-1.0";
const char option_txt_0_14_3[] PROGMEM = "\x05""-0.5";
const char option_txt_0_14_4[] PROGMEM = "\x04""0";
const char option_txt_0_14_5[] PROGMEM = "\x03""+0.5";
const char option_txt_0_14_6[] PROGMEM = "\x02""+1.0";
const char option_txt_0_14_7[] PROGMEM = "\x01""+1.5";
const char option_txt_0_14_8[] PROGMEM = "\x00""+2.0";
const char* const option_txt_0_14[] PROGMEM = {
option_txt_0_14_0, option_txt_0_14_1, option_txt_0_14_2, option_txt_0_14_3, option_txt_0_14_4, option_txt_0_14_5, option_txt_0_14_6, option_txt_0_14_7, option_txt_0_14_8, NULL
};

const char title_txt_0_15[] PROGMEM = "\x49""Manual Exposure";
const char option_txt_0_15_0[] PROGMEM = "\x00""Auto";
const char option_txt_0_15_1[] PROGMEM = "\x01""1/12.5";
const char option_txt_0_15_2[] PROGMEM = "\x02""1/15";
const char option_txt_0_15_3[] PROGMEM = "\x03""1/24";
const char option_txt_0_15_4[] PROGMEM = "\x04""1/25";
const char option_txt_0_15_5[] PROGMEM = "\x05""1/30";
const char option_txt_0_15_6[] PROGMEM = "\x06""1/48";
const char option_txt_0_15_7[] PROGMEM = "\x07""1/50";
const char option_txt_0_15_8[] PROGMEM = "\x08""1/60";
const char option_txt_0_15_9[] PROGMEM = "\x09""1/80";
const char option_txt_0_15_10[] PROGMEM = "\x0a""1/90";
const char option_txt_0_15_11[] PROGMEM = "\x0b""1/96";
const char option_txt_0_15_12[] PROGMEM = "\x0c""1/100";
const char option_txt_0_15_13[] PROGMEM = "\x0d""1/120";
const char option_txt_0_15_14[] PROGMEM = "\x0e""1/160";
const char option_txt_0_15_15[] PROGMEM = "\x0f""1/180";
const char option_txt_0_15_16[] PROGMEM = "\x10""1/192";
const char option_txt_0_15_17[] PROGMEM = "\x11""1/200";
const char option_txt_0_15_18[] PROGMEM = "\x12""1/240";
const char option_txt_0_15_19[] PROGMEM = "\x13""1/320";
const char option_txt_0_15_20[] PROGMEM = "\x14""1/360";
const char option_txt_0_15_21[] PROGMEM = "\x15""1/400";
const char option_txt_0_15_22[] PROGMEM = "\x16""1/480";
const char option_txt_0_15_23[] PROGMEM = "\x17""1/960";
const char* const option_txt_0_15[] PROGMEM = {
option_txt_0_15_0, option_txt_0_15_1, option_txt_0_15_2, option_txt_0_15_3, option_txt_0_15_4, option_txt_0_15_5, option_txt_0_15_6, option_txt_0_15_7, option_txt_0_15_8, option_txt_0_15_9, option_txt_0_15_10, option_txt_0_15_11, option_txt_0_15_12, option_txt_0_15_13, option_txt_0_15_14, option_txt_0_15_15, option_txt_0_15_16, option_txt_0_15_17, option_txt_0_15_18, option_txt_0_15_19, option_txt_0_15_20, option_txt_0_15_21, option_txt_0_15_22, option_txt_0_15_23, NULL
};

const char title_txt_0_16[] PROGMEM = "\x0d""ISO Limit";
const char option_txt_0_16_0[] PROGMEM = "\x00""6400";
const char option_txt_0_16_1[] PROGMEM = "\x03""3200";
const char option_txt_0_16_2[] PROGMEM = "\x01""1600";
const char option_txt_0_16_3[] PROGMEM = "\x04""800";
const char option_txt_0_16_4[] PROGMEM = "\x02""400";
const char option_txt_0_16_5[] PROGMEM = "\x07""200";
const char option_txt_0_16_6[] PROGMEM = "\x08""100";
const char* const option_txt_0_16[] PROGMEM = {
option_txt_0_16_0, option_txt_0_16_1, option_txt_0_16_2, option_txt_0_16_3, option_txt_0_16_4, option_txt_0_16_5, option_txt_0_16_6, NULL
};

const char title_txt_0_17[] PROGMEM = "\x4a""ISO Mode";
const char option_txt_0_17_0[] PROGMEM = "\x00""Max";
const char option_txt_0_17_1[] PROGMEM = "\x01""Lock";
const char* const option_txt_0_17[] PROGMEM = {
option_txt_0_17_0, option_txt_0_17_1, NULL
};

const char title_txt_0_18[] PROGMEM = "\x4e""EIS";
const char option_txt_0_18_0[] PROGMEM = "\x01""ON";
const char option_txt_0_18_1[] PROGMEM = "\x00""OFF";
const char* const option_txt_0_18[] PROGMEM = {
option_txt_0_18_0, option_txt_0_18_1, NULL
};


//
const char title_txt_1_0[] PROGMEM = "\x10""Default Sub Mode";
const char option_txt_1_0_0[] PROGMEM = "\x00""Single";
const char option_txt_1_0_1[] PROGMEM = "\x01""Continuous";
const char option_txt_1_0_2[] PROGMEM = "\x02""Night";
const char* const option_txt_1_0[] PROGMEM = {
option_txt_1_0_0, option_txt_1_0_1, option_txt_1_0_2, NULL
};

const char title_txt_1_1[] PROGMEM = "\x45""Sub Mode";
const char option_txt_1_1_0[] PROGMEM = "\x00""Single";
const char option_txt_1_1_1[] PROGMEM = "\x01""Continuous";
const char option_txt_1_1_2[] PROGMEM = "\x02""Night";
const char* const option_txt_1_1[] PROGMEM = {
option_txt_1_1_0, option_txt_1_1_1, option_txt_1_1_2, NULL
};

const char title_txt_1_2[] PROGMEM = "\x12""Continuous Rate";
const char option_txt_1_2_0[] PROGMEM = "\x00""3 Frames / Sec";
const char option_txt_1_2_1[] PROGMEM = "\x01""5 Frames / Sec";
const char option_txt_1_2_2[] PROGMEM = "\x02""10 Frames / Sec";
const char* const option_txt_1_2[] PROGMEM = {
option_txt_1_2_0, option_txt_1_2_1, option_txt_1_2_2, NULL
};

const char title_txt_1_3[] PROGMEM = "\x11""Megapixels";
const char option_txt_1_3_0[] PROGMEM = "\x00""12MP Wide";
const char option_txt_1_3_1[] PROGMEM = "\x01""7MP Wide";
const char option_txt_1_3_2[] PROGMEM = "\x02""7MP Med";
const char option_txt_1_3_3[] PROGMEM = "\x03""5MP Med";
const char* const option_txt_1_3[] PROGMEM = {
option_txt_1_3_0, option_txt_1_3_1, option_txt_1_3_2, option_txt_1_3_3, NULL
};

const char title_txt_1_4[] PROGMEM = "\x13""Shutter";
const char option_txt_1_4_0[] PROGMEM = "\x00""Auto";
const char option_txt_1_4_1[] PROGMEM = "\x01""2 Seconds";
const char option_txt_1_4_2[] PROGMEM = "\x02""5 Seconds";
const char option_txt_1_4_3[] PROGMEM = "\x03""10 Seconds";
const char option_txt_1_4_4[] PROGMEM = "\x04""15 Seconds";
const char option_txt_1_4_5[] PROGMEM = "\x05""20 Seconds";
const char option_txt_1_4_6[] PROGMEM = "\x06""30 Seconds";
const char* const option_txt_1_4[] PROGMEM = {
option_txt_1_4_0, option_txt_1_4_1, option_txt_1_4_2, option_txt_1_4_3, option_txt_1_4_4, option_txt_1_4_5, option_txt_1_4_6, NULL
};

const char title_txt_1_5[] PROGMEM = "\x14""Spot Meter";
const char option_txt_1_5_0[] PROGMEM = "\x01""ON";
const char option_txt_1_5_1[] PROGMEM = "\x00""OFF";
const char* const option_txt_1_5[] PROGMEM = {
option_txt_1_5_0, option_txt_1_5_1, NULL
};

const char title_txt_1_6[] PROGMEM = "\x4d""WDR";
const char option_txt_1_6_0[] PROGMEM = "\x01""ON";
const char option_txt_1_6_1[] PROGMEM = "\x00""OFF";
const char* const option_txt_1_6[] PROGMEM = {
option_txt_1_6_0, option_txt_1_6_1, NULL
};

const char title_txt_1_7[] PROGMEM = "\x52""RAW";
const char option_txt_1_7_0[] PROGMEM = "\x01""ON";
const char option_txt_1_7_1[] PROGMEM = "\x00""OFF";
const char* const option_txt_1_7[] PROGMEM = {
option_txt_1_7_0, option_txt_1_7_1, NULL
};

const char title_txt_1_8[] PROGMEM = "\x15""Protune";
const char option_txt_1_8_0[] PROGMEM = "\x01""ON";
const char option_txt_1_8_1[] PROGMEM = "\x00""OFF";
const char* const option_txt_1_8[] PROGMEM = {
option_txt_1_8_0, option_txt_1_8_1, NULL
};

const char title_txt_1_9[] PROGMEM = "\x16""White Balance";
const char option_txt_1_9_0[] PROGMEM = "\x00""Auto";
const char option_txt_1_9_1[] PROGMEM = "\x01""3000K";
const char option_txt_1_9_2[] PROGMEM = "\x05""4000K";
const char option_txt_1_9_3[] PROGMEM = "\x06""4800K";
const char option_txt_1_9_4[] PROGMEM = "\x02""5500K";
const char option_txt_1_9_5[] PROGMEM = "\x07""6000K";
const char option_txt_1_9_6[] PROGMEM = "\x03""6500K";
const char option_txt_1_9_7[] PROGMEM = "\x04""Native";
const char* const option_txt_1_9[] PROGMEM = {
option_txt_1_9_0, option_txt_1_9_1, option_txt_1_9_2, option_txt_1_9_3, option_txt_1_9_4, option_txt_1_9_5, option_txt_1_9_6, option_txt_1_9_7, NULL
};

const char title_txt_1_10[] PROGMEM = "\x17""Color";
const char option_txt_1_10_0[] PROGMEM = "\x00""GoPro Color";
const char option_txt_1_10_1[] PROGMEM = "\x01""Flat";
const char* const option_txt_1_10[] PROGMEM = {
option_txt_1_10_0, option_txt_1_10_1, NULL
};

const char title_txt_1_11[] PROGMEM = "\x19""Sharpness";
const char option_txt_1_11_0[] PROGMEM = "\x00""High";
const char option_txt_1_11_1[] PROGMEM = "\x01""Medium";
const char option_txt_1_11_2[] PROGMEM = "\x02""Low";
const char* const option_txt_1_11[] PROGMEM = {
option_txt_1_11_0, option_txt_1_11_1, option_txt_1_11_2, NULL
};

const char title_txt_1_12[] PROGMEM = "\x1a""EV Comp";
const char option_txt_1_12_0[] PROGMEM = "\x08""-2.0";
const char option_txt_1_12_1[] PROGMEM = "\x07""-1.5";
const char option_txt_1_12_2[] PROGMEM = "\x06""-1.0";
const char option_txt_1_12_3[] PROGMEM = "\x05""-0.5";
const char option_txt_1_12_4[] PROGMEM = "\x04""0";
const char option_txt_1_12_5[] PROGMEM = "\x03""+0.5";
const char option_txt_1_12_6[] PROGMEM = "\x02""+1.0";
const char option_txt_1_12_7[] PROGMEM = "\x01""+1.5";
const char option_txt_1_12_8[] PROGMEM = "\x00""+2.0";
const char* const option_txt_1_12[] PROGMEM = {
option_txt_1_12_0, option_txt_1_12_1, option_txt_1_12_2, option_txt_1_12_3, option_txt_1_12_4, option_txt_1_12_5, option_txt_1_12_6, option_txt_1_12_7, option_txt_1_12_8, NULL
};

const char title_txt_1_13[] PROGMEM = "\x4b""ISO Min";
const char option_txt_1_13_0[] PROGMEM = "\x00""800";
const char option_txt_1_13_1[] PROGMEM = "\x01""400";
const char option_txt_1_13_2[] PROGMEM = "\x02""200";
const char option_txt_1_13_3[] PROGMEM = "\x03""100";
const char* const option_txt_1_13[] PROGMEM = {
option_txt_1_13_0, option_txt_1_13_1, option_txt_1_13_2, option_txt_1_13_3, NULL
};

const char title_txt_1_14[] PROGMEM = "\x18""ISO Max";
const char option_txt_1_14_0[] PROGMEM = "\x00""800";
const char option_txt_1_14_1[] PROGMEM = "\x01""400";
const char option_txt_1_14_2[] PROGMEM = "\x02""200";
const char option_txt_1_14_3[] PROGMEM = "\x03""100";
const char* const option_txt_1_14[] PROGMEM = {
option_txt_1_14_0, option_txt_1_14_1, option_txt_1_14_2, option_txt_1_14_3, NULL
};


//
const char title_txt_2_0[] PROGMEM = "\x1b""Default Sub Mode";
const char option_txt_2_0_0[] PROGMEM = "\x00""Burst";
const char option_txt_2_0_1[] PROGMEM = "\x01""Time Lapse";
const char option_txt_2_0_2[] PROGMEM = "\x02""Night Lapse";
const char* const option_txt_2_0[] PROGMEM = {
option_txt_2_0_0, option_txt_2_0_1, option_txt_2_0_2, NULL
};

const char title_txt_2_1[] PROGMEM = "\x46""Sub Mode";
const char option_txt_2_1_0[] PROGMEM = "\x00""Burst";
const char option_txt_2_1_1[] PROGMEM = "\x01""Time Lapse";
const char option_txt_2_1_2[] PROGMEM = "\x02""Night Lapse";
const char* const option_txt_2_1[] PROGMEM = {
option_txt_2_1_0, option_txt_2_1_1, option_txt_2_1_2, NULL
};

const char title_txt_2_2[] PROGMEM = "\x1f""Shutter";
const char option_txt_2_2_0[] PROGMEM = "\x00""Auto";
const char option_txt_2_2_1[] PROGMEM = "\x01""2 Seconds";
const char option_txt_2_2_2[] PROGMEM = "\x02""5 Seconds";
const char option_txt_2_2_3[] PROGMEM = "\x03""10 Seconds";
const char option_txt_2_2_4[] PROGMEM = "\x04""15 Seconds";
const char option_txt_2_2_5[] PROGMEM = "\x05""20 Seconds";
const char option_txt_2_2_6[] PROGMEM = "\x06""30 Seconds";
const char* const option_txt_2_2[] PROGMEM = {
option_txt_2_2_0, option_txt_2_2_1, option_txt_2_2_2, option_txt_2_2_3, option_txt_2_2_4, option_txt_2_2_5, option_txt_2_2_6, NULL
};

const char title_txt_2_3[] PROGMEM = "\x1d""Rate";
const char option_txt_2_3_0[] PROGMEM = "\x00""3 P / 1 Sec";
const char option_txt_2_3_1[] PROGMEM = "\x01""5 P / 1 Sec";
const char option_txt_2_3_2[] PROGMEM = "\x02""10 P / 1 Sec";
const char option_txt_2_3_3[] PROGMEM = "\x03""10 P / 2 Sec";
const char option_txt_2_3_4[] PROGMEM = "\x04""10 P / 3 Sec";
const char option_txt_2_3_5[] PROGMEM = "\x05""30 P / 1 Sec";
const char option_txt_2_3_6[] PROGMEM = "\x06""30 P / 2 Sec";
const char option_txt_2_3_7[] PROGMEM = "\x07""30 P / 3 Sec";
const char option_txt_2_3_8[] PROGMEM = "\x08""30 P / 6 Sec";
const char* const option_txt_2_3[] PROGMEM = {
option_txt_2_3_0, option_txt_2_3_1, option_txt_2_3_2, option_txt_2_3_3, option_txt_2_3_4, option_txt_2_3_5, option_txt_2_3_6, option_txt_2_3_7, option_txt_2_3_8, NULL
};

const char title_txt_2_4[] PROGMEM = "\x1e""Interval";
const char option_txt_2_4_0[] PROGMEM = "\x00""1 P / 0.5 Sec";
const char option_txt_2_4_1[] PROGMEM = "\x01""1 P / 1 Sec";
const char option_txt_2_4_2[] PROGMEM = "\x02""1 P / 2 Sec";
const char option_txt_2_4_3[] PROGMEM = "\x05""1 P / 5 Sec";
const char option_txt_2_4_4[] PROGMEM = "\x0a""1 P / 10 Sec";
const char option_txt_2_4_5[] PROGMEM = "\x1e""1 P / 30 Sec";
const char option_txt_2_4_6[] PROGMEM = "\x3c""1 P / 60 Sec";
const char* const option_txt_2_4[] PROGMEM = {
option_txt_2_4_0, option_txt_2_4_1, option_txt_2_4_2, option_txt_2_4_3, option_txt_2_4_4, option_txt_2_4_5, option_txt_2_4_6, NULL
};

const char title_txt_2_5[] PROGMEM = "\x20""Interval";
const char option_txt_2_5_0[] PROGMEM = "\x09""Continuous";
const char option_txt_2_5_1[] PROGMEM = "\x0a""4 Seconds";
const char option_txt_2_5_2[] PROGMEM = "\x0b""5 Seconds";
const char option_txt_2_5_3[] PROGMEM = "\x00""10 Seconds";
const char option_txt_2_5_4[] PROGMEM = "\x01""15 Seconds";
const char option_txt_2_5_5[] PROGMEM = "\x02""20 Seconds";
const char option_txt_2_5_6[] PROGMEM = "\x03""30 Seconds";
const char option_txt_2_5_7[] PROGMEM = "\x04""1 Minute";
const char option_txt_2_5_8[] PROGMEM = "\x05""2 Minutes";
const char option_txt_2_5_9[] PROGMEM = "\x06""5 Minutes";
const char option_txt_2_5_10[] PROGMEM = "\x07""30 Minutes";
const char option_txt_2_5_11[] PROGMEM = "\x08""60 Minutes";
const char* const option_txt_2_5[] PROGMEM = {
option_txt_2_5_0, option_txt_2_5_1, option_txt_2_5_2, option_txt_2_5_3, option_txt_2_5_4, option_txt_2_5_5, option_txt_2_5_6, option_txt_2_5_7, option_txt_2_5_8, option_txt_2_5_9, option_txt_2_5_10, option_txt_2_5_11, NULL
};

const char title_txt_2_6[] PROGMEM = "\x1c""Megapixels";
const char option_txt_2_6_0[] PROGMEM = "\x00""12MP Wide";
const char option_txt_2_6_1[] PROGMEM = "\x01""7MP Wide";
const char option_txt_2_6_2[] PROGMEM = "\x02""7MP Med";
const char option_txt_2_6_3[] PROGMEM = "\x03""5MP Med";
const char* const option_txt_2_6[] PROGMEM = {
option_txt_2_6_0, option_txt_2_6_1, option_txt_2_6_2, option_txt_2_6_3, NULL
};

const char title_txt_2_7[] PROGMEM = "\x21""Spot Meter";
const char option_txt_2_7_0[] PROGMEM = "\x01""ON";
const char option_txt_2_7_1[] PROGMEM = "\x00""OFF";
const char* const option_txt_2_7[] PROGMEM = {
option_txt_2_7_0, option_txt_2_7_1, NULL
};

const char title_txt_2_8[] PROGMEM = "\x22""Protune";
const char option_txt_2_8_0[] PROGMEM = "\x01""ON";
const char option_txt_2_8_1[] PROGMEM = "\x00""OFF";
const char* const option_txt_2_8[] PROGMEM = {
option_txt_2_8_0, option_txt_2_8_1, NULL
};

const char title_txt_2_9[] PROGMEM = "\x23""White Balance";
const char option_txt_2_9_0[] PROGMEM = "\x00""Auto";
const char option_txt_2_9_1[] PROGMEM = "\x01""3000K";
const char option_txt_2_9_2[] PROGMEM = "\x05""4000K";
const char option_txt_2_9_3[] PROGMEM = "\x06""4800K";
const char option_txt_2_9_4[] PROGMEM = "\x02""5500K";
const char option_txt_2_9_5[] PROGMEM = "\x07""6000K";
const char option_txt_2_9_6[] PROGMEM = "\x03""6500K";
const char option_txt_2_9_7[] PROGMEM = "\x04""Native";
const char* const option_txt_2_9[] PROGMEM = {
option_txt_2_9_0, option_txt_2_9_1, option_txt_2_9_2, option_txt_2_9_3, option_txt_2_9_4, option_txt_2_9_5, option_txt_2_9_6, option_txt_2_9_7, NULL
};

const char title_txt_2_10[] PROGMEM = "\x24""Color";
const char option_txt_2_10_0[] PROGMEM = "\x00""GoPro Color";
const char option_txt_2_10_1[] PROGMEM = "\x01""Flat";
const char* const option_txt_2_10[] PROGMEM = {
option_txt_2_10_0, option_txt_2_10_1, NULL
};

const char title_txt_2_11[] PROGMEM = "\x26""Sharpness";
const char option_txt_2_11_0[] PROGMEM = "\x00""High";
const char option_txt_2_11_1[] PROGMEM = "\x01""Medium";
const char option_txt_2_11_2[] PROGMEM = "\x02""Low";
const char* const option_txt_2_11[] PROGMEM = {
option_txt_2_11_0, option_txt_2_11_1, option_txt_2_11_2, NULL
};

const char title_txt_2_12[] PROGMEM = "\x27""EV Comp";
const char option_txt_2_12_0[] PROGMEM = "\x08""-2.0";
const char option_txt_2_12_1[] PROGMEM = "\x07""-1.5";
const char option_txt_2_12_2[] PROGMEM = "\x06""-1.0";
const char option_txt_2_12_3[] PROGMEM = "\x05""-0.5";
const char option_txt_2_12_4[] PROGMEM = "\x04""0";
const char option_txt_2_12_5[] PROGMEM = "\x03""+0.5";
const char option_txt_2_12_6[] PROGMEM = "\x02""+1.0";
const char option_txt_2_12_7[] PROGMEM = "\x01""+1.5";
const char option_txt_2_12_8[] PROGMEM = "\x00""+2.0";
const char* const option_txt_2_12[] PROGMEM = {
option_txt_2_12_0, option_txt_2_12_1, option_txt_2_12_2, option_txt_2_12_3, option_txt_2_12_4, option_txt_2_12_5, option_txt_2_12_6, option_txt_2_12_7, option_txt_2_12_8, NULL
};

const char title_txt_2_13[] PROGMEM = "\x4c""ISO Min";
const char option_txt_2_13_0[] PROGMEM = "\x00""800";
const char option_txt_2_13_1[] PROGMEM = "\x01""400";
const char option_txt_2_13_2[] PROGMEM = "\x02""200";
const char option_txt_2_13_3[] PROGMEM = "\x03""100";
const char* const option_txt_2_13[] PROGMEM = {
option_txt_2_13_0, option_txt_2_13_1, option_txt_2_13_2, option_txt_2_13_3, NULL
};

const char title_txt_2_14[] PROGMEM = "\x25""ISO Max";
const char option_txt_2_14_0[] PROGMEM = "\x00""800";
const char option_txt_2_14_1[] PROGMEM = "\x01""400";
const char option_txt_2_14_2[] PROGMEM = "\x02""200";
const char option_txt_2_14_3[] PROGMEM = "\x03""100";
const char* const option_txt_2_14[] PROGMEM = {
option_txt_2_14_0, option_txt_2_14_1, option_txt_2_14_2, option_txt_2_14_3, NULL
};


//

//
const char title_txt_4_0[] PROGMEM = "\x48""LCD Display";
const char option_txt_4_0_0[] PROGMEM = "\x01""ON";
const char option_txt_4_0_1[] PROGMEM = "\x00""OFF";
const char* const option_txt_4_0[] PROGMEM = {
option_txt_4_0_0, option_txt_4_0_1, NULL
};

const char title_txt_4_1[] PROGMEM = "\x31""LCD Brightness";
const char option_txt_4_1_0[] PROGMEM = "\x00""High";
const char option_txt_4_1_1[] PROGMEM = "\x01""Medium";
const char option_txt_4_1_2[] PROGMEM = "\x02""Low";
const char* const option_txt_4_1[] PROGMEM = {
option_txt_4_1_0, option_txt_4_1_1, option_txt_4_1_2, NULL
};

const char title_txt_4_2[] PROGMEM = "\x32""LCD Lock";
const char option_txt_4_2_0[] PROGMEM = "\x01""ON";
const char option_txt_4_2_1[] PROGMEM = "\x00""OFF";
const char* const option_txt_4_2[] PROGMEM = {
option_txt_4_2_0, option_txt_4_2_1, NULL
};

const char title_txt_4_3[] PROGMEM = "\x33""LCD Sleep";
const char option_txt_4_3_0[] PROGMEM = "\x00""Never";
const char option_txt_4_3_1[] PROGMEM = "\x01""1 MIN";
const char option_txt_4_3_2[] PROGMEM = "\x02""2 MIN";
const char option_txt_4_3_3[] PROGMEM = "\x03""3 MIN";
const char* const option_txt_4_3[] PROGMEM = {
option_txt_4_3_0, option_txt_4_3_1, option_txt_4_3_2, option_txt_4_3_3, NULL
};

const char title_txt_4_4[] PROGMEM = "\x34""Orientation";
const char option_txt_4_4_0[] PROGMEM = "\x01""Up";
const char option_txt_4_4_1[] PROGMEM = "\x02""Down";
const char option_txt_4_4_2[] PROGMEM = "\x00""Auto";
const char* const option_txt_4_4[] PROGMEM = {
option_txt_4_4_0, option_txt_4_4_1, option_txt_4_4_2, NULL
};

const char title_txt_4_5[] PROGMEM = "\x35""Default Mode";
const char option_txt_4_5_0[] PROGMEM = "\x00""Video";
const char option_txt_4_5_1[] PROGMEM = "\x01""Photo";
const char option_txt_4_5_2[] PROGMEM = "\x02""Multi-shot";
const char* const option_txt_4_5[] PROGMEM = {
option_txt_4_5_0, option_txt_4_5_1, option_txt_4_5_2, NULL
};

const char title_txt_4_6[] PROGMEM = "\x36""Quick Capture";
const char option_txt_4_6_0[] PROGMEM = "\x01""ON";
const char option_txt_4_6_1[] PROGMEM = "\x00""OFF";
const char* const option_txt_4_6[] PROGMEM = {
option_txt_4_6_0, option_txt_4_6_1, NULL
};

const char title_txt_4_7[] PROGMEM = "\x37""LED Blink";
const char option_txt_4_7_0[] PROGMEM = "\x00""OFF";
const char option_txt_4_7_1[] PROGMEM = "\x01""2";
const char option_txt_4_7_2[] PROGMEM = "\x02""4";
const char* const option_txt_4_7[] PROGMEM = {
option_txt_4_7_0, option_txt_4_7_1, option_txt_4_7_2, NULL
};

const char title_txt_4_8[] PROGMEM = "\x38""Beeps";
const char option_txt_4_8_0[] PROGMEM = "\x00""100%";
const char option_txt_4_8_1[] PROGMEM = "\x01""70%";
const char option_txt_4_8_2[] PROGMEM = "\x02""OFF";
const char* const option_txt_4_8[] PROGMEM = {
option_txt_4_8_0, option_txt_4_8_1, option_txt_4_8_2, NULL
};

const char title_txt_4_9[] PROGMEM = "\x39""Video Format";
const char option_txt_4_9_0[] PROGMEM = "\x00""NTSC";
const char option_txt_4_9_1[] PROGMEM = "\x01""PAL";
const char* const option_txt_4_9[] PROGMEM = {
option_txt_4_9_0, option_txt_4_9_1, NULL
};

const char title_txt_4_10[] PROGMEM = "\x3a""OSD";
const char option_txt_4_10_0[] PROGMEM = "\x01""ON";
const char option_txt_4_10_1[] PROGMEM = "\x00""OFF";
const char* const option_txt_4_10[] PROGMEM = {
option_txt_4_10_0, option_txt_4_10_1, NULL
};

const char title_txt_4_11[] PROGMEM = "\x3b""Auto Off";
const char option_txt_4_11_0[] PROGMEM = "\x00""NEVER";
const char option_txt_4_11_1[] PROGMEM = "\x01""1 MIN";
const char option_txt_4_11_2[] PROGMEM = "\x02""2 MIN";
const char option_txt_4_11_3[] PROGMEM = "\x03""3 MIN";
const char option_txt_4_11_4[] PROGMEM = "\x04""5 MIN";
const char* const option_txt_4_11[] PROGMEM = {
option_txt_4_11_0, option_txt_4_11_1, option_txt_4_11_2, option_txt_4_11_3, option_txt_4_11_4, NULL
};

const char title_txt_4_12[] PROGMEM = "\x3f""Wireless Mode";
const char option_txt_4_12_0[] PROGMEM = "\x00""OFF";
const char option_txt_4_12_1[] PROGMEM = "\x01""App";
const char option_txt_4_12_2[] PROGMEM = "\x02""RC";
const char option_txt_4_12_3[] PROGMEM = "\x04""Smart";
const char* const option_txt_4_12[] PROGMEM = {
option_txt_4_12_0, option_txt_4_12_1, option_txt_4_12_2, option_txt_4_12_3, NULL
};

//
const char title_txt_5_0[] PROGMEM = "\x50""Auto Audio Mode";
const char option_txt_5_0_0[] PROGMEM = "\x00""Stereo Only";
const char option_txt_5_0_1[] PROGMEM = "\x01""Wind Only";
const char option_txt_5_0_2[] PROGMEM = "\x02""Auto";
const char* const option_txt_5_0[] PROGMEM = {
option_txt_5_0_0, option_txt_5_0_1, option_txt_5_0_2, NULL
};

const char title_txt_5_1[] PROGMEM = "\x4f""Audio Protune";
const char option_txt_5_1_0[] PROGMEM = "\x01""ON";
const char option_txt_5_1_1[] PROGMEM = "\x00""OFF";
const char* const option_txt_5_1[] PROGMEM = {
option_txt_5_1_0, option_txt_5_1_1, NULL
};

const char title_txt_5_2[] PROGMEM = "\x51""Raw Audio Track";
const char option_txt_5_2_0[] PROGMEM = "\x00""Low";
const char option_txt_5_2_1[] PROGMEM = "\x01""Mid";
const char option_txt_5_2_2[] PROGMEM = "\x02""High";
const char* const option_txt_5_2[] PROGMEM = {
option_txt_5_2_0, option_txt_5_2_1, option_txt_5_2_2, NULL
};

struct Widget {
const char * title_txt;
const char * const *option_txt;
} Widget;

const struct Widget widgets[] PROGMEM = {
{ NULL, NULL },
{ title_txt_0_0, option_txt_0_0 },
{ title_txt_0_2, option_txt_0_2 },
{ title_txt_0_3, option_txt_0_3 },
{ title_txt_0_4, option_txt_0_4 },
{ title_txt_0_5, option_txt_0_5 },
{ title_txt_0_6, option_txt_0_6 },
{ title_txt_0_7, option_txt_0_7 },
{ title_txt_0_8, option_txt_0_8 },
{ title_txt_0_9, option_txt_0_9 },
{ title_txt_0_10, option_txt_0_10 },
{ title_txt_0_11, option_txt_0_11 },
{ title_txt_0_12, option_txt_0_12 },
{ title_txt_0_16, option_txt_0_16 },
{ title_txt_0_13, option_txt_0_13 },
{ title_txt_0_14, option_txt_0_14 },
{ title_txt_1_0, option_txt_1_0 },
{ title_txt_1_3, option_txt_1_3 },
{ title_txt_1_2, option_txt_1_2 },
{ title_txt_1_4, option_txt_1_4 },
{ title_txt_1_5, option_txt_1_5 },
{ title_txt_1_8, option_txt_1_8 },
{ title_txt_1_9, option_txt_1_9 },
{ title_txt_1_10, option_txt_1_10 },
{ title_txt_1_14, option_txt_1_14 },
{ title_txt_1_11, option_txt_1_11 },
{ title_txt_1_12, option_txt_1_12 },
{ title_txt_2_0, option_txt_2_0 },
{ title_txt_2_6, option_txt_2_6 },
{ title_txt_2_3, option_txt_2_3 },
{ title_txt_2_4, option_txt_2_4 },
{ title_txt_2_2, option_txt_2_2 },
{ title_txt_2_5, option_txt_2_5 },
{ title_txt_2_7, option_txt_2_7 },
{ title_txt_2_8, option_txt_2_8 },
{ title_txt_2_9, option_txt_2_9 },
{ title_txt_2_10, option_txt_2_10 },
{ title_txt_2_14, option_txt_2_14 },
{ title_txt_2_11, option_txt_2_11 },
{ title_txt_2_12, option_txt_2_12 },
{ NULL, NULL },
{ NULL, NULL },
{ NULL, NULL },
{ NULL, NULL },
{ NULL, NULL },
{ NULL, NULL },
{ NULL, NULL },
{ NULL, NULL },
{ NULL, NULL },
{ title_txt_4_1, option_txt_4_1 },
{ title_txt_4_2, option_txt_4_2 },
{ title_txt_4_3, option_txt_4_3 },
{ title_txt_4_4, option_txt_4_4 },
{ title_txt_4_5, option_txt_4_5 },
{ title_txt_4_6, option_txt_4_6 },
{ title_txt_4_7, option_txt_4_7 },
{ title_txt_4_8, option_txt_4_8 },
{ title_txt_4_9, option_txt_4_9 },
{ title_txt_4_10, option_txt_4_10 },
{ title_txt_4_11, option_txt_4_11 },
{ NULL, NULL },
{ NULL, NULL },
{ NULL, NULL },
{ title_txt_4_12, option_txt_4_12 },
{ NULL, NULL },
{ NULL, NULL },
{ NULL, NULL },
{ NULL, NULL },
{ title_txt_0_1, option_txt_0_1 },
{ title_txt_1_1, option_txt_1_1 },
{ title_txt_2_1, option_txt_2_1 },
{ NULL, NULL },
{ title_txt_4_0, option_txt_4_0 },
{ title_txt_0_15, option_txt_0_15 },
{ title_txt_0_17, option_txt_0_17 },
{ title_txt_1_13, option_txt_1_13 },
{ title_txt_2_13, option_txt_2_13 },
{ title_txt_1_6, option_txt_1_6 },
{ title_txt_0_18, option_txt_0_18 },
{ title_txt_5_1, option_txt_5_1 },
{ title_txt_5_0, option_txt_5_0 },
{ title_txt_5_2, option_txt_5_2 },
{ title_txt_1_7, option_txt_1_7 },
};

#define SETUP_LEN 83
typedef union Setting {
  byte b[SETUP_LEN];
  struct {
    byte mode;
    struct {
      byte default_sub_mode;
      byte resolution;
      byte fps;
      byte fov;
      byte timelapse_rate;
      byte looping;
      byte piv;
      byte low_light;
      byte spot_meter;
      byte protune;
      byte protune_white_balance;
      byte protune_color;
      byte protune_iso;
      byte protune_sharpness;
      byte protune_ev;  
    } video;
    struct {
      byte default_sub_mode;
      byte resolution;
      byte continuous_rate;
      byte exposure_time;
      byte spot_meter;
      byte protune;
      byte protune_white_balance;
      byte protune_color;
      byte protune_iso;
      byte protune_sharpness;
      byte protune_ev; 
    } photo;
    struct {
      byte default_sub_mode;
      byte resolution;
      byte burst_rate;
      byte timelapse_rate;
      byte exposure_time;
      byte nightlapse_rate;
      byte spot_meter;
      byte protune;
      byte protune_white_balance;
      byte protune_color;
      byte protune_iso;
      byte protune_sharpness;
      byte protune_ev;
    } multi_shot;
    byte reserved0[9];
    struct {
      byte lcd_brightness;
      byte lcd_lock;
      byte lcd_sleep;
      byte orientation;
      byte default_app_mode;
      byte quick_capture;
      byte led;
      byte beep_volume;
      byte video_format;
      byte osd;
      byte auto_power_down;
      byte stream_gop_size;
      byte stream_idr_interval;
      byte stream_bit_rate;
      byte wireless_mode;
      byte stream_window_size;
    } setup;
    byte reserved1[3];
    byte current_submode[5];
    struct {
      byte videoExposure_time;
      byte videoProtune_iso_mode;
      byte photoProtune_iso_min;
      byte multi_shotProtune_iso_min;
      // the following are not supported yet in firmware v4.0.0
      byte photoSingle_wdr;
      byte videoEis;
      byte audioProtune;
      byte audioOption;
      byte audioProtune_option;
      byte photoSingle_raw;
    } v4;
  } p;
} Setting;

Setting setting =
{
         // id path
  0,     //  0 
  0,     //  1 video/default_sub_mode
  9,     //  2 video/resolution
  5,     //  3 video/fps
  0,     //  4 video/fov
  0,     //  5 video/timelapse_rate
  1,     //  6 video/looping
  1,     //  7 video/piv
  1,     //  8 video/low_light
  0,     //  9 video/spot_meter
  0,     // 10 video/protune
  0,     // 11 video/protune_white_balance
  0,     // 12 video/protune_color
  1,     // 13 video/protune_iso
  0,     // 14 video/protune_sharpness
  4,     // 15 video/protune_ev
  0,     // 16 photo/default_sub_mode
  0,     // 17 photo/resolution
  0,     // 18 photo/continuous_rate
  0,     // 19 photo/exposure_time
  0,     // 20 photo/spot_meter
  0,     // 21 photo/protune
  0,     // 22 photo/protune_white_balance
  0,     // 23 photo/protune_color
  0,     // 24 photo/protune_iso
  0,     // 25 photo/protune_sharpness
  4,     // 26 photo/protune_ev
  0,     // 27 multi_shot/default_sub_mode
  0,     // 28 multi_shot/resolution
  5,     // 29 multi_shot/burst_rate
  0,     // 30 multi_shot/timelapse_rate
  0,     // 31 multi_shot/exposure_time
  9,     // 32 multi_shot/nightlapse_rate
  0,     // 33 multi_shot/spot_meter
  0,     // 34 multi_shot/protune
  0,     // 35 multi_shot/protune_white_balance
  0,     // 36 multi_shot/protune_color
  0,     // 37 multi_shot/protune_iso
  0,     // 38 multi_shot/protune_sharpness
  4,     // 39 multi_shot/protune_ev
  0,     // 40
  0,     // 41
  0,     // 42
  0,     // 43
  0,     // 44
  0,     // 45
  0,     // 46
  0,     // 47
  0,     // 48
  0,     // 49 setup/lcd_brightness
  0,     // 50 setup/lcd_lock
  0,     // 51 setup/lcd_sleep
  1,     // 52 setup/orientation
  0,     // 53 setup/default_app_mode
  0,     // 54 setup/quick_capture
  2,     // 55 setup/led
  0,     // 56 setup/beep_volume
  0,     // 57 setup/video_format
  1,     // 58 setup/osd
  0,     // 59 setup/auto_power_down
  0,     // 60 setup/stream_gop_size
  0,     // 61 setup/stream_idr_interval
  0,     // 62 setup/stream_bit_rate
  0,     // 63 setup/wireless_mode
  0,     // 64 setup/stream_window_size
  0,     // 65
  0,     // 66
  0,     // 67
  0,     // 68 setup/current_sub_mode (video)
  0,     // 69 setup/current_sub_mode (photo)
  0,     // 70 setup/current_sub_mode (multi shot)
  0,     // 71
  0,     // 72 setup/lcd
// firmware v.4.00 only
  0,     // 73 v4/video/exposure_time
  0,     // 74 v4/video/protune_iso_mode
  3,     // 75 v4/photo/protune_iso_min
  3,     // 76 v4/multi_shot/protune_iso_min
// v4.0.0 firmware doesn't support the following, yet
  0,     // 77 v4/photo/single_wdr (wide dynamic range)
  0,     // 78 v4/video/eis (electronic image stabilization)
  1,     // 79 v4/audio/protune
  1,     // 80 v4/audio/option (0: stereo only, 1: wind only, 2: auto)
  1,     // 81 v4/audio/protune_option (0: Low, 1: Mid, 2: High)
  0,     // 82 v4/photo/single_raw (capture in raw)
};

const char MAX_SUBMODE_SIZE = 4;

Setting storage[MAX_SUBMODE_SIZE] = {
{ // setting #0
         // id path
  0,     //  0 
  0,     //  1 video/default_sub_mode
  9,     //  2 video/resolution
  5,     //  3 video/fps
  0,     //  4 video/fov
  0,     //  5 video/timelapse_rate
  1,     //  6 video/looping
  1,     //  7 video/piv
  1,     //  8 video/low_light
  0,     //  9 video/spot_meter
  0,     // 10 video/protune
  0,     // 11 video/protune_white_balance
  0,     // 12 video/protune_color
  1,     // 13 video/protune_iso
  0,     // 14 video/protune_sharpness
  4,     // 15 video/protune_ev
  0,     // 16 photo/default_sub_mode
  0,     // 17 photo/resolution
  0,     // 18 photo/continuous_rate
  0,     // 19 photo/exposure_time
  0,     // 20 photo/spot_meter
  0,     // 21 photo/protune
  0,     // 22 photo/protune_white_balance
  0,     // 23 photo/protune_color
  0,     // 24 photo/protune_iso
  0,     // 25 photo/protune_sharpness
  4,     // 26 photo/protune_ev
  0,     // 27 multi_shot/default_sub_mode
  0,     // 28 multi_shot/resolution
  5,     // 29 multi_shot/burst_rate
  0,     // 30 multi_shot/timelapse_rate
  0,     // 31 multi_shot/exposure_time
  9,     // 32 multi_shot/nightlapse_rate
  0,     // 33 multi_shot/spot_meter
  0,     // 34 multi_shot/protune
  0,     // 35 multi_shot/protune_white_balance
  0,     // 36 multi_shot/protune_color
  0,     // 37 multi_shot/protune_iso
  0,     // 38 multi_shot/protune_sharpness
  4,     // 39 multi_shot/protune_ev
  0,     // 40
  0,     // 41
  0,     // 42
  0,     // 43
  0,     // 44
  0,     // 45
  0,     // 46
  0,     // 47
  0,     // 48
  0,     // 49 setup/lcd_brightness
  0,     // 50 setup/lcd_lock
  0,     // 51 setup/lcd_sleep
  0,     // 52 setup/orientation
  0,     // 53 setup/default_app_mode
  0,     // 54 setup/quick_capture
  2,     // 55 setup/led
  0,     // 56 setup/beep_volume
  0,     // 57 setup/video_format
  1,     // 58 setup/osd
  0,     // 59 setup/auto_power_down
  0,     // 60 setup/stream_gop_size
  0,     // 61 setup/stream_idr_interval
  0,     // 62 setup/stream_bit_rate
  0,     // 63 setup/wireless_mode
  0,     // 64 setup/stream_window_size
  0,     // 65
  0,     // 66
  0,     // 67
  0,     // 68 setup/current_sub_mode (video)
  0,     // 69 setup/current_sub_mode (photo)
  0,     // 70 setup/current_sub_mode (multi shot)
  0,     // 71
  0,     // 72 setup/lcd
// firmware v.4.00 only
  0,     // 73 v4/video/exposure_time
  0,     // 74 v4/video/protune_iso_mode
  3,     // 75 v4/photo/protune_iso_min
  3,     // 76 v4/multi_shot/protune_iso_min
// v4.0.0 firmware doesn't support the following, yet
  0,     // 77 v4/photo/single_wdr (wide dynamic range)
  0,     // 78 v4/video/eis (electronic image stabilization)
  1,     // 79 v4/audio/protune
  1,     // 80 v4/audio/option (0: stereo only, 1: wind only, 2: auto)
  1,     // 81 v4/audio/protune_option (0: Low, 1: Mid, 2: High)
  0,     // 82 v4/photo/single_raw (capture in raw)
},
{ // setting #1
         // id path
  0,     //  0 
  0,     //  1 video/default_sub_mode
  1,     //  2 video/resolution
  8,     //  3 video/fps
  0,     //  4 video/fov
  0,     //  5 video/timelapse_rate
  1,     //  6 video/looping
  1,     //  7 video/piv
  1,     //  8 video/low_light
  0,     //  9 video/spot_meter
  0,     // 10 video/protune
  0,     // 11 video/protune_white_balance
  0,     // 12 video/protune_color
  1,     // 13 video/protune_iso
  0,     // 14 video/protune_sharpness
  4,     // 15 video/protune_ev
  0,     // 16 photo/default_sub_mode
  0,     // 17 photo/resolution
  0,     // 18 photo/continuous_rate
  0,     // 19 photo/exposure_time
  0,     // 20 photo/spot_meter
  0,     // 21 photo/protune
  0,     // 22 photo/protune_white_balance
  0,     // 23 photo/protune_color
  0,     // 24 photo/protune_iso
  0,     // 25 photo/protune_sharpness
  4,     // 26 photo/protune_ev
  0,     // 27 multi_shot/default_sub_mode
  0,     // 28 multi_shot/resolution
  5,     // 29 multi_shot/burst_rate
  0,     // 30 multi_shot/timelapse_rate
  0,     // 31 multi_shot/exposure_time
  9,     // 32 multi_shot/nightlapse_rate
  0,     // 33 multi_shot/spot_meter
  0,     // 34 multi_shot/protune
  0,     // 35 multi_shot/protune_white_balance
  0,     // 36 multi_shot/protune_color
  0,     // 37 multi_shot/protune_iso
  0,     // 38 multi_shot/protune_sharpness
  4,     // 39 multi_shot/protune_ev
  0,     // 40
  0,     // 41
  0,     // 42
  0,     // 43
  0,     // 44
  0,     // 45
  0,     // 46
  0,     // 47
  0,     // 48
  0,     // 49 setup/lcd_brightness
  0,     // 50 setup/lcd_lock
  0,     // 51 setup/lcd_sleep
  0,     // 52 setup/orientation
  0,     // 53 setup/default_app_mode
  0,     // 54 setup/quick_capture
  2,     // 55 setup/led
  0,     // 56 setup/beep_volume
  0,     // 57 setup/video_format
  1,     // 58 setup/osd
  0,     // 59 setup/auto_power_down
  0,     // 60 setup/stream_gop_size
  0,     // 61 setup/stream_idr_interval
  0,     // 62 setup/stream_bit_rate
  0,     // 63 setup/wireless_mode
  0,     // 64 setup/stream_window_size
  0,     // 65
  0,     // 66
  0,     // 67
  0,     // 68 setup/current_sub_mode (video)
  0,     // 69 setup/current_sub_mode (photo)
  0,     // 70 setup/current_sub_mode (multi shot)
  0,     // 71
  0,     // 72 setup/lcd
// firmware v.4.00 only
  0,     // 73 v4/video/exposure_time
  0,     // 74 v4/video/protune_iso_mode
  3,     // 75 v4/photo/protune_iso_min
  3,     // 76 v4/multi_shot/protune_iso_min
// v4.0.0 firmware doesn't support the following, yet
  0,     // 77 v4/photo/single_wdr (wide dynamic range)
  0,     // 78 v4/video/eis (electronic image stabilization)
  1,     // 79 v4/audio/protune
  1,     // 80 v4/audio/option (0: stereo only, 1: wind only, 2: auto)
  1,     // 81 v4/audio/protune_option (0: Low, 1: Mid, 2: High)
  0,     // 82 v4/photo/single_raw (capture in raw)
},
{ // setting #2
         // id path
  0,     //  0 
  0,     //  1 video/default_sub_mode
  9,     //  2 video/resolution
  8,     //  3 video/fps
  0,     //  4 video/fov
  0,     //  5 video/timelapse_rate
  1,     //  6 video/looping
  1,     //  7 video/piv
  1,     //  8 video/low_light
  0,     //  9 video/spot_meter
  0,     // 10 video/protune
  0,     // 11 video/protune_white_balance
  0,     // 12 video/protune_color
  1,     // 13 video/protune_iso
  0,     // 14 video/protune_sharpness
  4,     // 15 video/protune_ev
  0,     // 16 photo/default_sub_mode
  0,     // 17 photo/resolution
  0,     // 18 photo/continuous_rate
  0,     // 19 photo/exposure_time
  0,     // 20 photo/spot_meter
  0,     // 21 photo/protune
  0,     // 22 photo/protune_white_balance
  0,     // 23 photo/protune_color
  0,     // 24 photo/protune_iso
  0,     // 25 photo/protune_sharpness
  4,     // 26 photo/protune_ev
  0,     // 27 multi_shot/default_sub_mode
  0,     // 28 multi_shot/resolution
  5,     // 29 multi_shot/burst_rate
  0,     // 30 multi_shot/timelapse_rate
  0,     // 31 multi_shot/exposure_time
  9,     // 32 multi_shot/nightlapse_rate
  0,     // 33 multi_shot/spot_meter
  0,     // 34 multi_shot/protune
  0,     // 35 multi_shot/protune_white_balance
  0,     // 36 multi_shot/protune_color
  0,     // 37 multi_shot/protune_iso
  0,     // 38 multi_shot/protune_sharpness
  4,     // 39 multi_shot/protune_ev
  0,     // 40
  0,     // 41
  0,     // 42
  0,     // 43
  0,     // 44
  0,     // 45
  0,     // 46
  0,     // 47
  0,     // 48
  0,     // 49 setup/lcd_brightness
  0,     // 50 setup/lcd_lock
  0,     // 51 setup/lcd_sleep
  0,     // 52 setup/orientation
  0,     // 53 setup/default_app_mode
  0,     // 54 setup/quick_capture
  2,     // 55 setup/led
  0,     // 56 setup/beep_volume
  0,     // 57 setup/video_format
  1,     // 58 setup/osd
  0,     // 59 setup/auto_power_down
  0,     // 60 setup/stream_gop_size
  0,     // 61 setup/stream_idr_interval
  0,     // 62 setup/stream_bit_rate
  0,     // 63 setup/wireless_mode
  0,     // 64 setup/stream_window_size
  0,     // 65
  0,     // 66
  0,     // 67
  0,     // 68 setup/current_sub_mode (video)
  0,     // 69 setup/current_sub_mode (photo)
  0,     // 70 setup/current_sub_mode (multi shot)
  0,     // 71
  0,     // 72 setup/lcd
// firmware v.4.00 only
  0,     // 73 v4/video/exposure_time
  0,     // 74 v4/video/protune_iso_mode
  3,     // 75 v4/photo/protune_iso_min
  3,     // 76 v4/multi_shot/protune_iso_min
// v4.0.0 firmware doesn't support the following, yet
  0,     // 77 v4/photo/single_wdr (wide dynamic range)
  0,     // 78 v4/video/eis (electronic image stabilization)
  1,     // 79 v4/audio/protune
  1,     // 80 v4/audio/option (0: stereo only, 1: wind only, 2: auto)
  1,     // 81 v4/audio/protune_option (0: Low, 1: Mid, 2: High)
  0,     // 82 v4/photo/single_raw (capture in raw)
},
{ // setting #3
         // id path
  0,     //  0 
  0,     //  1 video/default_sub_mode
  9,     //  2 video/resolution
  5,     //  3 video/fps
  0,     //  4 video/fov
  0,     //  5 video/timelapse_rate
  1,     //  6 video/looping
  1,     //  7 video/piv
  1,     //  8 video/low_light
  0,     //  9 video/spot_meter
  0,     // 10 video/protune
  0,     // 11 video/protune_white_balance
  0,     // 12 video/protune_color
  1,     // 13 video/protune_iso
  0,     // 14 video/protune_sharpness
  4,     // 15 video/protune_ev
  0,     // 16 photo/default_sub_mode
  0,     // 17 photo/resolution
  0,     // 18 photo/continuous_rate
  0,     // 19 photo/exposure_time
  0,     // 20 photo/spot_meter
  0,     // 21 photo/protune
  0,     // 22 photo/protune_white_balance
  0,     // 23 photo/protune_color
  0,     // 24 photo/protune_iso
  0,     // 25 photo/protune_sharpness
  4,     // 26 photo/protune_ev
  0,     // 27 multi_shot/default_sub_mode
  0,     // 28 multi_shot/resolution
  5,     // 29 multi_shot/burst_rate
  0,     // 30 multi_shot/timelapse_rate
  0,     // 31 multi_shot/exposure_time
  9,     // 32 multi_shot/nightlapse_rate
  0,     // 33 multi_shot/spot_meter
  0,     // 34 multi_shot/protune
  0,     // 35 multi_shot/protune_white_balance
  0,     // 36 multi_shot/protune_color
  0,     // 37 multi_shot/protune_iso
  0,     // 38 multi_shot/protune_sharpness
  4,     // 39 multi_shot/protune_ev
  0,     // 40
  0,     // 41
  0,     // 42
  0,     // 43
  0,     // 44
  0,     // 45
  0,     // 46
  0,     // 47
  0,     // 48
  0,     // 49 setup/lcd_brightness
  0,     // 50 setup/lcd_lock
  0,     // 51 setup/lcd_sleep
  0,     // 52 setup/orientation
  0,     // 53 setup/default_app_mode
  0,     // 54 setup/quick_capture
  2,     // 55 setup/led
  0,     // 56 setup/beep_volume
  0,     // 57 setup/video_format
  1,     // 58 setup/osd
  0,     // 59 setup/auto_power_down
  0,     // 60 setup/stream_gop_size
  0,     // 61 setup/stream_idr_interval
  0,     // 62 setup/stream_bit_rate
  0,     // 63 setup/wireless_mode
  0,     // 64 setup/stream_window_size
  0,     // 65
  0,     // 66
  0,     // 67
  0,     // 68 setup/current_sub_mode (video)
  0,     // 69 setup/current_sub_mode (photo)
  0,     // 70 setup/current_sub_mode (multi shot)
  0,     // 71
  0,     // 72 setup/lcd
// firmware v.4.00 only
  0,     // 73 v4/video/exposure_time
  0,     // 74 v4/video/protune_iso_mode
  3,     // 75 v4/photo/protune_iso_min
  3,     // 76 v4/multi_shot/protune_iso_min
// v4.0.0 firmware doesn't support the following, yet
  0,     // 77 v4/photo/single_wdr (wide dynamic range)
  0,     // 78 v4/video/eis (electronic image stabilization)
  1,     // 79 v4/audio/protune
  1,     // 80 v4/audio/option (0: stereo only, 1: wind only, 2: auto)
  1,     // 81 v4/audio/protune_option (0: Low, 1: Mid, 2: High)
  0,     // 82 v4/photo/single_raw (capture in raw)
},  
};

boolean blacklist(byte id, byte v)
{
if(id==3&&setting.b[2]==13&&setting.b[57]==0)switch(v){case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 11:case 12:return true;}
if(id==3&&setting.b[2]==11&&setting.b[57]==0)switch(v){case 0:case 2:case 3:case 4:case 6:case 7:case 8:case 9:case 10:case 11:case 12:return true;}
if(id==3&&setting.b[2]==12&&setting.b[57]==0)switch(v){case 2:case 3:case 4:case 6:case 7:case 9:case 10:case 11:case 12:return true;}
if(id==3&&setting.b[2]==10&&setting.b[57]==0)switch(v){case 0:case 2:case 3:case 4:case 6:case 7:case 8:case 9:case 10:case 11:case 12:return true;}
if(id==3&&setting.b[2]==8&&setting.b[57]==0)switch(v){case 0:case 1:case 2:case 3:case 6:case 9:case 11:case 12:return true;}
if(id==3&&setting.b[2]==9&&setting.b[57]==0)switch(v){case 0:case 2:case 4:case 6:case 9:case 11:case 12:return true;}
if(id==3&&setting.b[2]==7&&setting.b[57]==0)switch(v){case 0:case 1:case 2:case 3:case 6:case 9:case 11:case 12:return true;}
if(id==3&&setting.b[2]==6&&setting.b[57]==0)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 9:case 10:case 11:case 12:return true;}
if(id==3&&setting.b[2]==5&&setting.b[57]==0)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 9:case 10:case 11:case 12:return true;}
if(id==3&&setting.b[2]==4&&setting.b[57]==0)switch(v){case 0:case 1:case 2:case 3:case 4:case 6:case 9:case 11:case 12:return true;}
if(id==3&&setting.b[2]==2&&setting.b[57]==0)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 11:case 12:return true;}
if(id==3&&setting.b[2]==1&&setting.b[57]==0)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 9:case 11:case 12:return true;}
if(id==3&&setting.b[2]==13&&setting.b[57]==1)switch(v){case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 11:case 12:return true;}
if(id==3&&setting.b[2]==11&&setting.b[57]==1)switch(v){case 0:case 2:case 3:case 4:case 5:case 7:case 8:case 9:case 10:case 11:case 12:return true;}
if(id==3&&setting.b[2]==12&&setting.b[57]==1)switch(v){case 2:case 3:case 4:case 5:case 7:case 8:case 10:case 11:case 12:return true;}
if(id==3&&setting.b[2]==10&&setting.b[57]==1)switch(v){case 0:case 2:case 3:case 4:case 5:case 7:case 8:case 9:case 10:case 11:case 12:return true;}
if(id==3&&setting.b[2]==8&&setting.b[57]==1)switch(v){case 0:case 1:case 2:case 3:case 5:case 8:case 11:case 12:return true;}
if(id==3&&setting.b[2]==9&&setting.b[57]==1)switch(v){case 0:case 2:case 4:case 5:case 8:case 11:case 12:return true;}
if(id==3&&setting.b[2]==7&&setting.b[57]==1)switch(v){case 0:case 1:case 2:case 3:case 5:case 8:case 11:case 12:return true;}
if(id==3&&setting.b[2]==6&&setting.b[57]==1)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 10:case 11:case 12:return true;}
if(id==3&&setting.b[2]==5&&setting.b[57]==1)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 10:case 11:case 12:return true;}
if(id==3&&setting.b[2]==4&&setting.b[57]==1)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 8:case 11:case 12:return true;}
if(id==3&&setting.b[2]==2&&setting.b[57]==1)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 11:case 12:return true;}
if(id==3&&setting.b[2]==1&&setting.b[57]==1)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 11:case 12:return true;}
if(id==4&&setting.b[2]==1)switch(v){case 1:case 2:case 4:return true;}
if(id==4&&setting.b[2]==2)switch(v){case 1:case 2:case 4:return true;}
if(id==4&&setting.b[2]==4&&setting.b[3]==5)switch(v){case 2:case 4:return true;}
if(id==4&&setting.b[2]==4&&setting.b[3]==6)switch(v){case 2:case 4:return true;}
if(id==4&&setting.b[2]==4&&setting.b[3]==7)switch(v){case 2:case 4:return true;}
if(id==4&&setting.b[2]==4)switch(v){case 2:return true;}
if(id==4&&setting.b[2]==5)switch(v){case 1:case 2:case 4:return true;}
if(id==4&&setting.b[2]==6)switch(v){case 1:case 2:case 4:return true;}
if(id==4&&setting.b[2]==7)switch(v){case 1:case 2:case 4:return true;}
if(id==4&&setting.b[2]==9&&setting.b[3]==1)switch(v){case 1:case 4:return true;}
if(id==4&&setting.b[2]==9&&setting.b[3]==3)switch(v){case 1:case 4:return true;}
if(id==4&&setting.b[2]==8)switch(v){case 1:case 2:case 4:return true;}
if(id==4&&setting.b[2]==10)switch(v){case 1:case 2:case 4:return true;}
if(id==4&&setting.b[2]==12&&setting.b[3]==0)switch(v){case 0:case 1:case 4:return true;}
if(id==4&&setting.b[2]==11)switch(v){case 1:case 2:case 4:return true;}
if(id==4&&setting.b[2]==13)switch(v){case 1:case 2:case 4:return true;}
if(id==2&&setting.b[68]==2)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 8:case 10:case 11:case 13:return true;}
if(id==3&&setting.b[68]==2&&setting.b[2]==4)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 11:case 12:return true;}
if(id==3&&setting.b[68]==2&&setting.b[2]==5)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 10:case 11:case 12:return true;}
if(id==3&&setting.b[68]==2&&setting.b[2]==7)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 11:case 12:return true;}
if(id==3&&setting.b[68]==2&&setting.b[2]==9)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 11:case 12:return true;}
if(id==3&&setting.b[68]==2&&setting.b[2]==8)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 11:case 12:return true;}
if(id==3&&setting.b[68]==2&&setting.b[2]==10)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 10:case 11:case 12:return true;}
if(id==3&&setting.b[68]==2&&setting.b[2]==11)switch(v){case 0:case 1:case 2:case 3:case 4:case 7:case 8:case 9:case 10:case 11:case 12:return true;}
if(id==3&&setting.b[68]==2&&setting.b[2]==12)switch(v){case 0:case 1:case 2:case 3:case 4:case 7:case 10:case 11:case 12:return true;}
if(id==4&&setting.b[68]==2&&setting.b[2]==12&&setting.b[3]==5)switch(v){case 0:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==1)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==2)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==3)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==4)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==5)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==6)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==7)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==8)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==9)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==10)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==11)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==12)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==13)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==14)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==15)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==16)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==17)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==18)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==19)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==20)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==21)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==22)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[10]==1&&setting.b[73]==23)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[68]==1)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[3]==0)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[3]==8)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[3]==9)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[3]==10)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[3]==11)switch(v){case 0:case 1:return true;}
if(id==8&&setting.b[3]==12)switch(v){case 0:case 1:return true;}
if(id==11&&setting.b[10]==0)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:return true;}
if(id==12&&setting.b[10]==0)switch(v){case 0:case 1:return true;}
if(id==14&&setting.b[10]==0)switch(v){case 0:case 1:case 2:return true;}
if(id==13&&setting.b[10]==0)switch(v){case 0:case 1:case 2:case 3:case 4:case 7:case 8:return true;}
if(id==74&&setting.b[10]==0)switch(v){case 0:case 1:return true;}
if(id==15&&setting.b[10]==0)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==73&&setting.b[10]==0)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 11:case 12:case 13:case 14:case 15:case 16:case 17:case 18:case 19:case 20:case 21:case 22:case 23:return true;}
if(id==5&&setting.b[68]==0)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:return true;}
if(id==6&&setting.b[68]==0)switch(v){case 0:case 1:case 2:case 3:case 4:return true;}
if(id==7&&setting.b[68]==0)switch(v){case 0:case 1:case 2:case 3:case 4:return true;}
if(id==6&&setting.b[68]==1)switch(v){case 0:case 1:case 2:case 3:case 4:return true;}
if(id==7&&setting.b[68]==1)switch(v){case 0:case 1:case 2:case 3:case 4:return true;}
if(id==6&&setting.b[68]==2)switch(v){case 0:case 1:case 2:case 3:case 4:return true;}
if(id==5&&setting.b[68]==2)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:return true;}
if(id==7&&setting.b[68]==3)switch(v){case 0:case 1:case 2:case 3:case 4:return true;}
if(id==5&&setting.b[68]==3)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:return true;}
if(id==4&&setting.b[68]==1)switch(v){case 0:case 1:case 2:return true;}
if(id==9&&setting.b[68]==1)switch(v){case 0:case 1:return true;}
if(id==2&&setting.b[68]==1)switch(v){case 2:case 3:case 4:case 5:case 7:case 8:case 9:case 10:case 11:case 12:case 13:return true;}
if(id==3&&setting.b[68]==1)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 11:case 12:return true;}
if(id==73&&setting.b[3]==0)switch(v){case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 11:case 12:case 13:case 14:case 15:case 16:case 17:case 19:case 20:case 21:return true;}
if(id==73&&setting.b[3]==1)switch(v){case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 11:case 12:case 14:case 15:case 16:case 17:case 19:case 20:case 21:case 23:return true;}
if(id==73&&setting.b[3]==2)switch(v){case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 11:case 13:case 14:case 15:case 16:case 18:case 19:case 20:case 22:case 23:return true;}
if(id==73&&setting.b[3]==3)switch(v){case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 11:case 12:case 13:case 14:case 16:case 17:case 18:case 19:case 21:case 22:case 23:return true;}
if(id==73&&setting.b[3]==4)switch(v){case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 10:case 11:case 12:case 13:case 15:case 16:case 17:case 18:case 20:case 21:case 22:case 23:return true;}
if(id==73&&setting.b[3]==5)switch(v){case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 9:case 10:case 11:case 12:case 14:case 15:case 16:case 17:case 19:case 20:case 21:case 22:case 23:return true;}
if(id==73&&setting.b[3]==6)switch(v){case 1:case 2:case 3:case 4:case 5:case 6:case 8:case 9:case 10:case 11:case 13:case 14:case 15:case 16:case 18:case 19:case 20:case 21:case 22:case 23:return true;}
if(id==73&&setting.b[3]==7)switch(v){case 1:case 2:case 3:case 4:case 5:case 7:case 8:case 9:case 10:case 12:case 13:case 14:case 15:case 17:case 18:case 19:case 20:case 21:case 22:case 23:return true;}
if(id==73&&setting.b[3]==8)switch(v){case 1:case 2:case 3:case 4:case 6:case 7:case 9:case 10:case 11:case 12:case 14:case 15:case 16:case 17:case 18:case 19:case 20:case 21:case 22:case 23:return true;}
if(id==73&&setting.b[3]==9)switch(v){case 1:case 2:case 3:case 5:case 6:case 8:case 9:case 10:case 11:case 13:case 14:case 15:case 16:case 17:case 18:case 19:case 20:case 21:case 22:case 23:return true;}
if(id==73&&setting.b[3]==10)switch(v){case 1:case 2:case 4:case 5:case 7:case 8:case 9:case 10:case 12:case 13:case 14:case 15:case 16:case 17:case 18:case 19:case 20:case 21:case 22:case 23:return true;}
if(id==73&&setting.b[3]==11)switch(v){case 1:case 3:case 4:case 6:case 7:case 9:case 10:case 11:case 12:case 13:case 14:case 15:case 16:case 17:case 18:case 19:case 20:case 21:case 22:case 23:return true;}
if(id==73&&setting.b[3]==12)switch(v){case 3:case 4:case 5:case 6:case 8:case 9:case 10:case 11:case 12:case 13:case 14:case 15:case 16:case 17:case 18:case 19:case 20:case 21:case 22:case 23:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==1)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==2)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==3)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==4)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==5)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==6)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==7)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==8)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==9)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==10)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==11)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==12)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==13)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==14)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==15)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==16)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==17)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==18)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==19)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==20)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==21)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==22)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[10]==1&&setting.b[73]==23)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==1&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==2&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==3&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==4&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==5&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==6&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==7&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==8&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==9&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==10&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==11&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==12&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==13&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==14&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==15&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==16&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==17&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==18&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==19&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==20&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==21&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==22&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==13&&setting.b[10]==1&&setting.b[73]==23&&setting.b[74]==0)switch(v){case 7:case 8:return true;}
if(id==18&&setting.b[69]==0)switch(v){case 0:case 1:case 2:return true;}
if(id==19&&setting.b[69]==0)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:return true;}
if(id==19&&setting.b[69]==1)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:return true;}
if(id==18&&setting.b[69]==2)switch(v){case 0:case 1:case 2:return true;}
if(id==22&&setting.b[21]==0)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:return true;}
if(id==23&&setting.b[21]==0)switch(v){case 0:case 1:return true;}
if(id==25&&setting.b[21]==0)switch(v){case 0:case 1:case 2:return true;}
if(id==75&&setting.b[21]==0)switch(v){case 0:case 1:case 2:case 3:return true;}
if(id==24&&setting.b[21]==0)switch(v){case 0:case 1:case 2:case 3:return true;}
if(id==26&&setting.b[21]==0)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==22&&setting.b[69]==2&&setting.b[19]==1)switch(v){case 0:return true;}
if(id==22&&setting.b[69]==2&&setting.b[19]==2)switch(v){case 0:return true;}
if(id==22&&setting.b[69]==2&&setting.b[19]==3)switch(v){case 0:return true;}
if(id==22&&setting.b[69]==2&&setting.b[19]==4)switch(v){case 0:return true;}
if(id==22&&setting.b[69]==2&&setting.b[19]==5)switch(v){case 0:return true;}
if(id==22&&setting.b[69]==2&&setting.b[19]==6)switch(v){case 0:return true;}
if(id==26&&setting.b[69]==2&&setting.b[19]==1)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==26&&setting.b[69]==2&&setting.b[19]==2)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==26&&setting.b[69]==2&&setting.b[19]==3)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==26&&setting.b[69]==2&&setting.b[19]==4)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==26&&setting.b[69]==2&&setting.b[19]==5)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==26&&setting.b[69]==2&&setting.b[19]==6)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==24&&setting.b[75]==2)switch(v){case 3:return true;}
if(id==24&&setting.b[75]==1)switch(v){case 2:case 3:return true;}
if(id==24&&setting.b[75]==0)switch(v){case 1:case 2:case 3:return true;}
if(id==75&&setting.b[24]==1)switch(v){case 0:return true;}
if(id==75&&setting.b[24]==2)switch(v){case 0:case 1:return true;}
if(id==75&&setting.b[24]==3)switch(v){case 0:case 1:case 2:return true;}
if(id==31&&setting.b[70]==0)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:return true;}
if(id==30&&setting.b[70]==0)switch(v){case 0:case 1:case 2:case 5:case 10:case 30:case 60:return true;}
if(id==32&&setting.b[70]==0)switch(v){case 9:case 10:case 11:case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==31&&setting.b[70]==1)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:return true;}
if(id==29&&setting.b[70]==1)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==32&&setting.b[70]==1)switch(v){case 9:case 10:case 11:case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==29&&setting.b[70]==2)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==30&&setting.b[70]==2)switch(v){case 0:case 1:case 2:case 5:case 10:case 30:case 60:return true;}
if(id==35&&setting.b[70]==2&&setting.b[31]==1)switch(v){case 0:return true;}
if(id==35&&setting.b[70]==2&&setting.b[31]==2)switch(v){case 0:return true;}
if(id==35&&setting.b[70]==2&&setting.b[31]==3)switch(v){case 0:return true;}
if(id==35&&setting.b[70]==2&&setting.b[31]==4)switch(v){case 0:return true;}
if(id==35&&setting.b[70]==2&&setting.b[31]==5)switch(v){case 0:return true;}
if(id==35&&setting.b[70]==2&&setting.b[31]==6)switch(v){case 0:return true;}
if(id==32&&setting.b[70]==2&&setting.b[31]==2)switch(v){case 10:case 11:return true;}
if(id==32&&setting.b[70]==2&&setting.b[31]==3)switch(v){case 10:case 11:case 0:return true;}
if(id==32&&setting.b[70]==2&&setting.b[31]==4)switch(v){case 10:case 11:case 0:case 1:return true;}
if(id==32&&setting.b[70]==2&&setting.b[31]==5)switch(v){case 10:case 11:case 0:case 1:case 2:return true;}
if(id==32&&setting.b[70]==2&&setting.b[31]==6)switch(v){case 10:case 11:case 0:case 1:case 2:case 3:return true;}
if(id==35&&setting.b[34]==0)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:return true;}
if(id==36&&setting.b[34]==0)switch(v){case 0:case 1:return true;}
if(id==38&&setting.b[34]==0)switch(v){case 0:case 1:case 2:return true;}
if(id==76&&setting.b[34]==0)switch(v){case 0:case 1:case 2:case 3:return true;}
if(id==37&&setting.b[34]==0)switch(v){case 0:case 1:case 2:case 3:return true;}
if(id==39&&setting.b[34]==0)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==39&&setting.b[70]==2&&setting.b[31]==1)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==39&&setting.b[70]==2&&setting.b[31]==2)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==39&&setting.b[70]==2&&setting.b[31]==3)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==39&&setting.b[70]==2&&setting.b[31]==4)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==39&&setting.b[70]==2&&setting.b[31]==5)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==39&&setting.b[70]==2&&setting.b[31]==6)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==37&&setting.b[70]==1&&setting.b[30]==0)switch(v){case 2:case 3:return true;}
if(id==37&&setting.b[70]==1&&setting.b[30]==1)switch(v){case 2:case 3:return true;}
if(id==37&&setting.b[76]==2)switch(v){case 3:return true;}
if(id==37&&setting.b[76]==1)switch(v){case 2:case 3:return true;}
if(id==37&&setting.b[76]==0)switch(v){case 1:case 2:case 3:return true;}
if(id==76&&setting.b[37]==1)switch(v){case 0:return true;}
if(id==76&&setting.b[37]==2)switch(v){case 0:case 1:return true;}
if(id==76&&setting.b[37]==3)switch(v){case 0:case 1:case 2:return true;}
if(id==10&&setting.b[68]==1)switch(v){case 0:case 1:return true;}
if(id==11&&setting.b[68]==1)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:return true;}
if(id==12&&setting.b[68]==1)switch(v){case 0:case 1:return true;}
if(id==14&&setting.b[68]==1)switch(v){case 0:case 1:case 2:return true;}
if(id==13&&setting.b[68]==1)switch(v){case 0:case 1:case 2:case 3:case 4:case 7:case 8:return true;}
if(id==15&&setting.b[68]==1)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==73&&setting.b[68]==1)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 11:case 12:case 13:case 14:case 15:case 16:case 17:case 18:case 19:case 20:case 21:case 22:case 23:return true;}
if(id==4&&setting.b[68]==2&&setting.b[2]==12&&setting.b[3]==5)switch(v){case 0:return true;}
if(id==10&&setting.b[68]==2)switch(v){case 0:case 1:return true;}
if(id==11&&setting.b[68]==2)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:return true;}
if(id==12&&setting.b[68]==2)switch(v){case 0:case 1:return true;}
if(id==14&&setting.b[68]==2)switch(v){case 0:case 1:case 2:return true;}
if(id==13&&setting.b[68]==2)switch(v){case 0:case 1:case 2:case 3:case 4:case 7:case 8:return true;}
if(id==15&&setting.b[68]==2)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==73&&setting.b[68]==2)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 11:case 12:case 13:case 14:case 15:case 16:case 17:case 18:case 19:case 20:case 21:case 22:case 23:return true;}
if(id==10&&setting.b[68]==3)switch(v){case 0:case 1:return true;}
if(id==11&&setting.b[68]==3)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:return true;}
if(id==12&&setting.b[68]==3)switch(v){case 0:case 1:return true;}
if(id==14&&setting.b[68]==3)switch(v){case 0:case 1:case 2:return true;}
if(id==13&&setting.b[68]==3)switch(v){case 0:case 1:case 2:case 3:case 4:case 7:case 8:return true;}
if(id==15&&setting.b[68]==3)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==15&&setting.b[68]==3)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:return true;}
if(id==73&&setting.b[68]==3)switch(v){case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:case 10:case 11:case 12:case 13:case 14:case 15:case 16:case 17:case 18:case 19:case 20:case 21:case 22:case 23:return true;}
if(id==74&&setting.b[10]==1&&setting.b[73]==0)switch(v){case 0:case 1:return true;}
if(id==16&&setting.b[53]==0)switch(v){case 0:case 1:case 2:return true;}
if(id==27&&setting.b[53]==0)switch(v){case 0:case 1:case 2:return true;}
if(id==1&&setting.b[53]==1)switch(v){case 0:case 1:case 2:case 3:return true;}
if(id==27&&setting.b[53]==1)switch(v){case 0:case 1:case 2:return true;}
if(id==1&&setting.b[53]==2)switch(v){case 0:case 1:case 2:case 3:return true;}
if(id==16&&setting.b[53]==2)switch(v){case 0:case 1:case 2:return true;}
return false;
}
