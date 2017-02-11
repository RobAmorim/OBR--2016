/*
 * Libray ControlMotorsRobot v.2 
 * -----------------------------------------------------------
 * $Based on Adafruit's library: AFMotor $
 * $Author Alberto Daniel Calvalcante  
 * $Date 2015-06-27 12:49:06 (Sat, 27 Jun 2015) $
 * $Encoders added in 2015-08-02 12:17:39 (Sun, 02 Aug 2015)$
 * -----------------------------------------------------------
 * $Author Roboson Vincius AMorim Silva
 * $Walking with Centimetres added in 2016-08 (july 2016))$
 * $Translat portuguese/English added in 2016-08(Feb 2017) 
 * ----------------------------------------------------------
 */


#ifndef CONTROLMOTORS_H
#define CONTROLMOTORS_H

#include <Arduino.h>
#include "AFMotor.h"
#include "Encoder.h"

//ENCODER - SETTINGS
#define ATTACH1_LEFT 18
#define ATTACH2_LEFT 16

#define ATTACH1_RIGHT 19
#define ATTACH2_RIGHT 17

class Motors
{
public:
	Motors();
	//~Motors();

	void speed(uint8_t speedLeft, uint8_t speedRight);
	void maxSpeed();

	void forward();
	void forward(int ms);
	void forward(uint8_t speedLeft, uint8_t speedRight);
	void forward(uint8_t speedLeft, uint8_t speedRight, int ms);

	void backward();
	void backward(int ms);
	void backward(uint8_t speedLeft, uint8_t speedRight);
	void backward(uint8_t speedLeft, uint8_t speedRight, int ms);

	void right();
	void right(int ms);
	void right(uint8_t speedLeft, uint8_t speedRight);
	void right(uint8_t speedLeft, uint8_t speedRight, int ms);

	void left();
	void left(int ms);
	void left(uint8_t speedLeft, uint8_t speedRight);
	void left(uint8_t speedLeft, uint8_t speedRight, int ms);

	void stop();
	void stop(int ms);
	void stopMicroseconds(int ms);

	//With Encoder

	void forwardEncoder(int pulses);
	void forwardEncoder(int pulses, uint8_t speedLeft, uint8_t speedRight);

	void rightEncoder(int pulses);
	void rightEncoder(int pulses, uint8_t speedLeft, uint8_t speedRight);

	void leftEncoder(int pulses);
	void leftEncoder(int pulses, uint8_t speedLeft, uint8_t speedRight);

	void backwardEncoder(int pulses);
	void backwardEncoder(int pulses, uint8_t speedLeft, uint8_t speedRight);

        void forwardCM(int DistanciaCm);
        void forwardCM(int DistanciaCm, uint8_t speedLeft, uint8_t speedRight);

         void backwardCM(int DistanciaCm);
         void backwardCM(int DistanciaCm, uint8_t speedLeft, uint8_t speedRight);


	void resetEncoders();
private:
	long Delta_RIGHT;
	long Delta_LEFT;
	long ENC_LEFT_Begin;
	long ENC_LEFT_End;
	long ENC_RIGHT_Begin;
	long ENC_RIGHT_End;

	void readBegin();
	void readEnd();
	void DeltaEncoders();
};
#endif

