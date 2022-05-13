#pragma config(Sensor, S1,     LeftCol,        sensorEV3_Color)
#pragma config(Sensor, S3,     RightCol,       sensorEV3_Color)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Medium, PIDControl, reversed, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Medium, PIDControl, driveRight, encoder)
#pragma config(Motor,  motorD,          armMotor,      tmotorEV3_Medium, PIDControl, encoder)

void lineFollow(int speed, int mid, float kp)
{

	while (getColorReflected(RightCol) > 12 ){
		setMotorSpeed(leftMotor, speed+(getColorReflected(LeftCol)- mid)*kp);
		setMotorSpeed(rightMotor, speed-(getColorReflected(LeftCol)- mid)*kp);
	};
};

task main()
{

lineFollow(20, 25,0.2);

}
