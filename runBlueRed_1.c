#include "helper.h"

int col;
int marker;
string val;
void
 runBlueRed_1() {


	moveForward(3, 20, 45);
	moveTank(1, -20, 20, 290);
	stopRobot();

	moveRack(-20, 600);
	moveClaw(20,200);
	wait1Msec(100);
	moveForward(3, 20, 30);

	moveForward(1, -20, 30);
	moveForward(3, -20, 50);
	lineSquare(1500, 40, 0.2);

	moveForward(3, 20, 100);
	initSensor(&hi2, S4);
	while (hi2.red < 10){
		initSensor(&hi2, S4);
		setMotorSpeed(leftMotor, 10);
		setMotorSpeed(rightMotor, 10);
		readSensor(&hi2);
		val = hi2.red;
		displayBigStringAt(50,50,val);
	};
	stopRobot();


	playSound(soundBeepBeep);
	wait1Msec(100);

	moveForward(3, 20, 25);
	readSensor(&hi2);
	marker = hi2.red;

	val = marker;
	displayBigStringAt(50,50,val);

	wait1Msec(100);
	// stary laundry block scan
	moveTank(1, 20, -20, 5);
	moveForward(3, 20, 135);
	stopRobot();

	wait1Msec(100);
	initSensor(&hi2, S4);
	wait1Msec(100);
	readSensor(&hi2);

	if(hi2.red > 195){
		playSound(soundBeepBeep);
		sleep(100);
		col = 1;
		//yellow detected
	}
	else if(hi2.red > 100 && hi2.red < 194 ){
		playSound(soundBeepBeep);
		playSound(soundBeepBeep);
		sleep(100);
		col = 2;
		//red detected
	}
	else if(hi2.red > 3 && hi2.red < 80 ){
		playSound(soundBeepBeep);
		playSound(soundBeepBeep);
		playSound(soundBeepBeep);
		sleep(100);
		col = 3;
		//black detected
	}
	else {
		col = 0;
		// no laundry
	}

	val = marker;
	displayBigStringAt(50,50,val);

	if (marker > 50 ){
		  if ( col != 0) {
	       dropWater_L();
	    }
	    else { dropWater();}
	  }

	else {
		    if (col != 0){
		      playBall_L();
	         }
	      else{
		      playBall();

	       }
  }

  moveForward(3, -20, 240);
	moveForward(1, -20, 30);
	moveForward(3, 20, 40);

	displayBigStringAt(50,50,"done room task");
	moveTank(1, -20, 20, 300);
	moveForward(3, -30, 550);
	//done wall sqr
	moveForward(3, 25, 300);
	moveForward(3, 50, 1850);
	//at the middle
	if(col != 0){

		stopRobot();

		moveTank(1, 20, -20, 280);

		//Turn face bins
	moveForward(3, 30, 200);
		moveForward(1, 20, 20);
		moveForward(3, -20, 35);

		moveTank(1, 20, -20, 260);
		moveForward(1, 20, 30);
		stopRobot();
		moveForward(3, -20, 50);

		lineSquare(1500, 40, 0.2);
		moveForward(3, -20, 170);

		laundryBasket(col);

 		stopRobot();

 	moveForward(3, -30, 400);
	moveTank(1, -20, 20, 300)








	}

	else{

		//dont do laundry

	};
}
