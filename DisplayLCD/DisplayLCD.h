#ifndef DISPLAY_LCD_H
#define DISPLAY_LCD_H

#include <LiquidCrystal_I2C.h>

class DisplayLCD {
private:
LiquidCrystal_I2C lcd;

public:
DisplayLCD();

void begin();

void showFloor(int currentFloor, int targetFloor);

void showMessage(const String& line1,
                 const String& line2 = "");

};

#endif