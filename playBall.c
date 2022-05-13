#include "helper.h"


void playBall(){

	displayBigStringAt(50,50,"play ball");
	stopRobot();

	moveTank(1, 20, -20, 30);
	moveForward(3, 20, 140);
	stopRobot();


	//turn to and pickup ball


	moveTank(1, -20, 20, 150);
	moveForward(3, 20, 25);
	moveTank(3, -5, 5, 16);
	stopRobot();
	moveTank(2, -5, 5, 12);
	moveTank(1, -5, 5, 10);
	moveForward(3, -10, 20);

	moveClaw(-50, 2000);
	stopRobot();

	moveForward(5, 5, 6);

	moveClaw(100, 1500);
	stopRobot();
	moveForward(3, -20, 70);

	//turn to drop ball

	moveTank(1, 20, -20, 265);
	moveForward(3, 20, 70);
	stopRobot();

	moveClaw(-40, 1500);
	stopRobot();
	wait1Msec(100);

	moveClaw(40, 1500);
	stopRobot();
	moveForward(3, -20, 40);

		//cha cha to line!!

	moveTank(1, -20, 20, 115);
			moveForward(3, -30, 300);
			moveTank(1, -20, 20, 15);




}
