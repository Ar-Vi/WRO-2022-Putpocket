#include "helper.h"

void dropWater(){

displayBigStringAt(50,50,"drop water NO L");
	wait1Msec(300);
	stopRobot();
	moveTank(1 ,20 ,-20 ,280);


	stopRobot();


	//at table
	moveForward(3, 20, 50);
	moveRack(20, 500);
	wait1Msec(200);
	moveForward(3, -20, 60);
	moveRack(-20, 500);
	stopRobot();
	moveForward(3, -20, 100);
	stopRobot();
	wait1Msec(300);
	moveForward(3, 20, 30);
	moveTank(1, -20, 20, 320);
	moveForward(3, -30, 90);

	//chachahome?





}
