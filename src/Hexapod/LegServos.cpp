#include <Arduino.h>
#include <Servo.h>
#include "LegServos.h"

Servo servos[4][3];

int degOfServo[4][3] = {
  {90, 180, 180}, // LEG3 - Servo 1, 2, 3
  {90, 180, 180}, // LEG4 - Servo 1, 2, 3
  {90, 0,   0},   // LEG2 - Servo 1, 2, 3
  {90, 0,   0}    // LEG1 - Servo 1, 2, 3
};

void initServos() {
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 3; j++) {
      servos[i][j].attach(8 + i * 3 + j);
    }
  }
  updateServos();
}

void updateServos() {
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < 3; j++) {
      servos[i][j].write(degOfServo[i][j]); 
      delayMicroseconds(MICROSECONDS);
    }
  }
}

void forLoop(int to,  void (*fn)(int), int arg) {
  for(int i = 0; i < to; i++) {
    fn(arg);
  }
}

// step servo degree data 

void joint1_1ClkDataStep(int deg) {
  degOfServo[3][0] += deg;
}

void joint2_1ClkDataStep(int deg) {
  degOfServo[2][0] += deg;
}

void joint3_1ClkDataStep(int deg) {
  degOfServo[0][0] += deg;
}

void joint4_1ClkDataStep(int deg) {
  degOfServo[1][0] += deg;
}

void joint1_2DownDataStep(int deg) {
  degOfServo[3][1] += deg;
}

void joint2_2DownDataStep(int deg) {
  degOfServo[2][1] += deg;
}

void joint3_2DownDataStep(int deg) {
  degOfServo[0][1] -= deg;
}

void joint4_2DownDataStep(int deg) {
  degOfServo[1][1] -= deg;
}

void joint1_3DownDataStep(int deg) {
  degOfServo[3][2] += deg;
}

void joint2_3DownDataStep(int deg) {
  degOfServo[2][2] += deg;
}

void joint3_3DownDataStep(int deg) {
  degOfServo[0][2] -= deg;
}

void joint4_3DownDataStep(int deg) {
  degOfServo[1][2] -= deg;
}

// basic step actions

void leg1UpStep(int deg) {
  joint1_2DownDataStep(deg); joint1_3DownDataStep(deg); 
  updateServos();
}

void leg2UpStep(int deg) {
  joint2_2DownDataStep(deg); joint2_3DownDataStep(deg); 
  updateServos();
}

void leg3UpStep(int deg) {
  joint3_2DownDataStep(deg); joint3_3DownDataStep(deg); 
  updateServos();
}

void leg4UpStep(int deg) {
  joint4_2DownDataStep(deg); joint4_3DownDataStep(deg); 
  updateServos();
}

void hexapodUpStep(int deg) {
  joint1_2DownDataStep(deg); joint2_2DownDataStep(deg); joint3_2DownDataStep(deg); joint4_2DownDataStep(deg);
  joint1_3DownDataStep(deg); joint2_3DownDataStep(deg); joint3_3DownDataStep(deg); joint4_3DownDataStep(deg);
  updateServos();
}

void hexapodClockwiseStep(int deg) {
  joint1_1ClkDataStep(-deg);
  joint2_1ClkDataStep(-deg);
  joint3_1ClkDataStep(-deg);
  joint4_1ClkDataStep(-deg);
  updateServos();
}

void joint1_1ClkStep(int deg) {
  joint1_1ClkDataStep(deg);
  updateServos();
}

void joint2_1ClkStep(int deg) {
  joint2_1ClkDataStep(deg);
  updateServos();
}

void joint3_1ClkStep(int deg) {
  joint3_1ClkDataStep(deg);
  updateServos();
}

void joint4_1ClkStep(int deg) {
  joint4_1ClkDataStep(deg);
  updateServos();
}


