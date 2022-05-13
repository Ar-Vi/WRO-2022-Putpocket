#include "helper.h"

int col;
int marker;
string val;
void
 runBlueRed_1() {





	moveForward(3, 20, 40);
	moveTank(1, -20, 20, 290)
	stopRobot();

	moveRack(-20, 1000);
	wait1Msec(200);
	moveForward(3, 20, 30);

	moveForward(1, -20, 30);
	moveForward(3, -20, 50);
	lineSquare(3000, 40, 0.2);

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
	wait1Msec(500);
	moveForward(3, 20, 25);
	readSensor(&hi2);
	marker = hi2.red;

	val = marker;
	displayBigStringAt(50,50,val);

	wait1Msec(500);
	// stary laundry block scan

	moveForward(3, 20, 135);

	stopRobot();
	wait1Msec(1000);

	initSensor(&hi2, S4);

	wait1Msec(500);
	readSensor(&hi2);
	if(hi2.red > 230){
		playSound(soundBeepBeep);
		sleep(200);
		col = 1;
		//yellow detected
	}
	else if(hi2.red > 100 && hi2.red < 220 ){
		playSound(soundBeepBeep);
		playSound(soundBeepBeep);
		sleep(200);
		col = 2;
		//red detected
	}
	else if(hi2.red > 10 && hi2.red < 80 ){
		playSound(soundBeepBeep);
		playSound(soundBeepBeep);
		playSound(soundBeepBeep);
		sleep(200);
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

	displayBigStringAt(50,50,"done room task");
	moveTank(1, -20, 20, 270);
	moveForward(3, -30, 1000);
	if(col != 0){
		plf_dist(0, 1500, 20, 45, 0.2);
		stopRobot();
		moveForward(3, 30, 700);
		moveTank(1, 20, -20, 280);
		//Turn face bins
		moveForward(3, 30, 200);
		moveForward(1, 30, 20);
		moveForward(3, -20, 60);
		moveTank(1, 20, -20, 220);
		moveForward(1, 20, 20);
		stopRobot();
		moveForward(3, -20, 20);

		lineSquare(3000, 40, 0.2);
		moveForward(3, -20, 200);
		laundryBasket(col);

 		stopRobot();



	}

	else{
		//dont do laundry
	};
}
