#include <Servo.h>
#include "LegServos.h"

void setup() {
  initServos();  
  hexapodUpTest(1);  
  leg1LiftTest(1);  
  leg3LiftTest(1);      
}

void loop() {
  leg1LiftTest(1);  
  leg3LiftTest(1);     
//  
//  for(int i = 0; i < 3; i++) { // up down 3 times
//    hexapodUpTest(1); hexapodUpTest(-1);    
//  }
//
//  hexapodClockwiseTest(1);
//  hexapodClockwiseTest(-1);
//  
//  for(int i = 0; i < 3; i++) { // forward 3 times
//      forwardTest(1);
//  }
//
//  for(int i = 0; i < 2; i++) {  // lift legs 2 times
//    leg1UpTest(1);  leg1UpTest(-1);
//    leg2UpTest(1);  leg2UpTest(-1);
//    leg3UpTest(1);  leg3UpTest(-1);
//    leg4UpTest(1);  leg4UpTest(-1);    
//  }
//  
//  for(int i = 0; i < 3; i++) { // back 3 times
//      forwardTest(-1);
//  }  
//  
//  for(int i = 0; i < 3; i++) {  // turn right 3 times
//    turnRightTest(1);
//  }
//  
//  for(int i = 0; i < 3; i++) {  // turn left 3 times
//    turnRightTest(-1);
//  }
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

void turnRightTest(int deg) {
  forLoop(45, hexapodClockwise, -deg);
  
  // leg one by one
  int multipleDeg = deg * 2;
  legClockwise(leg1_1Clockwise,  multipleDeg);
  legClockwise(leg3_1Clockwise,  multipleDeg);
  legClockwise(leg2_1Clockwise,  multipleDeg);
  legClockwise(leg4_1Clockwise,  multipleDeg); 
}

void forwardTest(int deg) {
  int multipleDeg = deg * 2;  

  legClockwise(leg4_1Clockwise,  multipleDeg);
  legClockwise(leg3_1Clockwise,  multipleDeg);  
  legClockwise(leg2_1Clockwise,  -multipleDeg);  
  legClockwise(leg1_1Clockwise,  -multipleDeg);    
  forLoop(92, hexapodForerake, deg);  
  legClockwise(leg4_1Clockwise,  multipleDeg);
  legClockwise(leg3_1Clockwise,  multipleDeg);    
  legClockwise(leg2_1Clockwise,  -multipleDeg);  
  legClockwise(leg1_1Clockwise,  -multipleDeg);    
}

void leg1LiftTest(int deg) {
  forLoop(60, leg2Up, 1);
  forLoop(60, leg3Up, 1);
  forLoop(60, leg4Up, -1);
  forLoop(60, leg1Up, -1);  
  forLoop(60, leg1Up, 1);
  forLoop(60, leg4Up, 1);
  forLoop(60, leg3Up, -1);
  forLoop(60, leg2Up, -1);    
}

void leg3LiftTest(int deg) {
  forLoop(60, leg1Up, 1);
  forLoop(60, leg4Up, 1);
  forLoop(60, leg2Up, -1);
  forLoop(60, leg3Up, -1);  
  forLoop(60, leg3Up, 1);
  forLoop(60, leg2Up, 1);
  forLoop(60, leg4Up, -1);
  forLoop(60, leg1Up, -1);    
}



