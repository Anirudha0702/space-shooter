#include "Spaceship.h"

int starY1 = 12;
int starY2 = 15;
int starY3 = 45;
int starY4 = 48;

// Star shape positions
int shapeY1 = 16;
int shapeY2 = 30;

//  ionitially spaceship shoud be at bottom center
int spaceshipX = 61;// bullet start x will be alwasy +3
int spaceshipY = 56; //bullet start y will be always same

int bulletX = spaceshipX + 3;
int bulletY = spaceshipY;
void drawStarShape(int x, int y)
{
  int top = y - 3;
  int bottom = y + 3;

  // Completely outside screen
  if (bottom < 0 || top >= 64)
    return;

  // Keep vertical line inside display
  if (top < 0)
    top = 0;
  if (bottom > 63)
    bottom = 63;

  display.drawLine(x, top, x, bottom);

  // Draw horizontal line only when visible
  if (y >= 0 && y < 64)
  {
    display.drawLine(x - 3, y, x + 3, y);
  }
}

void drawStars()
{
  // Small stars
  display.drawPixel(15, starY1);
  display.drawPixel(105, starY2);
  display.drawPixel(25, starY3);
  display.drawPixel(95, starY4);

  // Star shapes
  drawStarShape(30, shapeY1);
  drawStarShape(100, shapeY2);
}

void updateStars()
{
  // Move stars downward
  starY1 += 1;
  starY2 += 2;
  starY3 += 1;
  starY4 += 2;

  shapeY1 += 1;
  shapeY2 += 2;

  // Reset when stars leave the screen
  if (starY1 >= 64)
    starY1 = 0;
  if (starY2 >= 64)
    starY2 = 0;
  if (starY3 >= 64)
    starY3 = 0;
  if (starY4 >= 64)
    starY4 = 0;

  // Account for the 3-pixel star shape radius
  if (shapeY1 >= 67)
    shapeY1 = -3;
  if (shapeY2 >= 67)
    shapeY2 = -3;
}

void drawSpaceship()
{
  // Spaceship nose
  display.drawLine(56, 23, 64, 8);
  display.drawLine(64, 8, 72, 23);
  display.drawLine(56, 23, 72, 23);

  // Main body
  display.drawFrame(56, 24, 17, 25);

  // Cockpit window
  display.drawCircle(64, 33, 5);
  display.drawDisc(64, 33, 2);

  // Wings
  display.drawLine(56, 39, 47, 51);
  display.drawLine(47, 51, 56, 48);

  display.drawLine(72, 39, 81, 51);
  display.drawLine(81, 51, 72, 48);

  // Engine
  display.drawFrame(60, 49, 9, 4);

  // Flames
  display.drawLine(61, 53, 64, 62);
  display.drawLine(64, 62, 67, 53);
  display.drawLine(64, 53, 64, 58);
}

void renderStartAnimation()
{
  display.firstPage();
  do
  {
    drawStars();
    drawSpaceship();
  } while (display.nextPage());

  // Update positions AFTER rendering
  updateStars();
  delay(30);
}

void drawSpaceshipInGame( int width, int height)
{
    int x=spaceshipX;
    int y=spaceshipY;
  if (width <= 0 || height <= 0)
    return;

  // 9x8 spaceship pixel pattern
  const uint16_t ship[8] = {
      0b000010000,
      0b000111000,
      0b001111100,
      0b001101100,
      0b001111100,
      0b011111110,
      0b100111001,
      0b000010000};

  for (int row = 0; row < 8; row++)
  {
    for (int col = 0; col < 9; col++)
    {
      if (ship[row] & (1 << (8 - col)))
      {
        int px = x + (col * width) / 9;
        int py = y + (row * height) / 8;

        int pw = ((col + 1) * width) / 9 - (col * width) / 9;

        int ph = ((row + 1) * height) / 8 - (row * height) / 8;

        if (pw > 0 && ph > 0)
          display.drawBox(px, py, pw, ph);
      }
    }
  }
}


Coordinate getSpaceshipPosition()
{
  return {spaceshipX, spaceshipY};
}

void updateSpaceshipPosition(int deltaX, int deltaY)
{
  spaceshipX += deltaX;
  spaceshipY += deltaY;

  // Ensure the spaceship stays within the display boundaries
  if (spaceshipX < 0)
    spaceshipX = 0;
  if (spaceshipX > 119) // 128 - spaceship width (9)
    spaceshipX = 119;
  if (spaceshipY < 0)
    spaceshipY = 0;
  if (spaceshipY > 56) // 64 - spaceship height (8)
    spaceshipY = 56;
}