
#include "Display.h"

struct Bullet
{
    int x;
    int y;
    bool active;
};

static Bullet bullets[10];

void fireBullet(int x, int y)
{
    for (int i = 0; i < 10; i++)
    {
        if (!bullets[i].active)
        {
            bullets[i] = {x, y, true};
            return;
        }
    }
}

void updateBullets()
{
    for (int i = 0; i < 10; i++)
    {
        if (!bullets[i].active)
            continue;

        bullets[i].y -= 2;

        if (bullets[i].y < 0)
            bullets[i].active = false;
    }
}

void drawBullets()
{
    for (int i = 0; i < 10; i++)
    {
        if (!bullets[i].active)
            continue;

        display.drawPixel(bullets[i].x, bullets[i].y);
    }
}