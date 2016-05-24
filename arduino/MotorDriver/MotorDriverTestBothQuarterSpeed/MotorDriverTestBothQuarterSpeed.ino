/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
const int pinLftMtrIn1 = 10;
const int pinLftMtrIn2 = 11;
const int pinLftMtrPwm = 9;
const int pinLftMtrStby = 8;

boolean debug = true;

void motorControl(int in1, int in2, int pwm, int stdby) {
  digitalWrite(pinLftMtrIn1, in1);     
  digitalWrite(pinLftMtrIn2, in2);     
  analogWrite(pinLftMtrPwm, pwm);     
  digitalWrite(pinLftMtrStby, stdby);     
}

void motorShortBreakForward(){
  motorControl(HIGH, LOW, LOW, HIGH);
  if (debug) {
    Serial.println("Motor: ShortBreak Fwd");
  }
}

void motorShortBreakReverse(){
  motorControl(LOW, HIGH, LOW, HIGH);
  if (debug) {
    Serial.println("Motor: ShortBreak Rev");
  }
}

void motorForward(int pwm){
  motorControl(HIGH, LOW, pwm, HIGH);
  if (debug) {
    Serial.print("Motor: Forward pwm=");
    Serial.print(pwm);
    Serial.println("");
  }
}

void motorReverse(int pwm){
  motorControl(LOW, HIGH, pwm, HIGH);
  if (debug) {
    Serial.print("Motor: Reverse pwm=");
    Serial.print(pwm);
    Serial.println("");
  }
}

void motorStop(){
  motorControl(LOW, LOW, LOW, HIGH);
  if (debug) {
    Serial.println("Motor: Stop");
  }
}

void motorStandby(){
  motorControl(LOW, LOW, LOW, LOW);
  if (debug) {
    Serial.println("Motor: Standby");
  }
}


// the setup routine runs once when you press reset:
void setup() {         
  Serial.begin(9600);  

  // initialize the digital pin as an output.
  pinMode(pinLftMtrIn1, OUTPUT);     
  pinMode(pinLftMtrIn2, OUTPUT);     
  pinMode(pinLftMtrPwm, OUTPUT);     
  pinMode(pinLftMtrStby, OUTPUT);     

  motorStop();
}

// the loop routine runs over and over again forever:
void loop() {
  // Speeding up forward
  motorForward(255);
}
