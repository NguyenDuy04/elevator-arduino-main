#include "DisplayLCD.h"

DisplayLCD::DisplayLCD()
: lcd(0x27, 16, 2)
{
}

void DisplayLCD::begin()
{
lcd.init();
lcd.backlight();

lcd.clear();
lcd.setCursor(0,0);
lcd.print("Elevator Ready");

}

void DisplayLCD::showFloor(
int currentFloor,
int targetFloor
)
{
lcd.clear();

lcd.setCursor(0,0);
lcd.print("Floor:");
lcd.print(currentFloor);

lcd.setCursor(0,1);
lcd.print("Target:");
lcd.print(targetFloor);

}

void DisplayLCD::showMessage(
const String& line1,
const String& line2
)
{
lcd.clear();

lcd.setCursor(0,0);
lcd.print(line1);

lcd.setCursor(0,1);
lcd.print(line2);

}