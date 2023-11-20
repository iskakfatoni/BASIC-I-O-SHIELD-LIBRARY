//penyertaan library BasicIOShield
#include <BasicIOShield.h>
//penyertaan library Wire
#include <Wire.h>
BasicIOShield shield; //deklarasi objek BasicIOShield

void setup()
{
  //pin 8 yang terhubung dengan LED kuning
  //dikonfigurasikan sebagai input, karena nyala
  //LED kuning akan dikendalikan oleh output DAC
  pinMode(8, INPUT);
}

void loop()
{
  //output on-off
  //LED merah berkedip dengan durasi 2 detik
  
  for(int i = 0; i < 3; i++)
  {
    shield.RedOn();
    delay(2000);
    shield.RedOff();
    delay(2000);
  }
  
  //output pseudo-analog
  //LED hijau menyala dan padam secara bertahap
  //dengan durasi ~2 detik
  for(int i = 0; i < 3; i++)
  {
    for(int i = 0; i < 1024; i++)
    {
      analogWrite(6, map(i, 0, 1023, 0, 255));
      delay(2);
    }
    for(int i = 1023; i > 0; i--)
    {
      analogWrite(6, map(i, 0, 1023, 0, 255));
      delay(2);
    }
  }
  
  //output analog dari DAC
  //LED kuning menyala dan padam secara bertahap
  //dengan durasi ~2 detik
  for(int i = 0; i < 3; i++)
  {
    for(int i = 0; i < 1024; i++)
    {
      shield.WriteDAC(i);
      delay(2);
    }
    for(int i = 1023; i > 0; i--)
    {
      shield.WriteDAC(i);
      delay(2);
    }
  }
}
