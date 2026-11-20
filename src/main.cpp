
#include <Arduino.h>
#include <U8g2lib.h>

#include "Spaceship.h"
#include "Input.h"
#include "UFO.h"

void setup()
{
  initDisplay();
  initInputPins();
  Serial.begin(9600);
}

int gameStarted = false;
unsigned long previousMillis = 0;
const unsigned long interval = 2000;

void renderGame()
{
  display.firstPage();
  do
  {
    drawUFOs();
    drawSpaceshipInGame(9, 8);
  } while (display.nextPage());

  delay(30);
}
bool fired = false;
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
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;
    spawnUFO();
  }
  moveUFOs();
  Coordinate spaceshipPos = getSpaceshipPosition();

  if (leftButton == HIGH && spaceshipPos.x > 0)
  {
    Serial.println("Left button pressed");
    updateSpaceshipPosition(-1, 0);
  }
  if (rightButton == HIGH && spaceshipPos.x < 119)
  {
    Serial.println("Right button pressed");
    updateSpaceshipPosition(1, 0);
  }

  if (startButton == HIGH && !fired)
  {
    fired = true;
    // fireBullet(spaceshipPos.x + 3, spaceshipPos.y);
    Serial.println("Start button pressed");
    updateSegmentDisplay(1);
  }
  else if (startButton == LOW)
  {
    fired = false;
  }
}
