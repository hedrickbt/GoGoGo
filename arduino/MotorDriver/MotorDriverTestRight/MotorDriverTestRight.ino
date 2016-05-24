/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
const int pinRgtMtrIn1 = 6;
const int pinRgtMtrIn2 = 7;
const int pinRgtMtrPwm = 5;
const int pinRgtMtrStby = 4;

boolean debug = true;

void motorControl(int in1, int in2, int pwm, int stdby) {
  digitalWrite(pinRgtMtrIn1, in1);     
  digitalWrite(pinRgtMtrIn2, in2);     
  analogWrite(pinRgtMtrPwm, pwm);     
  digitalWrite(pinRgtMtrStby, stdby);     
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
  pinMode(pinRgtMtrIn1, OUTPUT);     
  pinMode(pinRgtMtrIn2, OUTPUT);     
  pinMode(pinRgtMtrPwm, OUTPUT);     
  pinMode(pinRgtMtrStby, OUTPUT);     

  motorStop();
}

// the loop routine runs over and over again forever:
void loop() {
  // Speeding up forward
  motorForward(80);
  delay(3000); 
  motorForward(128);
  delay(3000); 
  motorForward(255);
  delay(3000); 
  
  // Standby
  motorStandby();
  delay(3000);
 
  // Full speed forward 
  motorForward(255);
  delay(3000); 
  
  // Stop
  motorStop();
  delay(3000); 

  //Full speed reverse
  motorReverse(255);
  delay(3000); 
  
  // Short break reverse
  motorShortBreakReverse();
  delay(3000); 
  
  // Slowing down reverse
  motorReverse(255);
  delay(3000); 
  motorReverse(128);
  delay(3000); 
  motorReverse(80);
  delay(3000); 
  
  // Stop
  motorStop();  
  delay(10000);
}
