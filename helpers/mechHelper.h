
void stopClaw(){
	setMotorSpeed(clawArm, 0);
};
void stopRack(){
	setMotorSpeed(rackArm, 0);
};

void moveRack(int speed, int sec){
	clearTimer(T1);
	while (time1[T1] < sec){
		setMotorSpeed(rackArm, speed);
	};
	//stopRobot();
};

void moveClaw(int speed, int sec){
	clearTimer(T1);
	while (time1[T1] < sec){
		setMotorSpeed(clawArm, speed);
	};
	//stopRobot();
};
