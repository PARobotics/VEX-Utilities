#pragma config(Sensorm dgtl1, limitSwitch, sensorTouch)
#pragma config(Motor, port1, M_1, tmotorVex393_HBridge, openLoop)
#pragma config(Motor, port2, M_2, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port3, M_3, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port4, M_4, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port5, M_5, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port6, M_6, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port7, M_7, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port8, M_8, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port9, M_9, tmotorVex393_MC29, openLoop)
#pragma config(Motor, port10, M_10, tmotorVex393_HBridge, openLoop)

#pragma platform(VEX)
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(1200)

#include "Vex_Competition_Includes.c"

/*
  MOTOR TEST
  Author: Jeffrey Shen
  Utility to easily test each vex port and its motors.
  ----------------------------------------------------
  Test all motors by plugging a limit switch into digital one and pressing it
  Test individual motors by connecting a joystick and pressing the following buttons:

  7L: Port 1
  7U: Port 2
  7R: Port 3
  7D: Port 4
  8L: Port 5
  8U: Port 6
  8R: Port 7
  8D: Port 8
  5U: Port 9
  5D: Port 10

*/

void all_motors(int vol){
	motor[port1] = vol;
	motor[port2] = vol;
	motor[port3] = vol;
	motor[port4] = vol;
	motor[port5] = vol;
	motor[port6] = vol;
	motor[port7] = vol;
	motor[port8] = vol;
	motor[port9] = vol;
	motor[port10] = vol;
}

void pre_auton(){
}

/*
 	AUTONOMOUS
	task
*/

task autonomous()
{

}

/*
	USER CONTROL
*/

task usercontrol(){
  while(true){
		if(SensorValue(limitSwitch) == 1){
			all_motors(127);
			wait1Msec(10);
		}
    else if(vexRT[Btn7L] == 1)
      motor[port1] = 127;
    else if(vexRT[Btn7U] == 1)
      motor[port2] = 127;
    else if(vexRT[Btn7R] == 1)
      motor[port3] = 127;
    else if(vexRT[Btn7D] == 1)
      motor[port4] = 127;
    else if(vexRT[Btn8L] == 1)
      motor[port5] = 127;
    else if(vexRT[Btn8U] == 1)
      motor[port6] = 127;
    else if(vexRT[Btn8R] == 1)
      motor[port7] = 127;
    else if(vexRT[Btn8D] == 1)
      motor[port8] = 127;
    else if(vexRT[Btn5U] == 1)
      motor[port9] = 127;
    else if(vexRT[Btn5D] == 1)
      motor[port10] = 127;
		else
			all_motors(0);
	}
}
