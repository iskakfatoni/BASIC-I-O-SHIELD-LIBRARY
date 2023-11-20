/***************************************************************************
Title: BASIC I/O SHIELD V1.0
Created by: Innovative Electronics - Training Division
For: Arduino Training - Basic

This file is free software; you can redistribute it and/or modify
it under the terms of either the GNU General Public License version 2
or the GNU Lesser General Public License version 2.1, both as
published by the Free Software Foundation.
***************************************************************************/

#ifndef BasicIOShield_h
#define BasicIOShield_h

#include <Arduino.h>
#include <Wire.h>

#define POTENTIOMETER_PIN A1
#define GREEN_PIN 6
#define BLUE_PIN 7
#define YELLOW_PIN 8
#define RED_PIN 9
#define BUTTON_1_PIN 2
#define BUTTON_2_PIN 4
#define SEVEN_SEGMENT_1_PIN A2
#define SEVEN_SEGMENT_2_PIN A3
#define SEGMENT_A_PIN 6
#define SEGMENT_B_PIN 7
#define SEGMENT_C_PIN 8
#define SEGMENT_D_PIN 9
#define SEGMENT_E_PIN 10
#define SEGMENT_F_PIN 11
#define SEGMENT_G_PIN 12
#define SEGMENT_DP_PIN 13

#define GREEN_ARRAY 0
#define BLUE_ARRAY 1
#define YELLOW_ARRAY 2
#define RED_ARRAY 3
#define BUTTON_1_ARRAY 0
#define BUTTON_2_ARRAY 1
#define SEGMENT_A_ARRAY 0
#define SEGMENT_B_ARRAY 1
#define SEGMENT_C_ARRAY 2
#define SEGMENT_D_ARRAY 3
#define SEGMENT_E_ARRAY 4
#define SEGMENT_F_ARRAY 5
#define SEGMENT_G_ARRAY 6
#define SEGMENT_DP_ARRAY 7
#define SEVEN_SEGMENT_1_ARRAY 0
#define SEVEN_SEGMENT_2_ARRAY 1

#define AD5612Address 0x0E

class BasicIOShield
{
	public :
		BasicIOShield();
		word ReadPotentiometer();
		void RedOn();
		void RedOff();
		void GreenOn();
		void GreenOff();
		void BlueOn();
		void BlueOff();
		void YellowOn();
		void YellowOff();
		bool Button1State();
		bool Button2State();
		void PrintSevenSegment(byte number, byte times = 10, byte delayTime = 5);
		bool WriteDAC(word value);

	private :
		byte angka0[8];
		byte angka1[8];
		byte angka2[8];
		byte angka3[8];
		byte angka5[8];
		byte angka4[8];
		byte angka6[8];
		byte angka7[8];
		byte angka8[8];
		byte angka9[8];
		byte _LEDsPin[4];
		byte _ButtonsPin[2];
		byte _SegmentsPin[8];
		byte _SevenSegmentsPin[2];
		void SevenSegment(byte number);
		void SegmentsPinWrite(byte number[]);
};

#endif