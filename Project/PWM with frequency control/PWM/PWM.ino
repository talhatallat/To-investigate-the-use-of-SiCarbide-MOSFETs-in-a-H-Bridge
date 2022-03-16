
#include <PWM.h> //pulse with modulation (PWM) libaray

//PWM Controlled by pot
int x=0;
int y=0;

int pinOut = 9; // selecting a pin number 9 and assigning type integer
int32_t frequency = 1000; // picking a frequency 

void setup() {
  // put your setup code here, to run once:

  pinMode(pinOut,OUTPUT);
  pinMode(A0,INPUT);

  InitTimersSafe(); //initialize all timers except for 0, to save time keeping functions

  bool success = SetPinFrequencySafe(pinOut, frequency);
  // type bool provides true or false and assigned to a varible called 'success' 
  // set.. functions sets the frequency for the pin 9
}

void loop() {
  // put your main code here, to run repeatedly:
  pwmWrite(pinOut, 127);

  x=(analogRead(A0)); //pot will change the width of the pulse
  y=(map(x,0,1023,0,255));/* Map an analog value to 8 bits (0 to 255) */
 
  analogWrite(pinOut,y);
}





