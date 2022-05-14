#include "helpers\navHelper.h"
#include "helpers\mechHelper.h"

int col2;
int marker2;
string val2;
void
 twoRoom() {
	initSensor(&hi2, S4);
	while (hi2.red < 10){
		initSensor(&hi2, S4);
		setMotorSpeed(leftMotor, 10);
		setMotorSpeed(rightMotor, 10);
		readSensor(&hi2);
		val2 = hi2.red;
		displayBigStringAt(50,50,val2);
	};
	//stopRobot();
	playSound(soundBeepBeep);
	wait1Msec(500);
	moveForward(3, 20, 25);
	readSensor(&hi2);
	marker2 = hi2.red;

	val2 = marker2;
	displayBigStringAt(50,50,val2);

	wait1Msec(500);
	// stary laundry block scan

	moveForward(3, 20, 135);


	wait1Msec(1000);

	initSensor(&hi2, S4);

	wait1Msec(500);
	readSensor(&hi2);
	if(hi2.red > 213){
		playSound(soundBeepBeep);
		sleep(200);
		col2 = 1;
		//yellow detected
	}
	else if(hi2.red > 100 && hi2.red < 210 ){
		playSound(soundBeepBeep);
		playSound(soundBeepBeep);
		sleep(200);
		col2 = 2;
		//red detected
	}
	else if(hi2.red > 3 && hi2.red < 80 ){
		playSound(soundBeepBeep);
		playSound(soundBeepBeep);
		playSound(soundBeepBeep);
		sleep(200);
		col2 = 3;
		//black detected
	}
	else {
		col2 = 0;
		// no laundry
	}

	val2 = marker2;
	displayBigStringAt(50,50,val2);

	if (marker2 > 50 ){
		  if ( col2 != 0) {
	       dropWater_L();
	    }
	    else { dropWater();}
	  }

	else {
		    if (col2 != 0){
		      //playBall_L();
	         }
	      else{
		      //playBall();
	       }
  }

	displayBigStringAt(50,50,"done room task");
	moveTank(1, -20, 20, 270);
	moveForward(3, -30, 700);
	//done wall sqr
	moveForward(3, 25, 300);
	moveForward(3, 50, 1500);
	if(col2 != 0){



		moveTank(1, -20, 20, 320);

		//Turn face bins
		moveForward(3, 30, 200);
		moveForward(1, 20, 20);

		wait1Msec(100);
		moveForward(3, -20, 70);

		moveTank(1, 20, -20, 260);
		moveForward(1, 20, 20);

		moveForward(3, -20, 50);

		lineSquare(1500, 40, 0.2);
		moveForward(3, -20, 200);
		laundryBasket(col2);



 	moveForward(3, -30, 535);
	moveTank(1, -20, 20, 280)








	}

	else{

		//dont do laundry

	};
}
