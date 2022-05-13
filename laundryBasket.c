#include "helper.h"


int basketColor=0;
int bCol=0;
int counter = 1;

void colorAssign(){
	initSensor(&hi2, S4);
	readSensor(&hi2);
	basketColor = hi2.red;
	if (basketColor >100)
		bCol=1;
	else if (basketColor < 40)
		bCol=3;
  else
  	bCol =2;
}

void laundryBasket(int lCol){
  int match=0;
  string val;
  int counter = 1;



  colorAssign();

// for i in range 3 and then break instead?? kinda cringe im ngl
  while (match==0) {

  val = counter;
  displayBigStringAt(50,50,val);
  wait1Msec(300);
	//failsafe (10 pt even if wrong colour)
 	 if (lCol == bCol || counter == 3) {
 	  playSound(soundBeepBeep);
    sleep(100);
  	match=1;
  	if(counter == 1){
  		moveForward(3, 20, 20);
  	}

  	moveTank(1, -20, 20, 280);
		moveForward(3, 20, 10);
  	moveClaw(-50, 1200);

  	moveClaw(50, 1300);


  	moveForward(3, -20, 20);

    }
  else {
  		if(counter == 3){
  			moveForward(3, 20, 150);
  		}
  		else{
  			 moveForward(3, 20, 200);
  		}

		  colorAssign();
		  counter++;
		  if(counter == 2||counter == 3){
		  	moveForward(3, -5, 30);
		  	playSound(soundBeepBeep);
		  }


 		 }

  }

}
