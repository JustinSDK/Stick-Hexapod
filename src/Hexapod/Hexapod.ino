#include <Servo.h>
#include "LegServos.h"

void setup() {
  initServos();  
  hexapodUpTest(1);  
}

void loop() {
  leg1LiftTest(1);  
  leg2LiftTest(1);    
  leg3LiftTest(1);  
  leg4LiftTest(1);

  turnRightTest(1);
  turnRightTest(-1);  
  
  for(int i = 0; i < 3; i++) {
    forwardTest(1);
  }
}

// for testing

void leg1UpTest(int deg) {
  forLoop(45, leg1Up, deg);
}

void leg2UpTest(int deg) {
  forLoop(45, leg2Up, deg);
}

void leg3UpTest(int deg) {
  forLoop(45, leg3Up, deg);
}

void leg4UpTest(int deg) {
  forLoop(45, leg4Up, deg);
}

void hexapodUpTest(int deg) {
  forLoop(90, hexapodUp, deg);
}

void hexapodClockwiseTest(int deg) {
  forLoop(45, hexapodClockwise, deg);
  forLoop(45, hexapodClockwise, -deg);
}

void turnRightTest(int deg) {
  forLoop(45, hexapodClockwise, -deg);
  
  leg1Clockwise(deg);
  
  if(deg > 0) {
    leg2Clockwise(deg);
  } else {
    leg3Clockwise(deg);
 }    

  leg4Clockwise(deg);   

  if(deg > 0) {  
    leg3Clockwise(deg);
  } else {
    leg2Clockwise(deg);
  }
}

void forwardTest(int deg) {
  leg2Clockwise(-deg);  
  // right 2 back
  for(int i = 0; i < 45; i++) {
    leg1_1ClockwiseSet(deg);
    leg2_1ClockwiseSet(deg);    
    updateServos();
  }
  leg1Clockwise(-deg);
  
  leg4Clockwise(deg);   
  // left 2 back
  for(int i = 0; i < 45; i++) {
    leg3_1ClockwiseSet(-deg);
    leg4_1ClockwiseSet(-deg);    
    updateServos();
  }  
  leg3Clockwise(deg);
}

void leg1LiftTest(int deg) {
  forLoop(75, leg4Up, -1);
  forLoop(60, leg1Up, -1);  
  forLoop(60, leg1Up, 1);
  forLoop(75, leg4Up, 1);
}

void leg2LiftTest(int deg) {
  forLoop(75, leg3Up, -1);
  forLoop(60, leg2Up, -1);  
  forLoop(60, leg2Up, 1);
  forLoop(75, leg3Up, 1);
}

void leg3LiftTest(int deg) {
  forLoop(75, leg2Up, -1);
  forLoop(60, leg3Up, -1);  
  forLoop(60, leg3Up, 1);
  forLoop(75, leg2Up, 1);    
}

void leg4LiftTest(int deg) {
  forLoop(75, leg1Up, -1);
  forLoop(60, leg4Up, -1);  
  forLoop(60, leg4Up, 1);
  forLoop(75, leg1Up, 1);    
}

