#include <BasicIOShield.h>

BasicIOShield::BasicIOShield()
{
	angka0[0] = HIGH; angka0[1] = HIGH; angka0[2] = HIGH; angka0[3] = HIGH; angka0[4] = HIGH; angka0[5] = HIGH; angka0[6] = LOW; angka0[7] = LOW;
	angka1[0] = LOW; angka1[1] = HIGH; angka1[2] = HIGH; angka1[3] = LOW; angka1[4] = LOW; angka1[5] = LOW; angka1[6] = LOW; angka1[7] = LOW;
	angka2[0] = HIGH; angka2[1] = HIGH; angka2[2] = LOW; angka2[3] = HIGH; angka2[4] = HIGH; angka2[5] = LOW; angka2[6] = HIGH; angka2[7] = LOW;
	angka3[0] = HIGH; angka3[1] = HIGH; angka3[2] = HIGH; angka3[3] = HIGH; angka3[4] = LOW; angka3[5] = LOW; angka3[6] = HIGH; angka3[7] = LOW;
	angka4[0] = LOW; angka4[1] = HIGH; angka4[2] = HIGH; angka4[3] = LOW; angka4[4] = LOW; angka4[5] = HIGH; angka4[6] = HIGH; angka4[7] = LOW;
	angka5[0] = HIGH; angka5[1] = LOW; angka5[2] = HIGH; angka5[3] = HIGH; angka5[4] = LOW; angka5[5] = HIGH; angka5[6] = HIGH; angka5[7] = LOW;
	angka6[0] = HIGH; angka6[1] = LOW; angka6[2] = HIGH; angka6[3] = HIGH; angka6[4] = HIGH; angka6[5] = HIGH; angka6[6] = HIGH; angka6[7] = LOW;
	angka7[0] = HIGH; angka7[1] = HIGH; angka7[2] = HIGH; angka7[3] = LOW; angka7[4] = LOW; angka7[5] = LOW; angka7[6] = LOW; angka7[7] = LOW;
	angka8[0] = HIGH; angka8[1] = HIGH; angka8[2] = HIGH; angka8[3] = HIGH; angka8[4] = HIGH; angka8[5] = HIGH; angka8[6] = HIGH; angka8[7] = LOW;
	angka9[0] = HIGH; angka9[1] = HIGH; angka9[2] = HIGH; angka9[3] = HIGH; angka9[4] = LOW; angka9[5] = HIGH; angka9[6] = HIGH; angka9[7] = LOW;
	
	_LEDsPin[GREEN_ARRAY] = GREEN_PIN;
	_LEDsPin[BLUE_ARRAY] = BLUE_PIN;
	_LEDsPin[YELLOW_ARRAY] = YELLOW_PIN;
	_LEDsPin[RED_ARRAY] = RED_PIN;
	_ButtonsPin[BUTTON_1_ARRAY] = BUTTON_1_PIN;
	_ButtonsPin[BUTTON_2_ARRAY] = BUTTON_2_PIN;
	_SegmentsPin[SEGMENT_A_ARRAY] = SEGMENT_A_PIN;
	_SegmentsPin[SEGMENT_B_ARRAY] = SEGMENT_B_PIN;
	_SegmentsPin[SEGMENT_C_ARRAY] = SEGMENT_C_PIN;
	_SegmentsPin[SEGMENT_D_ARRAY] = SEGMENT_D_PIN;
	_SegmentsPin[SEGMENT_E_ARRAY] = SEGMENT_E_PIN;
	_SegmentsPin[SEGMENT_F_ARRAY] = SEGMENT_F_PIN;
	_SegmentsPin[SEGMENT_G_ARRAY] = SEGMENT_G_PIN;
	_SegmentsPin[SEGMENT_DP_ARRAY] = SEGMENT_DP_PIN;
	_SevenSegmentsPin[SEVEN_SEGMENT_1_ARRAY] = SEVEN_SEGMENT_1_PIN;
	_SevenSegmentsPin[SEVEN_SEGMENT_2_ARRAY] = SEVEN_SEGMENT_2_PIN;
	
	for(int i = 0; i < 4; i++)
		pinMode(_LEDsPin[i], OUTPUT);
	for(int i = 0; i < 2; i++)
		pinMode(_ButtonsPin[i], INPUT);
	for(int i = 0; i < 8; i++)
		pinMode(_SegmentsPin[i], OUTPUT);
	for(int i = 0; i < 2; i++)
		pinMode(_SevenSegmentsPin[i], OUTPUT);
	
	Wire.begin();
}

