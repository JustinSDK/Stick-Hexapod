#include <Servo.h>
#include "LegServos.h"

#define UP 1
#define DOWN -1
#define CLK 1
#define CT_CLK -1
#define BACK 1

void setup() {
  initServos();  
  hexapod(UP);  
}

void loop() {
  for(int i = 0; i < 3; i++) {
    hexapod(DOWN);  
    hexapod(UP);  
  }
  
  hello();

  hexapodTurn(CLK);
  hexapodTurn(CT_CLK);  

  for(int i = 0; i < 3; i++) {
    moveForward();
  }
}

// continuous movements

void hexapod(int dir) {
  forLoop(90, hexapodUpStep, dir);
}

void hello() {
  forLoop(60, leg1UpStep, -1);
  delay(100);
  for(int i = 0; i < 3; i++) {
    forLoop(90, joint1_1ClkStep, CT_CLK);
    forLoop(90, joint1_1ClkStep, CLK);
  }
  delay(100);
  forLoop(60, leg1UpStep, 1);
}

void leg1Turn(int dir, int angle) {
  forLoop(60, leg1UpStep, -1);  
  forLoop(angle, joint1_1ClkStep, dir);
  forLoop(60, leg1UpStep, 1);
}

void leg2Turn(int dir, int angle) {
  forLoop(60, leg2UpStep, -1);  
  forLoop(angle, joint2_1ClkStep, dir);  
  forLoop(60, leg2UpStep, 1);
}

void leg3Turn(int dir, int angle) {
  forLoop(60, leg3UpStep, -1);  
  forLoop(angle, joint3_1ClkStep, dir);  
  forLoop(60, leg3UpStep, 1);
}

void leg4Turn(int dir, int angle) {
  forLoop(60, leg4UpStep, -1);  
  forLoop(angle, joint4_1ClkStep, dir);  
  forLoop(60, leg4UpStep, 1);
}

void hexapodTurn(int dir) {
  if(dir == CLK) {
    leg2Turn(dir, 45);
    forLoop(45, hexapodClockwiseStep, dir);
    leg2Turn(dir, 45);
    leg4Turn(dir, 90);
  
    leg3Turn(dir, 45);
    forLoop(45, hexapodClockwiseStep, dir);  
    leg3Turn(dir, 45);
    leg1Turn(dir, 90);
  } else {  
    leg1Turn(dir, 45);
    forLoop(45, hexapodClockwiseStep, dir);  
    leg1Turn(dir, 45);
    leg3Turn(dir, 90);
  
    leg4Turn(dir, 45);
    forLoop(45, hexapodClockwiseStep, dir);  
    leg4Turn(dir, 45);
    leg2Turn(dir, 90);  
  }
}

void leg234Push(int dir) {
  joint2_1ClkDataStep(dir);
  joint3_1ClkDataStep(-dir);      
  joint4_1ClkDataStep(-dir);      
  updateServos();
}

void leg124Push(int dir) {
  joint1_1ClkDataStep(dir);
  joint2_1ClkDataStep(dir);
  joint4_1ClkDataStep(-dir);      
  updateServos();
}

void moveForward() {
  leg1Turn(CT_CLK, 45);
  forLoop(45, leg234Push, BACK);
  leg4Turn(CLK, 90);  
  
  leg3Turn(CLK, 45);
  forLoop(45, leg124Push, BACK);  
  leg2Turn(CT_CLK, 90);
}





