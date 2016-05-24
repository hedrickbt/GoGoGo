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



#define lmencpin    3                                     //  D2 is the pin for external interrupt 0
#define rmencpin    2                                     //  D3 is the pin for external interrupt 1

volatile unsigned int lpulse=100000;                      // width of left and right encoder pulses in uS
volatile unsigned int rpulse=100000;                      // width of left and right encoder pulses in uS
volatile unsigned int lcount,rcount;                      // left and right pulse counters to measure distance
volatile unsigned long ltime;                             // remembers time of left  encoders last state change in uS
volatile unsigned long rtime;                             // remembers time of right encoders last state change in uS

boolean debug = true;


// the setup routine runs once when you press reset:
void setup() {         
  Serial.begin(9600);  

  attachInterrupt(0,Rencoder,CHANGE);                     // trigger right encoder ISR on state change
  attachInterrupt(1,Lencoder,CHANGE);                     // trigger left  encoder ISR on state change
  
}

// the loop routine runs over and over again forever:
void loop() {
  //======================================================== Motor Speed Control =========================================================
  
  Serial.print("R/L count/Pulse/time: ");
  Serial.print(rcount);
  Serial.print("/");
  Serial.print(rpulse);
  Serial.print("/");
  Serial.print(rtime);
  Serial.print(" ");
  Serial.print(lcount);
  Serial.print("/");
  Serial.print(lpulse);
  Serial.print("/");
  Serial.println(ltime);
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


