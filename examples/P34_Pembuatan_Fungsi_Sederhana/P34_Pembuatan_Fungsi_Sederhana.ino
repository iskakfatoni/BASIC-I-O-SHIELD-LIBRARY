//penyertaan library BasicIOShield dan Wire
#include <BasicIOShield.h>
#include <Wire.h>
BasicIOShield shield; //objek BASIC I/O SHIELD

//fungsi untuk menyalakan dan memadamkan 4 buah LED dengan
//delay 1 detik
void blinkLED()
{
  shield.RedOn();
  shield.GreenOn();
  shield.BlueOn();
  shield.YellowOn();
  delay(1000);
  shield.RedOff();
  shield.GreenOff();
  shield.BlueOff();
  shield.YellowOff();
  delay(1000);
}

void setup()
{
  
}

void loop()
{
  //pemanggilan fungsi blinkLED
  blinkLED();
}
