/*
  PUSH RELEASE BUTTON
  Author: Jeffrey Shen
  Utility to allow easy debugging with buttons, limit switches, and joysticks.
  ----------------------------------------------------------------------------
  Normally if a button is pressed, it will give a stream of pushes, so if you want to execute just one function, you can't. This code allows you to execute ONE function for ONE click.
  ----------------------------------------------------------------------------
  USAGE:
  NUM_BUTTONS = 2; //How many buttons to monitor
  #include PATH/TO/PR_BUTTON.c

  void pre_auton(){
    buttonsInit();
    //Add buttons with add_button
  }

  task usercontrol(){
    buttonsInit();
    while(true){
      //To access a button:
      if(get_button(0) == PUSHED){
        //Do stuff
      }
    }
  }

*/

task PR_Monitor();
int NUM_BUTTONS = 0;

#define JOYSTICK    1
#define PARTNER     2
#define TOUCHSENSOR 3
#define NOT_PUSHED  0
#define PUSHED      1

struct button{
  int type; //Remote or touch sensors
  int port;
  int pushed; //Temporary variable (shouldn't be accessed)
  int status; //Pushed?
};

static button Buttons[NUM_BUTTONS];

/*
  PUBLIC INTERFACE
  Functions used by end user
*/

void add_button(int i, int type, int port){
  /*
    USAGE:
    add_button(0, JOYSTICK, Btn7L) //Main joystick
    add_button(0, PARTNER, Btn7LXmtr2) //Partner Joystick
    add_button(0, TOUCHSENSOR, dgtl1) //Limit Switch
  */
  Buttons[i].type = type;
  Buttons[i].port = port;
}


void buttonsInit(){
  startTask(PR_Monitor, 9);
}

int get_button(int i){
  return Buttons[i].status;
}

void reset_button(int i){
  Buttons[i].status = NOT_PUSHED;
}


task PR_Monitor(){
  int sensorValue = 0;

  while (true) {
    for(int i = 0; i < NUM_PR_BUTTONS; i++){
      if (Buttons[i].type == JOYSTICK || Buttons[i].type == PARTNER)
        sensorValue = vexRT[Buttons[i].port];
      else if (Buttons[i].type == TOUCHSENSOR)
        sensorValue = SensorValue(Buttons[i].port);

      //On push
      if (sensorValue == 1) Buttons[i].pushed = 1;
      //Pushed and released
      if (sensorValue == 0 && Buttons[i].pushed == 1) {
         Buttons[i].pushed = 0;
         Buttons[i].status = PUSHED;
      }

      //Monitor every 10 msec
      wait1Msec(10);
    }
  }
}
