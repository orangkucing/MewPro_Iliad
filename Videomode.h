#define SYNC_TIME_HSYNC 0
#define SYNC_TIME_VSYNC 1
#define SYNC_TIME_STRETCH 2
#define FPS_TABLE_SIZE 14

#define SYNC_TIME_720_NARROW  14
#define SYNC_TIME_1080_NARROW 15
#define SYNC_TIME_PHOTO       16

#define _NA_ {0,0,0}

const unsigned int syncTime[][3] PROGMEM = {
// HSYNC duration unit is the number of clock cycles in 16MHz AVR, i.e. 1 clock = 62.5 ns
// VSYNC duration unit is the number of HSYNC pulses
// Note: the 2nd last HSYNC duration followed by VSYNC will be longer than others by STRETCH (clock)
//
// frame per second = 16000000 / (HSYNC * VSYNC + STRETCH)
//
// video modes
// {HSYNC (clock), VSYNC (pulse), STRETCH (clock)}
//240      120          100            90          80          60             50             48             30             25              24              15              12.5            12
// 0x00: 4K 17:9             4096x2160
_NA_,      _NA_,        _NA_,          _NA_,       _NA_,       _NA_,          _NA_,          _NA_,          _NA_,          _NA_,           _NA_,           _NA_,           _NA_,           _NA_,
// 0x01: 4K 16:9             3840x2160
_NA_,      _NA_,        _NA_,          _NA_,       _NA_,       _NA_,          _NA_,          _NA_,          {243,2197,0},  {141,4539,0},   {147,4535,0},   {234,4550,2671},{284,4500,2000},_NA_,
// 0x02: 4K SuperView 16:9   3840x2160
_NA_,      _NA_,        _NA_,          _NA_,       _NA_,       _NA_,          _NA_,          _NA_,          _NA_,          _NA_,           {148,4509,0},   _NA_,           _NA_,           _NA_,
// 0x03: 2.7K 17:9           2704x1440
_NA_,      _NA_,        _NA_,          _NA_,       _NA_,       _NA_,          _NA_,          _NA_,          _NA_,          _NA_,           _NA_,           _NA_,           _NA_,           _NA_,
// 0x04: 2.7K 16:9           2704x1520
_NA_,      _NA_,        _NA_,          _NA_,       _NA_,       {121,2203,132},{140,2286,0},  {219,1520,787},{206,2589,0},  {256,2500,0},   {286,2331,0},   _NA_,           _NA_,           _NA_,
// 0x05: 2.7K SuperView 16:9 2704x1520
_NA_,      _NA_,        _NA_,          _NA_,       _NA_,       _NA_,          _NA_,          _NA_,          {151,3532,0},  {200,3200,0},   _NA_,           _NA_,           _NA_,           _NA_,
// 0x06: 2.7K 4:3            2704x2028
_NA_,      _NA_,        _NA_,          _NA_,       _NA_,       _NA_,          _NA_,          _NA_,          {171,3120,0},  {160,4000,0},   _NA_,           _NA_,           _NA_,           _NA_,
// 0x07: 1440 4:3            1920x1440
_NA_,      _NA_,        _NA_,          _NA_,       {0,0,0},    {78,3422,28},  {89,3600,800}, {86,3850,2567},{171,3120,0},  {160,4000,0},   {213,3121,1408},_NA_,           _NA_,           _NA_,
// 0x08: 1080 SuperView 16:9 1920x1080
_NA_,      _NA_,        _NA_,          _NA_,       {0,0,0},    {78,3422,28},  {89,3600,800}, {86,3850,2567},{171,3120,0},  {160,4000,0},   {213,3121,1408},_NA_,           _NA_,           _NA_,
// 0x09: 1080 16:9           1920x1080   
_NA_,      {118,1131,9},_NA_,          {0,0,0},    _NA_,       {121,2203,132},{142,2254,0},  {151,2205,726},{237,2250,83}, {284,2250,1000},{286,2331,0},   _NA_,           _NA_,           _NA_,
// 0x0a: 960 4:3             1280x960
_NA_,      {0,0,0},     {142,1125,250},_NA_,       _NA_,       {0,0,0},       {89,3600,800}, _NA_,          _NA_,          _NA_,           _NA_,           _NA_,           _NA_,           _NA_,
// 0x0b: 720 SuperView 16:9  1280x720
_NA_,      {0,0,0},     {142,1125,250},_NA_,       _NA_,       {78,3422,28},  {89,3600,800}, _NA_,          _NA_,          _NA_,           _NA_,           _NA_,           _NA_,           _NA_,
// 0x0c: 720 16:9            1280x720
_NA_,      {118,1131,9},_NA_,          _NA_,       _NA_,       {121,2203,132},{142,2250,500},_NA_,          {237,2250,83}, {284,2250,1000},_NA_,           _NA_,           _NA_,           _NA_,
// 0x0d: WVGA 16:9           848x480
{87,767,0},_NA_,        _NA_,          _NA_,       _NA_,       _NA_,          _NA_,          _NA_,          _NA_,          _NA_,           _NA_,           _NA_,           _NA_,           _NA_,
//
// video modes NARROW
// 14:   720 NARROW
{83,804,1},{0,0,0},     _NA_,          _NA_,       _NA_,       {195,1365,314},{222,1440,320},_NA_,          {391,1365,607},{444,1440,640}, _NA_,           _NA_,           _NA_,           _NA_,
// 15:   1080 NARROW
_NA_,      {0,0,0},     _NA_,          {0,0,0},    _NA_,       {195,1365,314},{222,1440,320},{244,1365,615},{391,1365,607},{444,1440,640}, {391,1706,744}, _NA_,           _NA_,           _NA_,
// 
// 16:   photo mode
{146,3640,0}
};
