void pickWater(){
	moveForward(1, 20, 20);

	moveForward(3, -20, 20);
	wait1Msec(100)
	lineSquare(1500, 50, 0.2);  // this is finicky, changing mp worked along with kp. quirky
	moveForward(3, -30, 120);

	//turn and pickup first
	moveTank(1, 20, -20, 120);
	moveForward(3, 30, 380);


	moveTank(1, -20, 20, 280);
	moveForward(1, -30, 20);
	moveForward(3, -20, 40);
	lineSquare(2000, 30, 0.2); // this is finicky, changing mp worked along with kp. quirky
	moveForward(3, -30, 50);
	moveTank(1, 20, -20, 275);

	moveForward(3, 30, 280);
	moveRack(-20, 500);
	//First picked up
	moveForward(3, -30, 280);
	moveTank(1, -20, 20, 280);
	moveForward(1, 30, 30);
	wait1Msec(100);
	moveForward(3, -20, 50);
	lineSquare(2000, 30, 0.2);
	moveForward(3, 30, 120);
	//Face secpnd water and pick up
	moveTank(1, 20, -20, 290);
	stopRobot()
	moveRack(20, 490);
	moveForward(3, 30, 280);
	stopRobot()
	moveRack(-20, 1000);
	wait1Msec(100);


}
