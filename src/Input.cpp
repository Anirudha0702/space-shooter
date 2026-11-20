#include <Arduino.h>
#include "Input.h"

int readInput(int button)
{
    if (button == START_PIN)
        return digitalRead(START_PIN);
    if (button == LEFT_PIN)
        return digitalRead(LEFT_PIN);
    if (button == RESET_PIN)
        return digitalRead(RESET_PIN);

    return -1;
}
void initInputPins()
{
    pinMode(START_PIN, INPUT);
    pinMode(LEFT_PIN, INPUT);
    pinMode(RESET_PIN, INPUT);
}