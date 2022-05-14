#include "helpers\navHelper.h"
#include "helpers\mechHelper.h"


int basketColor=0;
int bCol=0;

void colorAssign(){
	if (basketColor >175)
		bCol=1;
	else if (basketColor < 90)
		bCol=3;
  else
  	bCol =2;
}

void laundryBasket(int lCol){
  int match=0;
  string val;

	initSensor(&hi2, S4);
	readSensor(&hi2);
	basketColor = hi2.red;

  colorAssign();

// for i in range 3 and then break instead?? kinda cringe im ngl
  while (match==0) {

  val = bCol;
  displayBigStringAt(50,50,val);
  wait1Msec(1000);

 	 if (lCol == bCol) {
 	  playSound(soundBeepBeep);
    sleep(500);
  	match=1;
  	moveForward(3, 10, 20);
  	moveTank(1, -20, 20, 280);

  	moveClaw(-50, 1500);
  	moveClaw(50, 2300);

    }
  else {
  	  moveForward(3, 10, 200);
		  readSensor(&hi2);
	    basketColor = hi2.red;
		  colorAssign();
 		 }

  }

}
