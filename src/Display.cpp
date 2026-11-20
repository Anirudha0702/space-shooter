#include "display.h"

U8G2_SH1106_128X64_NONAME_1_HW_I2C display(
    U8G2_R0, U8X8_PIN_NONE);

TM1637Display segmentDisplay(CLK, DIO);

int number = 0;
void initDisplay()
{
    display.begin();
    segmentDisplay.setBrightness(7);
    segmentDisplay.showNumberDec(0, true);
}

void clearDisplay()
{
    display.clearDisplay();
    segmentDisplay.clear();
}
void updateSegmentDisplay(int delta)
{
    number += delta;
    segmentDisplay.showNumberDec(number, true);
}
