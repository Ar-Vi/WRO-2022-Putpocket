#pragma config(Sensor, S1,     LeftCol,        sensorEV3_Color)
#pragma config(Sensor, S2,     Ultra,          sensorEV3_Ultrasonic)
#pragma config(Sensor, S3,     RightCol,       sensorEV3_Color)
#pragma config(Sensor, S4,     HighCol,        sensorEV3_Color)
#pragma config(Motor,  motorA,          rackArm,       tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Medium, PIDControl, reversed, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Medium, PIDControl, driveRight, encoder)
#pragma config(Motor,  motorD,          clawArm,       tmotorEV3_Medium, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#include "helper.h"

void revDropWater_L(){

	moveForward(1, -20, 30);
	moveForward(3, -20, 50);
	lineSquare(2000, 50, 0.2);
	moveForward(5, 20, 10);

	moveTank(1 ,-20 ,20 ,300);
	stopRobot();


	//at table
	moveForward(3, 20, 100);
	moveRack(20, 500);
	wait1Msec(500);
	moveForward(3, -20, 60);
	moveRack(-20, 500);
	stopRobot();
	moveForward(3, -20, 100);
	moveForward(3, 20, 30);
	moveTank(1, 20, -20, 280);

	//goto laundry

	moveForward(3, -20, 600);



	moveTank(1, 20, -20, 80);
	stopRobot();
	setMotorSpeed(clawArm, -50);
	wait1Msec(2200);

	stopRobot()
	moveForward(3, 20, 280);
	stopRobot()
	wait1Msec(1000);
	setMotorSpeed(clawArm, 80);
	wait1Msec(1500);
	stopRobot();

	//Turn to go bACK HOMEE
	moveForward(3, -20, 130);
	moveTank(1, -20, 20, 80);

	moveForward(1, -20, 30);

	moveTank(1, 20, -20, 280);
	moveForward(3, -20, 650);
	moveForward(3, 60, 1800);



};

task main()
{

	revDropWater_L();


}
