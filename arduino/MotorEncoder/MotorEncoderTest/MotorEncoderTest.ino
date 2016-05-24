//======================================================== Your Code ====================================================================
  
// The tutorial for this code can be found here: http://letsmakerobots.com/node/38636

// Adjust the maxvolt and maxspeed values in the "Constants.h" tab to suit your battery and gearbox as instructed in the tutorial
// Adjust the IO pin definitions in the "IOpins.h" tab to suit your controller and wiring scheme
 
// Use the variable lspeed to control the left  motor speed. -100 to +100.  Negative values indicate reverse direction
// Use the variable rspeed to control the right motor speed. -100 to +100.  Negative values indicate reverse direction

// use the variables lcount and rcount to measure distance travelled. These counters increment every time the encoders output changes state
// for best accuracy, make sure the robot comes to a complete stop before resetting the counters

// The Motor Encoder code comes from the above site


/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */

// Motor Driver 
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


// Motor Encoder
#define maxvolt  1023                                     // 100% battery voltage

#define maxspeed 23                                       // encoder pulses per second for speed=100% with battery at 100%
                                                          // Because my encoder disc is on the motor shaft, my encoder resolution (slots) needs to be 
                                                          // multiplied by the gear ratio of the gearbox. The gearbox has a ratio of 48:1 so my final 
                                                          // resolution is 8 x 48 = 384
                                                          // My measured RPM is 194
                                                          // wheel diameter = 64mm
                                                          // Wheel circumference = 3.1415 * 64 = 201.06mm
                                                          // Smallest measurement = circumference / resulution = 201.06/ 384 = 0.52mm per pulse ( state change)
                                                          // RPS = 194 / 60 = 3.23 RPS
                                                          // State changes/sec = 3.23 * 8 = 25.85
                                                          // estimaged loaded state change / sec = 0.89 * 25.85 = 23
                                                          
#define lmencpin    3                                     //  D2 is the pin for external interrupt 0
#define rmencpin    2                                     //  D3 is the pin for external interrupt 1
#define powerpin    7                                     //  A7  monitors battery voltage

volatile unsigned int lpulse=100000;                      // width of left and right encoder pulses in uS
volatile unsigned int rpulse=100000;                      // width of left and right encoder pulses in uS
volatile unsigned int lcount,rcount;                      // left and right pulse counters to measure distance
volatile byte lflag;                                      // flag indicates when left  encoder changes states
volatile byte rflag;                                      // flag indicates when right encoder changes states

byte lpwm,rpwm;                                           // left and right motor speeds generated from the processor
int lspeed,rspeed;                                        // left and right motor speeds requested by the user
unsigned long bestspeed=maxspeed;                         // encoder pulses per second for speed=100% (less than actual to allow for load)
unsigned int batvolt;                                     // battery voltage to 2 decimal places e.g. 751 = 7.51V
unsigned long mtime;                                      // "no go" timer used to re-start motors when both motors stopped
unsigned long btime;                                      // timer used to check battery voltage

volatile unsigned long ltime;                             // remembers time of left  encoders last state change in uS
volatile unsigned long rtime;                             // remembers time of right encoders last state change in uS



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

  // Motor Driver
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
  
  // Motor Encoder
  //pinMode(lmdirpin,OUTPUT);
  //pinMode(rmdirpin,OUTPUT);
  
//  digitalWrite(rmencpin,1);                               // enable pullup resistor for right encoder sensor
//  digitalWrite(lmencpin,1);                               // enable pullup resistor for left  encoder sensor
  attachInterrupt(0,Rencoder,CHANGE);                     // trigger right encoder ISR on state change
  attachInterrupt(1,Lencoder,CHANGE);                     // trigger left  encoder ISR on state change
  lspeed=0;rspeed=0;
  
}

