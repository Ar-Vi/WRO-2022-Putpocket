#include "helper.h"

int col2;
int marker2;
string val2;
void
 runBlueRed_2() {

	moveForward(3, 20, 45);
	moveTank(1, -20, 20, 280)
	stopRobot();

	moveRack(-20, 400);
	moveClaw(20,300);
	wait1Msec(100);
	moveForward(3, 20, 30);

	moveForward(1, -20, 30);
	moveForward(3, -20, 30);
	lineSquare(1500, 40, 0.2);

	moveForward(3, 20, 100);
	initSensor(&hi2, S4);
	while (hi2.red < 10){
		initSensor(&hi2, S4);
		setMotorSpeed(leftMotor, 10);
		setMotorSpeed(rightMotor, 10);
		readSensor(&hi2);
		val2 = hi2.red;
		displayBigStringAt(50,50,val2);
	};
	stopRobot();
	playSound(soundBeepBeep);
	wait1Msec(100);
	moveForward(3, 20, 25);
	readSensor(&hi2);
	marker2 = hi2.red;

	val2 = marker2;
	displayBigStringAt(50,50,val2);

	wait1Msec(100);
	// stary laundry block scan
	moveTank(1, 20, -20, 5);
	moveTank(1, 20, -20, 5);
	moveForward(3, 20, 135);

	stopRobot();
	wait1Msec(100);

	initSensor(&hi2, S4);

	wait1Msec(100);
	readSensor(&hi2);
	if(hi2.red > 165){
		playSound(soundBeepBeep);
		sleep(100);
		col2 = 1;
		//yellow detected
	}
	else if(hi2.red > 100 && hi2.red < 164 ){
		playSound(soundBeepBeep);
		playSound(soundBeepBeep);
		sleep(100);
		col2 = 2;
		//red detected
	}
	else if(hi2.red > 3 && hi2.red < 80 ){
		playSound(soundBeepBeep);
		playSound(soundBeepBeep);
		playSound(soundBeepBeep);
		sleep(100);
		col2 = 3;
		//black detected
	}
	else {
		col2 = 0;
		// no laundry
	}

	val2 = marker;
	displayBigStringAt(50,50,val2);

	if (marker2 > 50 ){
		  if ( col2 != 0) {
	       dropWater_L();
	    }
	    else { dropWater();}
	  }

	else {
		    if (col2 != 0){
		      playBall_L();
	         }
	      else{
		      playBall();
	       }
  }

  moveForward(3, -30, 220);
	moveForward(1, -30, 30);
	moveForward(3, -30, 70);

	displayBigStringAt(50,50,"done room task");
	moveTank(1, -20, 20, 270);
	moveForward(3, -40, 700);
	//done wall sqr
	moveForward(3, 25, 300);
	moveForward(3, 50, 1500);
	if(col2 != 0){

		stopRobot();

		moveTank(1, -20, 20, 320);

		//Turn face bins
moveForward(3, 30, 200);
		moveForward(1, 20, 20);
		moveForward(3, -20, 35);



		moveTank(1, 20, -20, 260);
		moveForward(1, 20, 30);
		stopRobot();
		moveForward(3, -20, 30);

		lineSquare(1500, 40, 0.2);
		moveForward(3, -20, 170);
 		laundryBasket(col2);

 		stopRobot();


	// if statements to go back to base based on col val

//	if(counter == 1){
//		moveForward(3, -40, 250);
//moveForward(5, -10, 40);
//moveForward(3, 30, 320);
//moveTank(3, 20, -20, 395)
//moveForward(3, 30, 300);
//moveClaw(100, 500);
//	};

//	if(counter == 2){
//moveForward(3, -40, 300);
//moveForward(1, -10, 25);
//moveForward(3, 20, 60);
//moveTank(3, -20, 0, 300);
//moveForward(3, -20, 180);
//moveClaw(100, 500);
//	};

//	if(counter == 3){
//moveForward(3, -40, 250);
//moveForward(5, -10, 30);
//moveTank(1, 0, -20, 250)
//moveForward(3, -20, 140);
//moveClaw(100, 500);

	};


	}

	//else {

	//	//dont do laundry


	//};
//}
