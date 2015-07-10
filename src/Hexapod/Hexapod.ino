#include <Servo.h>

Servo servos[4][3];

int degs[4][3] = {
  {90, 180, 180}, // LEG3 - Servo 1, 2, 3
  {90, 180, 180}, // LEG4 - Servo 1, 2, 3
  {90, 0,   0},   // LEG2 - Servo 1, 2, 3
  {90, 0,   0}    // LEG1 - Servo 1, 2, 3
};

int delayMillis = 1;

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