// the loop routine runs over and over again forever:
void loop() {
  //======================================================== Motor Speed Control =========================================================
  
  unsigned int temp;                                      // temporary variable for calculationa
  if(micros()-mtime>999)                                  // Call motor control function every mS
  {
    mtime=micros();                                       // reset motor timer
    MotorControl();                                       // update motor speeds    
    
    //batvolt=analogRead(powerpin);                           // read battery voltage  
    batvolt=maxvolt;                                          // read battery voltage  - don't want to read power pin
    //temp=50*batvolt/maxvolt*batvolt/maxvolt*(maxspeed/50);  // calculate best possible speed with available battery voltage as an integer
    temp=(batvolt*1.0/maxvolt)*maxspeed;                      // calculate best possible speed with available battery voltage as an integer
    bestspeed=long(temp);                                     // convert to long                                
  }
  
  //lspeed = 10;
  //rspeed = 10;
  
  if (debug) {
    Serial.print("Rcount/Pulse: ");
    Serial.print(rcount);
    Serial.print("/");
    Serial.println(rpulse);
    Serial.print("Lcount/Pulse: ");
    Serial.print(lcount);
    Serial.print("/");
    Serial.println(lpulse);
  }
  
  if (rcount >= 50 ) {
    lspeed = 10;
    rspeed = 10;
    //motorForward(leftMotor, 255);
    //motorForward(rightMotor, 255);
  } else {
    lspeed = 10;
    rspeed = 10;
    //motorForward(leftMotor, 80);
    //motorForward(rightMotor, 80);
  }
}


//======================================================= ISR for left encoder =======================================================
void Lencoder()
{
  lpulse=micros()-ltime;                               // time between last state change and this state change
  ltime=micros();                                      // update ltime with time of most recent state change
  lcount++;                                            // increment left motor distance counter
}


//======================================================= ISR for right encoder ======================================================
void Rencoder()
{
  rpulse=micros()-rtime;                               // time between last state change and this state change
  rtime=micros();                                      // update ltime with time of most recent state change
  rcount++;                                            // increment right motor distance counter
}

//======================================================= Control speed and direction of left and right motors ==========================================
void MotorControl()
{
  unsigned long ractual;                                // stores temporary calculation of actual left and right motor speeds in uS between encoder pulses
  unsigned long lactual;                                // stores temporary calculation of actual left and right motor speeds in uS between encoder pulses
  if(lspeed<-100) lspeed=-100;                         // limit left and right motor speeds to allowed values
  if(rspeed<-100) rspeed=-100;
  if(lspeed>100) lspeed=100;
  if(rspeed>100) rspeed=100;
  
  if(micros()-ltime>20000 && lspeed!=0) lpwm+=2;       // jumpstart stalled motor
  if(micros()-rtime>20000 && rspeed!=0) rpwm+=2;       // jumpstart stalled motor
   
      
  //digitalWrite(rmdirpin,rspeed>0);                     // set direction of right motor
  ractual=1000000/(abs(rspeed)*bestspeed/100);          // calculate desired time in uS between encoder pulses  
  if(ractual>rpulse && rpwm>0) rpwm--;                  // if motor is running too fast then decrease PWM
  if(ractual<rpulse && rpwm<254) rpwm++;                // if motor is running too slow then increase PWM
//  analogWrite(rmpwmpin,rpwm);                          // update speed for right motor
  if (rspeed < 0) {
    motorReverse(rightMotor, rpwm);
  } else {
    motorForward(rightMotor, rpwm);
  }

  //digitalWrite(lmdirpin,lspeed>0);                     // set direction of left  motor
  lactual=1000000/(abs(lspeed)*bestspeed/100);          // calculate desired time in uS between encoder pulses
  if(lactual>lpulse && lpwm>0) lpwm--;                  // if motor is running too fast then decrease PWM
  if(lactual<lpulse && lpwm<254) lpwm++;                // if motor is running too slow then increase PWM
  //analogWrite(lmpwmpin,lpwm);                          // update speed for left  motor
  if (lspeed < 0) {
    motorReverse(leftMotor, lpwm);
  } else {
    motorForward(leftMotor, lpwm);
  }

  if (debug) {
    Serial.print("Right pwm/rpulse/actual:"),
    Serial.print(rpwm);
    Serial.print("/");
    Serial.println(rpulse);
    Serial.print("/");
    Serial.println(ractual);

    Serial.print("Left pwm/lpulse/actual:");
    Serial.print(lpwm);
    Serial.print("/");
    Serial.print(lpulse);
    Serial.print("/");
    Serial.println(lactual);
  }
}

/*
Power    SC/sec     μS/SC
100%  =   1900  =   526μS
 90%  =   1710  =   585μS
 80%  =   1520  =   658μS
 70%  =   1330  =   751μS
 60%  =   1140  =   877μS
 50%  =    950  =  1053μS
 40%  =    760  =  1316μS
 30%  =    570  =  1754μS
 20%  =    380  =  2631μS
 10%  =    190  =  5263μS
  1%  =     19  = 52632μS 
 */


