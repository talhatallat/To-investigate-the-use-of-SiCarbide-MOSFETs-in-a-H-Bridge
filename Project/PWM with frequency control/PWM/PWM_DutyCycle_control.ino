int pot = A0;
int pinOut = 9;

void setup() {
  // put your setup code here, to run once:
  TCCR1B = TCCR1B & B11111000 | B00000001; // set timer 1 divisor to 1 for PWM frequency of 31372.55 Hz
  Serial.begin(9600);
  pinMode(pinOut,OUTPUT);
  pinMode(A0,INPUT);//pot
}
// understanf how exactly arduino is working hardware register level. 
//forcing the bits the way 
void loop() {

 int readPotValues = analogRead(pot);//reading

int x = (255./1023.) * readPotValues;// conversion from analog 10-bit to 8-bit scale

 analogWrite (pinOut, x);
 Serial.print("Analog Value to the Output");
 Serial.print (x);
 delay (500);
}
