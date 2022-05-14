#pragma config(Sensor, S4,     ,               sensorEV3_GenericI2C)
#pragma config(Motor,  motorA,          arm1,          tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftM,         tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorC,          rightM,        tmotorEV3_Medium, PIDControl, reversed, encoder)
#pragma config(Motor,  motorD,          arm2,          tmotorEV3_Medium, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "hitechnic-colour-v2.h"

tHTCS2 hi2;
string val;

task main()
{
	/*
	setMotorSpeed(leftM,-10);
	setMotorSpeed(rightM,-10);
	wait1Msec(1000);
	setMotorSpeed(leftM,0);
	setMotorSpeed(rightM,0);
	*/
	initSensor(&hi2, S4);
	setSoundVolume(75);
	playSound(soundBeepBeep);
	sleep(500);

	clearTimer(T1);

	while(time1[T1]<20000) {
		readSensor(&hi2);
		if(hi2.red > 30){
			playSound(soundBeepBeep);
			sleep(2000);
		}
		if(hi2.red > 10 && hi2.red < 25 ){
			playSound(soundBeepBeep);
			playSound(soundBeepBeep);
			sleep(2000);

		}
		val = hi2.red;
		displayBigStringAt(50,50,val);
		sleep(100);

	}
	/*
	displayBigStringAt(50,50,"Red");
	sleep(1000);
	eraseDisplay();
	displayBigStringAt(50,50,"Yellow");
	sleep(1000);
	eraseDisplay();
	displayBigStringAt(50,50,"Black");
	sleep(1000);
	*/
}
