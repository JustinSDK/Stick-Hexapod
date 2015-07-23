#include <Servo.h>
#include "LegServos.h"

#define UP 1
#define DOWN -1
#define CLK 1
#define CT_CLK -1

void setup() {
  initServos();  
  hexapod(UP);  
}

void loop() {
  leg1UpDown();  
  leg2UpDown();    
  leg3UpDown();  
  leg4UpDown();

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

void leg1UpDown() {
  forLoop(75, leg4UpStep, -1);
  forLoop(60, leg1UpStep, -1);  
  forLoop(60, leg1UpStep, 1);
  forLoop(75, leg4UpStep, 1);
}

void leg2UpDown() {
  forLoop(75, leg3UpStep, -1);
  forLoop(60, leg2UpStep, -1);  
  forLoop(60, leg2UpStep, 1);
  forLoop(75, leg3UpStep, 1);
}

void leg3UpDown() {
  forLoop(75, leg2UpStep, -1);
  forLoop(60, leg3UpStep, -1);  
  forLoop(60, leg3UpStep, 1);
  forLoop(75, leg2UpStep, 1);    
}

void leg4UpDown() {
  forLoop(75, leg1UpStep, -1);
  forLoop(60, leg4UpStep, -1);  
  forLoop(60, leg4UpStep, 1);
  forLoop(75, leg1UpStep, 1);    
}

void leg1Turn(int dir) {
  forLoop(75, leg4UpStep, -1);
  forLoop(60, leg1UpStep, -1);  
  forLoop(45, joint1_1ClkStep, dir);
  forLoop(60, leg1UpStep, 1);
  forLoop(75, leg4UpStep, 1);  
}

void leg2Turn(int dir) {
  forLoop(75, leg3UpStep, -1);
  forLoop(60, leg2UpStep, -1);  
  forLoop(45, joint2_1ClkStep, dir);  
  forLoop(60, leg2UpStep, 1);
  forLoop(75, leg3UpStep, 1);
}

void leg3Turn(int dir) {
  forLoop(75, leg2UpStep, -1);
  forLoop(60, leg3UpStep, -1);  
  forLoop(45, joint3_1ClkStep, dir);  
  forLoop(60, leg3UpStep, 1);
  forLoop(75, leg2UpStep, 1); 
}

void leg4Turn(int dir) {
  forLoop(75, leg1UpStep, -1);
  forLoop(60, leg4UpStep, -1);  
  forLoop(45, joint4_1ClkStep, dir);  
  forLoop(60, leg4UpStep, 1);
  forLoop(75, leg1UpStep, 1);    
}

void hexapodTurn(int dir) {
  forLoop(45, hexapodClockwiseStep, dir);
  
  leg1Turn(dir);
  
  if(dir == CLK) {
    leg2Turn(dir);
  } else {
    leg3Turn(dir);
 }    

  leg4Turn(dir);   

  if(dir == CLK) {  
    leg3Turn(dir);
  } else {
    leg2Turn(dir);
  }
}

void leg12Turn(int dir) {
  joint1_1ClkDataStep(dir);
  joint2_1ClkDataStep(dir);    
  updateServos();  
}

void leg34Turn(int dir) {
  joint3_1ClkDataStep(dir);
  joint4_1ClkDataStep(dir);    
  updateServos();
}

void moveForward() {
  leg2Turn(CT_CLK);  
  forLoop(45, leg12Turn, CLK);
  leg1Turn(CT_CLK);
  
  leg4Turn(CLK);   
  forLoop(45, leg34Turn, CT_CLK);
  leg3Turn(CLK);
}





