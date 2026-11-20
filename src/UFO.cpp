#include "UFO.h"

#define MAX_UFO_COUNT 7
int ufoCount = 0;
UFO ufos[MAX_UFO_COUNT];
void spawnUFO()
{
    if (ufoCount >= MAX_UFO_COUNT)
        return;

    uint8_t ufoX = random(0, 120);
    uint8_t ufoY = random(0, 50);

    ufos[ufoCount] = {ufoX, ufoY};

    ++ufoCount;
}

const uint8_t ufoBitmap[5] = {
    0b00011000,
    0b00111100,
    0b11111111,
    0b01011010,
    0b10011001
};

void drawUFO(uint8_t x, uint8_t y)
{
    for (uint8_t row = 0; row < 5; row++)
    {
        for (uint8_t col = 0; col < 8; col++)
        {
            if (ufoBitmap[row] & (1 << (7 - col)))
            {
                display.drawPixel(x + col, y + row);
            }
        }
    }
}
void drawUFOs()
{
    display.firstPage();
    do
    {
        for (int i = 0; i < ufoCount; ++i)
        {
            drawUFO(ufos[i].x, ufos[i].y);
        }
    } while (display.nextPage());
}


void moveUFOs()
{
    for (int i = 0; i < ufoCount; ++i)
    {
        ufos[i].y += 1; // Move UFO downwards
        if (ufos[i].y > 64) // If UFO goes off the screen
        {
            // Remove UFO by shifting the array
            for (int j = i; j < ufoCount - 1; ++j)
            {
                ufos[j] = ufos[j + 1];
            }
            --ufoCount;
            --i; // Adjust index to check the new UFO at this position
        }
    }
}