#include <Servo.h>
#include "LegServos.h"

void setup() {
  initServos();  
  hexapodUpTest(1);  
}

void loop() {
  for(int i = 0; i < 3; i++) { // up down 3 times
    hexapodUpTest(1); hexapodUpTest(-1);    
  }
  for(int i = 0; i < 3; i++) {  // lift legs 3 times
    leg1UpTest(1);  leg1UpTest(-1);
    leg2UpTest(1);  leg2UpTest(-1);
    leg3UpTest(1);  leg3UpTest(-1);
    leg4UpTest(1);  leg4UpTest(-1);    
  }
  
  for(int i = 0; i < 3; i++) {  // turn right 3 times
    turnRightTest(1);
  }
  
  for(int i = 0; i < 3; i++) {  // turn left 3 times
    turnRightTest(-1);
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
  forLoop(45, hexapodUp, deg);
}

void hexapodClockwiseTest(int deg) {
  forLoop(45, hexapodClockwise, deg);
  forLoop(45, hexapodClockwise, -deg);
}

void hexapodForerakeTest(int deg) {
  forLoop(30, hexapodForerake, deg);
  forLoop(30, hexapodForerake, -deg);
}

void turnRightTest(int deg) {
  forLoop(45, hexapodClockwise, -deg);
  
  // leg one by one
  int multipleDeg = deg * 2;
  
  leg1Up(-15);
  forLoop(22, leg1_1Clockwise, multipleDeg);
  leg1Up(15);

  leg3Up(-15);
  forLoop(22, leg3_1Clockwise, multipleDeg);
  leg3Up(15);
  
  leg2Up(-15);
  forLoop(22, leg2_1Clockwise, multipleDeg);
  leg2Up(15);
    
  leg4Up(-15);
  forLoop(22, leg4_1Clockwise, multipleDeg);
  leg4Up(15); 
}

