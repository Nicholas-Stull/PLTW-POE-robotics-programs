#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  red1,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl2,  red2,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl3,  green1,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl4,  green2,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl5,  button1,        sensorTouch)
#pragma config(Sensor, dgtl6,  button2,        sensorTouch)
#pragma config(Sensor, dgtl11, red3,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, red4,           sensorLEDtoVCC)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           baseRotation,  tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           baseLift,      tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port3,           elbowLift,     tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port4,           handLift,      tmotorVex393_MC29, openLoop, encoderPort, I2C_3)
#pragma config(Motor,  port5,           handRotation,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           handClaw,      tmotorVex393_MC29, openLoop)
#pragma config(DatalogSeries, 0, "I2C Encoder 1 - Base Rotation", Sensors, Sensor, I2C_1, 10)
#pragma config(DatalogSeries, 1, "I2C Encoder 2 - Base Lift", Sensors, Sensor, I2C_2, 10)
#pragma config(DatalogSeries, 2, "I2C Encoder 3 - Elbow Lift", Sensors, Sensor, I2C_3, 10)
#pragma config(DatalogSeries, 3, "I2C Encoder 4 - Hand Lift", Sensors, Sensor, I2C_4, 10)
#pragma config(DatalogSeries, 4, "I2C Encoder 5 - Hand Rotation", Sensors, Sensor, I2C_5, 10)
#pragma config(DatalogSeries, 5, "I2C Encoder 6 - Claw", Sensors, Sensor, I2C_6, 10)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


//DECLARING "STATIC" VARIABLES FOR MATH STUFF
struct MotorControlStructure 		// (StructureName)
{
	int motorPort;								// (StructureName).motorPort
	int encoderPort;							// (StructureName).encoderPort
	int gearRatio;								// (StructureName).gearRatio
	int encoderCalibrationValue;	// (StructureName).encoderCalibrationValue
};

struct ArmLengthMathSubStructure // (struct RobotArmControlStructure name).(struct ArmLengthMathSubStructure).XXX
{
	 float length;
	 float height;
	 float MA;
	 float angleA;
	 float lengthA;
	 float angleB;
	 float lengthB;
	 float angleC;
	 float lengthC;

};

struct RobotArmControlStructure
{
	struct MotorControlStructure shoulder;
	struct MotorControlStructure elbow;
	struct MotorControlStructure wrist;
	struct ArmLengthMathSubStructure lengthMath;

};



task main()
{
	// Setting up a debug stream for current values of all the I2C integrated encoders on the bot.
	//  Should look something like this:

	/*
			baseRotation, baseLift, elbowLift, handLift, handRotation, handClaw (not necessarily encoded), joy1_x1, joy1_y1, joy1_x2, joy1_y2, joy1_Buttons, joy1_TopHat
			 141, 313, -11, -444, 333, 000


	*/

	// writeDebugStreamLine("baseRotation, baseLift, elbowLift, handLift, handRotation, handClaw (not necessarily encoded), joy1_x1, joy1_y1, joy1_x2, joy1_y2, joy1_Buttons, joy1_TopHat");









	while (0!=1) {
		/*  I'm at home with a partially built bot, so I changed it up a bit to work on arm code.
			I unplugged the base rotation IEM to get a second cord to extend the reach of the wire so that the bodged-on first joint I made with pieces from the base could have IEM readings.
			I2C 1 : base lift
			I2C 2 : elbow lift
			aand I'm out of 4-pin wires.
			Motor 1 (port 2) is base rotation
			motor 2 (port 3) is base lift
			motor 3 (port 4) is elbow lift


		*/
		if (vexRT[Btn5U] == 1) {
				startMotor(baseLift,30);
		} else if (vexRT[Btn5D] == 1) {
				startMotor(baseLift,-30);
		} else {
			stopMotor(baseLift);
		}
				if (vexRT[Btn6U] == 1) {
				startMotor(elbowLift,30);
		} else if (vexRT[Btn6D] == 1) {
				startMotor(elbowLift,-30);
		} else {
			stopMotor(elbowLift);
		}
}


}
