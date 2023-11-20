void setup()
{
  
}

void loop()
{
  int dataADC;
  //membaca data digital dari tegangan Potentiometer
  dataADC = analogRead(A0);

  //memetakan nilai 0 - 1023 dari ADC ke nilai 0 - 255
  dataADC = map(dataADC, 0, 1023, 0, 255);

  //menuliskan nilai hasil pemetaan (dalam rentang 0
  //sampai 255) ke LED hijau
  analogWrite(6, dataADC);
}
