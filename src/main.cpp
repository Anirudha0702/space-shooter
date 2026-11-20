
#include <Arduino.h>
#include <U8g2lib.h>



#include "Spaceship.h"
#include "Input.h"



void setup()
{
  initDisplay();
  initInputPins();
}
int number = 0;

int gameStarted = false;


void renderGame()
{
  display.firstPage();
  do
  {
    drawSpaceshipInGame(61, 56, 9, 8);
  } while (display.nextPage());

  delay(30);
}

void loop()
{
  if (!gameStarted)
  {
    renderStartAnimation();
  }
  int startButton = readInput(START_PIN);
  int leftButton = readInput(LEFT_PIN);
  int rightButton = readInput(RESET_PIN);

  if (!gameStarted && startButton == HIGH)
  {
    gameStarted = true;
  }
  if (!gameStarted)
    return;

  renderGame();
  Coordinate spaceshipPos = getSpaceshipPosition();
  if (leftButton == HIGH && spaceshipPos.x > 0)
  {
    updateSpaceshipPosition(-1, 0);
  }
  if (rightButton == HIGH && spaceshipPos.x < 119)
  {
    updateSpaceshipPosition(1, 0);
  }
  
  if(startButton == HIGH)
  {
    fireBullet(spaceshipPos.x + 3, spaceshipPos.y);
  }
}
