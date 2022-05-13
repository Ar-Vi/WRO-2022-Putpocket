
void stopRobot(){
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	setMotorSpeed(clawArm, 0);
	setMotorSpeed(rackArm, 0);


};

void lineSquare(int sec, int mid, float sens){
	clearTimer(T1);
	while (time1[T1] < sec){
		setMotorSpeed(leftMotor, (getColorReflected(LeftCol)-mid)*sens);
		setMotorSpeed(rightMotor, (getColorReflected(RightCol)-mid)*sens);
	};
	stopRobot();
};
void plf_col(int sensefollow, int stopsense, int speed, int mid, float kp, int stopat, int types)
{
	//light to dark
	if(types == 1){
		while (getColorReflected(stopsense) > stopat ){
			setMotorSpeed(leftMotor, speed+(getColorReflected(sensefollow)- mid)*kp);
			setMotorSpeed(rightMotor, speed-(getColorReflected(sensefollow)- mid)*kp);
		};
	}
	//dark to light
	if(types == 2){
		while (getColorReflected(stopsense) < stopat ){
			setMotorSpeed(leftMotor, speed+(getColorReflected(sensefollow)- mid)*kp);
			setMotorSpeed(rightMotor, speed-(getColorReflected(sensefollow)- mid)*kp);
		};
	}
	stopRobot();
};

void plf_dist(int s, int dist, int speed, int mid, float kp) // add string para?
{
	resetMotorEncoder(rightMotor);
	while (getMotorEncoder(rightMotor) < dist ){
		setMotorSpeed(leftMotor, speed+(getColorReflected(0)- mid)*kp);
		setMotorSpeed(rightMotor, speed-(getColorReflected(0)- mid)*kp);
	};
	stopRobot();
};
void plf_ultra(int sens, int dist, int speed, int mid, float kp)
{
	while (getUSDistance(Ultra) > dist){
		setMotorSpeed(leftMotor, speed+(getColorReflected(sens)- mid)*kp);
		setMotorSpeed(rightMotor, speed-(getColorReflected(sens)- mid)*kp);
	};
	stopRobot();
};

void plf_double(int dist, int speed, float kp)
	{
		int error;

		resetMotorEncoder(rightMotor);
		resetMotorEncoder(leftMotor);
		while ((getMotorEncoder(rightMotor)+getMotorEncoder(rightMotor))/2 < dist ){
			error = getColorReflected(0) - getColorReflected(2);
			setMotorSpeed(leftMotor, (speed+error)*kp);
			setMotorSpeed(rightMotor, (speed-error)*kp);
		};
		stopRobot();
	};

void pid_lf_double(int dist, int speed, float kp)
	{
		int error;

		resetMotorEncoder(rightMotor);
		resetMotorEncoder(leftMotor);
		while ((getMotorEncoder(rightMotor)+getMotorEncoder(rightMotor))/2 < dist ){
			error = getColorReflected(0) - getColorReflected(2);
			setMotorSpeed(leftMotor, (speed+error)*kp);
			setMotorSpeed(rightMotor, (speed-error)*kp);
		};
		stopRobot();
	};

	void moveRack(int speed, int sec){
		clearTimer(T1);
		while (time1[T1] < sec){
			setMotorSpeed(rackArm, speed);
		};
		stopRobot();
	};

	void moveClaw(int speed, int sec){
		clearTimer(T1);
		while (time1[T1] < sec){
			setMotorSpeed(clawArm, speed);
		};
		stopRobot();
	};

	void moveTank(int types, int pwrL, int pwrR, int upto){
		if(types == 1){
			resetMotorEncoder(rightMotor);
			while (abs(getMotorEncoder(rightMotor)) < abs(upto)){
				setMotorSpeed(leftMotor, pwrL);
				setMotorSpeed(rightMotor, pwrR);
			};
		};
		if(types == 3){
			resetMotorEncoder(leftMotor);
			while (abs(getMotorEncoder(leftMotor)) < abs(upto)){
				setMotorSpeed(leftMotor, pwrL);
				setMotorSpeed(rightMotor, pwrR);
			};
		};

		if(types == 2){
			while (getUSDistance(Ultra) > upto ){
				setMotorSpeed(leftMotor, pwrL);
				setMotorSpeed(rightMotor, pwrR);
			};
		};
		stopRobot();
	};

	void moveTank_col(int types, int pwrL, int pwrR, int upto){
		if(types == 1){
			while (getColorReflected(RightCol) > upto ){
				setMotorSpeed(leftMotor, pwrL);
				setMotorSpeed(rightMotor, pwrR);
			};
		};
		if(types == 2){
			while (getColorReflecteD(LeftCol) > upto ){
				setMotorSpeed(leftMotor, pwrL);
				setMotorSpeed(rightMotor, pwrR);
			};
		};
		stopRobot();
	};


	void moveForward(int types, int speed, float amnt){
		//Light to dark
		if(types == 1){
			while (getColorReflected(LeftCol) >= amnt){
				setMotorSpeed(leftMotor, speed);
				setMotorSpeed(rightMotor, speed);
			};
			stopRobot();
		};
		if(types == 5){
			while (getColorReflected(RightCol) <= amnt){
				setMotorSpeed(leftMotor, speed);
				setMotorSpeed(rightMotor, speed);
			};
			stopRobot();
		};
		//dark to light
		if(types == 4){
			while (getColorReflected(LeftCol) < amnt ){
				setMotorSpeed(leftMotor, speed);
				setMotorSpeed(rightMotor, speed);
			};
		};

		if(types == 2){
			clearTimer(T1);
			while (time1[T1] < amnt){
				setMotorSpeed(leftMotor, speed);
				setMotorSpeed(rightMotor, speed);
			};
		};
		if(types == 3){
			resetMotorEncoder(rightMotor);
			while (abs(getMotorEncoder(rightMotor)) < (amnt)){
				setMotorSpeed(rightMotor, speed);
				setMotorSpeed(leftMotor, speed);
			};
			stopRobot();
		};
		if(types == 5){

			while (abs(getUSDistance(Ultra)) > abs(amnt)){
				setMotorSpeed(rightMotor, speed);
				setMotorSpeed(leftMotor, speed);
			};
			stopRobot();
		};

	};