word BasicIOShield::ReadPotentiometer()
{
	return analogRead(POTENTIOMETER_PIN);
}

void BasicIOShield::RedOn()
{
	digitalWrite(_LEDsPin[RED_ARRAY], HIGH);
}

void BasicIOShield::RedOff()
{
	digitalWrite(_LEDsPin[RED_ARRAY], LOW);
}

void BasicIOShield::GreenOn()
{
	digitalWrite(_LEDsPin[GREEN_ARRAY], HIGH);
}

void BasicIOShield::GreenOff()
{
	digitalWrite(_LEDsPin[GREEN_ARRAY], LOW);
}

void BasicIOShield::BlueOn()
{
	digitalWrite(_LEDsPin[BLUE_ARRAY], HIGH);
}

void BasicIOShield::BlueOff()
{
	digitalWrite(_LEDsPin[BLUE_ARRAY], LOW);
}

void BasicIOShield::YellowOn()
{
	digitalWrite(_LEDsPin[YELLOW_ARRAY], HIGH);
}

void BasicIOShield::YellowOff()
{
	digitalWrite(_LEDsPin[YELLOW_ARRAY], LOW);
}

boolean BasicIOShield::Button1State()
{
	return digitalRead(_ButtonsPin[BUTTON_1_ARRAY]);
}

boolean BasicIOShield::Button2State()
{
	return digitalRead(_ButtonsPin[BUTTON_2_ARRAY]);
}

void BasicIOShield::SegmentsPinWrite(byte number[])
{
	for(byte i = 0; i < 8; i++)
	{
		digitalWrite(_SegmentsPin[i], number[i]);
		Serial.println(_SegmentsPin[i]);
		Serial.println(number[i]);
	}
}

void BasicIOShield::SevenSegment(byte number)
{
	switch(number)
	{
		case 0:
			SegmentsPinWrite(angka0);
			break;
		case 1:
			SegmentsPinWrite(angka1);
			break;
		case 2:
			SegmentsPinWrite(angka2);
			break;
		case 3:
			SegmentsPinWrite(angka3);
			break;
		case 4:
			SegmentsPinWrite(angka4);
			break;
		case 5:
			SegmentsPinWrite(angka5);
			break;
		case 6:
			SegmentsPinWrite(angka6);
			break;
		case 7:
			SegmentsPinWrite(angka7);
			break;
		case 8:
			SegmentsPinWrite(angka8);
			break;
		case 9:
			SegmentsPinWrite(angka9);
			break;
	}
}

void BasicIOShield::PrintSevenSegment(byte number, byte times, byte delayTime)
{
	byte puluhan = number / 10;
	byte satuan = number % 10;
	
	for(word loopTimes = 0; loopTimes < times; loopTimes++)
	{
		digitalWrite(SEVEN_SEGMENT_1_PIN, LOW);
		digitalWrite(SEVEN_SEGMENT_2_PIN, LOW);
		SevenSegment(puluhan);
		digitalWrite(SEVEN_SEGMENT_1_PIN, LOW);
		digitalWrite(SEVEN_SEGMENT_2_PIN, HIGH);
		delay(delayTime);
		
		digitalWrite(SEVEN_SEGMENT_1_PIN, LOW);
		digitalWrite(SEVEN_SEGMENT_2_PIN, LOW);
		SevenSegment(satuan);
		digitalWrite(SEVEN_SEGMENT_1_PIN, HIGH);
		digitalWrite(SEVEN_SEGMENT_2_PIN, LOW);
		delay(delayTime);
	}
}

bool BasicIOShield::WriteDAC(word value)
{
	value <<= 2;
	Wire.beginTransmission(AD5612Address);
	byte temp = (value >> 8 & 0x0F);
	Wire.write(temp);
	temp = (value & 0xFF);
	Wire.write(temp);
	return (Wire.endTransmission() == 0);
}