#pragma config(Motor,  port1,           leftMotor,     tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           armMotor,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           gearMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           clawMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// above parameters are defining motors for program use


/*
 * Single Joystick Control
 * This program is used to control the robot for Robocross using a single joystick.
 *
 * @author Aniruddha Murali
 * @school Bedford Middle School
 * @date January 20, 2015
 *
 * @copyright Aniruddha Murali
*/


// main program
task main()
{
	//initializing all motors to 0
	motor[armMotor] = 0;
	motor[clawMotor] = 0;
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;


	// infinite loop to take input from joystick and transmit output through Cortex
	while(true)
	{
		// receiving input from joystick for left and right wheel motors
		motor[leftMotor] = vexRT[Ch3];
		motor[rightMotor] = vexRT[Ch2];

		//armMotor up control
		if(vexRT[Btn7U] == 1)
		{
			motor[armMotor] = 40;
		}
		else
		{
			motor[armMotor] = 8; // helps to stabilize the arm motor
		}

		//armMotor down control
		if(vexRT[Btn7D] == 1)
		{
			motor[armMotor] = -40;
		}
		else
		{
		//	motor[armMotor] = 0;
		}



		//clawMotor up/outward
		if(vexRT[Btn8U] == 1)
		{
			motor[clawMotor] = -60;
		}
		else
		{
			motor[clawMotor] = 0;
		}

		//clawMotor down/inward control
		if(vexRT[Btn8D] == 1)
		{
			motor[clawMotor] = 60;
		}
		else
		{
		//	motor[clawMotor] = 0;
		}



		//gearMotor up control
		if(vexRT[Btn6U] == 1)
		{
			motor[gearMotor] = 50;
		}
		else
		{
			motor[gearMotor] = 0;
		}

		//gearMotor down control
		if(vexRT[Btn6D] == 1)
		{
			motor[gearMotor] = -50;
		}
		else
		{
			//motor[gearMotor] = 0;
		}

	} // end of while loop

} // end of main program
