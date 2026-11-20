#pragma once
#include "Display.h"

void drawStarShape(int x, int y);
void drawStars();
void updateStars();
void drawSpaceship();
void renderStartAnimation();
void drawSpaceshipInGame(int x, int y, int width, int height);

Coordinate getSpaceshipPosition();
void updateSpaceshipPosition(int deltaX, int deltaY);