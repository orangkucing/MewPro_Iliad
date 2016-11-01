#define SYNC_TIME_HSYNC 0
#define SYNC_TIME_VSYNC 1
#define FPS_TABLE_SIZE 14

#define _NA_ {0, 0}

const unsigned int syncTime[][2] = {
// HSYNC duration unit is the number of clock cycles in 16MHz AVR, i.e. 1 clock = 62.5 ns
// VSYNC duration unit is the number of HSYNC pulses
//
// frame per second = 16000000 / (HSYNC * VSYNC)
//
// video modes
// {HSYNC (clock), VSYNC (pulse)}
//240     120        100        90         80         60         50         48         30         25         24         15         12.5      12
// 0x00: 4K 17:9             4096x2160
_NA_,     _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,
// 0x01: 4K 16:9             3840x2160
_NA_,     _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      {118,4520},{141,4539},{147,4535},_NA_,      _NA_,      _NA_,
// 0x02: 4K SuperView 16:9   3840x2160
_NA_,     _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      {147,4535},_NA_,      _NA_,
// 0x03: 2.7K 17:9           2704x1440
_NA_,     _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,
// 0x04: 2.7K 16:9           2704x1520
_NA_,     _NA_,      _NA_,      _NA_,      _NA_,      {118,2260},{140,2286},{146,2283},{206,2589},{256,2500},{286,2331},_NA_,      _NA_,      _NA_,
// 0x05: 2.7K SuperView 16:9 2704x1520
_NA_,     _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      {206,2589},{256,2500},_NA_,      _NA_,      _NA_,      _NA_,
// 0x06: 2.7K 4:3            2704x2028
_NA_,     _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      {171,3120},{160,4000},_NA_,      _NA_,      _NA_,      _NA_,
// 0x07: 1440 4:3            1920x1440
_NA_,     _NA_,      _NA_,      _NA_,      {50,4000}, {78,3432}, {89,3600}, {87,3831}, {171,3120},{160,4000},{213,3130},_NA_,      _NA_,      _NA_,
// 0x08: 1080 SuperView 16:9 1920x1080
_NA_,     _NA_,      _NA_,      _NA_,      {50,4000}, {78,3432}, {89,3600}, {87,3831}, {171,3120},{160,4000},{146,4566},_NA_,      _NA_,      _NA_,
// 0x09: 1080 16:9           1920x1080   
_NA_,     _NA_,      _NA_,      {100,1778},_NA_,      {133,2005},{142,2254},_NA_,      _NA_,      _NA_,      {286,2331},_NA_,      _NA_,      _NA_,
// 0x0a: 960 4:3             1280x960
_NA_,     {119,1120},_NA_,      _NA_,      _NA_,      {242,1100},{89,3600}, _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,
// 0x0b: 720 SuperView 16:9  1280x720
_NA_,     {173,771}, _NA_,      _NA_,      _NA_,      {121,2200},{142,2254},_NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,
// 0x0c: 720 16:9            1280x720
_NA_,     _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,
// 0x0d: WVGA 16:9           848x480
_NA_,     _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,      _NA_,
// photo mode
{146,3640}
};
