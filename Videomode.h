#define SYNC_TIME_HSYNC 0
#define SYNC_TIME_VSYNC 1
#define SYNC_TIME_STRETCH 2
#define FPS_TABLE_SIZE 14

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
//240      120          100          90          80          60             50             48           30            25             24           15           12.5         12
// 0x00: 4K 17:9             4096x2160
_NA_,      _NA_,        _NA_,        _NA_,       _NA_,       _NA_,          _NA_,          _NA_,        _NA_,         _NA_,          _NA_,        _NA_,        _NA_,        _NA_,
// 0x01: 4K 16:9             3840x2160
_NA_,      _NA_,        _NA_,        _NA_,       _NA_,       _NA_,          _NA_,          _NA_,        {236,2260,0}, {141,4539,0},  {147,4535,0},{234,4558,0},{284,4507,0},_NA_,
// 0x02: 4K SuperView 16:9   3840x2160
_NA_,      _NA_,        _NA_,        _NA_,       _NA_,       _NA_,          _NA_,          _NA_,        _NA_,         _NA_,          {148,4509,0},_NA_,        _NA_,        _NA_,
// 0x03: 2.7K 17:9           2704x1440
_NA_,      _NA_,        _NA_,        _NA_,       _NA_,       _NA_,          _NA_,          _NA_,        _NA_,         _NA_,          _NA_,        _NA_,        _NA_,        _NA_,
// 0x04: 2.7K 16:9           2704x1520
_NA_,      _NA_,        _NA_,        _NA_,       _NA_,       {121,2203,132},  {140,2286,0},  {117,2849,0},{206,2589,0}, {256,2500,0},  {286,2331,0},_NA_,        _NA_,        _NA_,
// 0x05: 2.7K SuperView 16:9 2704x1520
_NA_,      _NA_,        _NA_,        _NA_,       _NA_,       _NA_,          _NA_,          _NA_,        {151,3532,0}, {200,3200,0},  _NA_,        _NA_,        _NA_,        _NA_,
// 0x06: 2.7K 4:3            2704x2028
_NA_,      _NA_,        _NA_,        _NA_,       _NA_,       _NA_,          _NA_,          _NA_,        {171,3120,0}, {160,4000,0},  _NA_,        _NA_,        _NA_,        _NA_,
// 0x07: 1440 4:3            1920x1440
_NA_,      _NA_,        _NA_,        _NA_,       {50,4000,0},{78,3432,0},   {89,3600,0},   {87,3831,0}, {171,3120,0}, {160,4000,0},  {213,3130,0},_NA_,        _NA_,        _NA_,
// 0x08: 1080 SuperView 16:9 1920x1080
_NA_,      _NA_,        _NA_,        _NA_,       {50,4000,0},{78,3432,0},   {89,3600,0},   {222,1503,0},{171,3120,0}, {160,4000,0},  {213,3130,0},_NA_,        _NA_,        _NA_,
// 0x09: 1080 16:9           1920x1080   
_NA_,      {82,1626,0}, _NA_,        {82,2168,0},_NA_,       {121,2203,132},{142,2254,0},  {144,2314,8},{237,2250,83},{284,2253,146},{286,2331,0},_NA_,        _NA_,        _NA_,
// 0x0a: 960 4:3             1280x960
_NA_,      {82,1626,0}, {142,1127,0},_NA_,       _NA_,       {133,2005,0},  {89,3600,0},   _NA_,        _NA_,         _NA_,          _NA_,        _NA_,        _NA_,        _NA_,
// 0x0b: 720 SuperView 16:9  1280x720
_NA_,      {173,771,0}, {141,1135,0},_NA_,       _NA_,       {121,2200,0},  {142,2254,0},  _NA_,        _NA_,         _NA_,          _NA_,        _NA_,        _NA_,        _NA_,
// 0x0c: 720 16:9            1280x720
{83,804,0},{173,771,27},_NA_,        _NA_,       _NA_,       {121,2203,132},{142,2250,500},_NA_,        {237,2250,83},{284,2253,146},_NA_,        _NA_,        _NA_,        _NA_,
// 0x0d: WVGA 16:9           848x480
_NA_,      _NA_,        _NA_,        _NA_,       _NA_,       _NA_,          _NA_,          _NA_,        _NA_,         _NA_,          _NA_,        _NA_,        _NA_,        _NA_,
// 16MHz AVR cannot do the following WVGA 240fps (240.5fps)
//{80.5, 825, 116.5}
// photo mode
{146,3640,0}
};
