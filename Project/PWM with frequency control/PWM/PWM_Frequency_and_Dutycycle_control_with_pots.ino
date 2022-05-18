/* Project title: To investigate the use of SIlicon Carbide (SIC) MOSFET in an H-bridge
 * Program Name: PWM_Frequency_and_Dutycycle_control_using_pots.
 * Programmer Name: Talha Tallat (D18124645)
 * Last Updated: 18/05/2022
 * Program Description: Producing Pulse width modulation (PWM) using Arduino UNO and varying the frequency & duty cycle by potentiometers.
 */
 

#include <PWM.h> //pulse with modulation (PWM) libaray

//PWM Controlled by pot
int x=0;
int y=0;

int pinOut = 9; // selecting a pin number 9 and assigning type integer

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200); // selecting a bot rate to be able to run a serial monitor 

  pinMode(pinOut,OUTPUT); // pin 9 output to turn on the base of the BJT
  pinMode(A0,INPUT); // dutycycle control pot input
  pinMode(A1,INPUT); // frequency control pot input

  InitTimersSafe(); //initialize all timers except for 0, to save time keeping functions

  

  
  
  // set.. functions sets the frequency for the pin 9
}

void loop() {

  //int potValue = analogRead(A1);
  //Serial.println(A1);
  int32_t frequency = map(analogRead(A1), 0, 1023, 0, 125000);/*
    Mapping this input(0-1023) values to 125 KHz range for the PWM frequency, using map() function.
  */
  SetPinFrequencySafe(pinOut, frequency);

  x=(analogRead(A0)); //pot will change the width of the pulse
  y=(map(x,0,1023,0,255));/* Map an analog value to 8 bits (0 to 255) */
 Serial.println(A0);
  analogWrite(pinOut,y);
  //Serial.println(A0);
}




