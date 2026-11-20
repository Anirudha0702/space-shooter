#pragma once
#include <U8g2lib.h>
#include <TM1637Display.h>
#define CLK 2
#define DIO 3

extern U8G2_SH1106_128X64_NONAME_1_HW_I2C display;
extern TM1637Display segmentDisplay;

struct Coordinate {
    uint8_t x;
    uint8_t y;
};
void initDisplay();
void clearDisplay();
void updateSegmentDisplay(int number);

