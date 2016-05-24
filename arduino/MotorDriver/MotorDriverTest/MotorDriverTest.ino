/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
const int pinRgtMtrIn1 = 6;
const int pinRgtMtrIn2 = 7;
const int pinRgtMtrPwm = 5;
const int pinRgtMtrStby = 4;

const int pinLftMtrIn1 = 10;
const int pinLftMtrIn2 = 11;
const int pinLftMtrPwm = 9;
const int pinLftMtrStby = 8;

const int rightMotor = 0;
const int leftMotor = 1;


boolean debug = true;

void printMotorName(int motor) {
  if (motor == rightMotor) {
    Serial.print("Rgt");  
  } else {
    if (motor == leftMotor) {
      Serial.print("Lft");
    } else {
      Serial.print("Unk");
    }
  }
}

void motorControl(int motor, int in1, int in2, int pwm, int stdby) {
  if (motor == rightMotor) {
    digitalWrite(pinRgtMtrIn1, in1);     
    digitalWrite(pinRgtMtrIn2, in2);     
    analogWrite(pinRgtMtrPwm, pwm);     
    digitalWrite(pinRgtMtrStby, stdby);     
  } else {
    if (motor == leftMotor) {  
      digitalWrite(pinLftMtrIn1, in1);     
      digitalWrite(pinLftMtrIn2, in2);     
      analogWrite(pinLftMtrPwm, pwm);     
      digitalWrite(pinLftMtrStby, stdby);     
    }
  }
}

void motorShortBreakForward(int motor){
  motorControl(motor, HIGH, LOW, LOW, HIGH);
  if (debug) {
    Serial.print("Motor [");
    printMotorName(motor);
    Serial.println("]: ShortBreak Fwd");
  }
}

void motorShortBreakReverse(int motor){
  motorControl(motor, LOW, HIGH, LOW, HIGH);
  if (debug) {
    Serial.print("Motor [");
    printMotorName(motor);
    Serial.println("]: ShortBreak Rev");
  }
}

void motorForward(int motor, int pwm){
  motorControl(motor, HIGH, LOW, pwm, HIGH);
  if (debug) {
    Serial.print("Motor [");
    printMotorName(motor);
    Serial.print("]: Forward pwm=");
    Serial.print(pwm);
    Serial.println("");
  }
}

void motorReverse(int motor, int pwm){
  motorControl(motor, LOW, HIGH, pwm, HIGH);
  if (debug) {
    Serial.print("Motor [");
    printMotorName(motor);
    Serial.print("]: Reverse pwm=");
    Serial.print(pwm);
    Serial.println("");
  }
}

void motorStop(int motor){
  motorControl(motor, LOW, LOW, LOW, HIGH);
  if (debug) {
    Serial.print("Motor [");
    printMotorName(motor);
    Serial.println("]: Stop");
  }
}

void motorStandby(int motor){
  motorControl(motor, LOW, LOW, LOW, LOW);
  if (debug) {
    Serial.print("Motor [");
    printMotorName(motor);
    Serial.println("]: Standby");
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

  pinMode(pinLftMtrIn1, OUTPUT);     
  pinMode(pinLftMtrIn2, OUTPUT);     
  pinMode(pinLftMtrPwm, OUTPUT);     
  pinMode(pinLftMtrStby, OUTPUT);     

  motorStop(rightMotor);
  motorStop(leftMotor);
}

// the loop routine runs over and over again forever:
void loop() {
  // Speeding up forward
  motorForward(rightMotor, 80);
  motorForward(leftMotor, 80);
  delay(3000); 
  motorForward(rightMotor, 128);
  motorForward(leftMotor, 128);
  delay(3000); 
  motorForward(rightMotor, 255);
  motorForward(leftMotor, 255);
  delay(3000); 
  
  // Standby
  motorStandby(rightMotor);
  motorStandby(leftMotor);
  delay(3000);
 
  // Full speed forward 
  motorForward(rightMotor, 255);
  motorForward(leftMotor, 255);
  delay(3000); 
  
  // Stop
  motorStop(rightMotor);
  motorStop(leftMotor);
  delay(3000); 

  //Full speed reverse
  motorReverse(rightMotor, 255);
  motorReverse(leftMotor, 255);
  delay(3000); 
  
  // Short break reverse
  motorShortBreakReverse(rightMotor);
  motorShortBreakReverse(leftMotor);
  delay(3000); 
  
  // Slowing down reverse
  motorReverse(rightMotor, 255);
  motorReverse(leftMotor, 255);
  delay(3000); 
  motorReverse(rightMotor, 128);
  motorReverse(leftMotor, 128);
  delay(3000); 
  motorReverse(rightMotor, 80);
  motorReverse(leftMotor, 80);
  delay(3000); 
  
  // Stop
  motorStop(rightMotor);  
  motorStop(leftMotor);  
  delay(10000);
}
