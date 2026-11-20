#pragma once
#include "Display.h"


struct UFO
{
    uint8_t x;
    uint8_t y;
    uint8_t health;
};
void spawnUFO();
void drawUFO(uint8_t x, uint8_t y);
void drawUFOs();
void moveUFOs();