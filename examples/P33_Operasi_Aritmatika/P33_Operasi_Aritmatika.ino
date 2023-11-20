//penyertaan library BasicIOShield dan Wire
#include <BasicIOShield.h>
#include <Wire.h>
BasicIOShield shield; //objek BASIC I/O SHIELD
char value; //variabel penampung data

void setup()
{
  //(5 * 3) + (4 / 2)
  value = 5 * 3 + 4 / 2;
}

void loop()
{
  //mencetak nilai variabel value ke seven segment
  shield.PrintSevenSegment(value);
}
