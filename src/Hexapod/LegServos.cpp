#include <Arduino.h>
#include <Servo.h>
#include "LegServos.h"

Servo servos[4][3];

int degs[4][3] = {
  {90, 180, 180}, // LEG3 - Servo 1, 2, 3
  {90, 180, 180}, // LEG4 - Servo 1, 2, 3
  {90, 0,   0},   // LEG2 - Servo 1, 2, 3
  {90, 0,   0}    // LEG1 - Servo 1, 2, 3
};

int delayMillis = 1;

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
      servos[i][j].write(degs[i][j]); 
      delay(delayMillis);
    }
  }
}

void forLoop(int to,  void (*fn)(int), int arg) {
  for(int i = 0; i < to; i++) {
    fn(arg);
  }
}

// servo setup

void leg1_1ClockwiseSet(int deg) {
  degs[3][0] += deg;
}

void leg2_1ClockwiseSet(int deg) {
  degs[2][0] += deg;
}

void leg3_1ClockwiseSet(int deg) {
  degs[0][0] += deg;
}

void leg4_1ClockwiseSet(int deg) {
  degs[1][0] += deg;
}

void leg1_2DownSet(int deg) {
  degs[3][1] += deg;
}

void leg2_2DownSet(int deg) {
  degs[2][1] += deg;
}

void leg3_2DownSet(int deg) {
  degs[0][1] -= deg;
}

void leg4_2DownSet(int deg) {
  degs[1][1] -= deg;
}

void leg1_3DownSet(int deg) {
  degs[3][2] += deg;
}

void leg2_3DownSet(int deg) {
  degs[2][2] += deg;
}

void leg3_3DownSet(int deg) {
  degs[0][2] -= deg;
}

void leg4_3DownSet(int deg) {
  degs[1][2] -= deg;
}

// basic movement

void leg1Up(int deg) {
  leg1_2DownSet(deg); leg1_3DownSet(deg); 
  updateServos();
}

void leg2Up(int deg) {
  leg2_2DownSet(deg); leg2_3DownSet(deg); 
  updateServos();
}

void leg3Up(int deg) {
  leg3_2DownSet(deg); leg3_3DownSet(deg); 
  updateServos();
}

void leg4Up(int deg) {
  leg4_2DownSet(deg); leg4_3DownSet(deg); 
  updateServos();
}

void hexapodUp(int deg) {
  leg1_2DownSet(deg); leg2_2DownSet(deg); leg3_2DownSet(deg); leg4_2DownSet(deg);
  leg1_3DownSet(deg); leg2_3DownSet(deg); leg3_3DownSet(deg); leg4_3DownSet(deg);
  updateServos();
}

void hexapodClockwise(int deg) {
  leg1_1ClockwiseSet(deg);
  leg2_1ClockwiseSet(deg);
  leg3_1ClockwiseSet(deg);
  leg4_1ClockwiseSet(deg);
  updateServos();
}

void hexapodForerake(int deg) {
  leg1_1ClockwiseSet(deg);
  leg2_1ClockwiseSet(deg);
  leg3_1ClockwiseSet(-deg);
  leg4_1ClockwiseSet(-deg);
  updateServos();
}

void leg1_1Clockwise(int deg) {
  leg1_1ClockwiseSet(deg);
  updateServos();
}

void leg2_1Clockwise(int deg) {
  leg2_1ClockwiseSet(deg);
  updateServos();
}

void leg3_1Clockwise(int deg) {
  leg3_1ClockwiseSet(deg);
  updateServos();
}

void leg4_1Clockwise(int deg) {
  leg4_1ClockwiseSet(deg);
  updateServos();
}

void legClockwise(void (*legClockwise)(int), int deg) {
  leg1Up(-15);
  forLoop(22, legClockwise, deg);
  leg1Up(15);  
}
