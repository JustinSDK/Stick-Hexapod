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
}

void loop() {
  upTest(1);
  clockWiseTest(1);  
  clockWiseTest(-1);
  forerakeTest(1);
  forerakeTest(-1);
  upTest(-1);
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

void leg1_1ClockWise(int deg) {
  degs[3][0] += deg;
}

void leg2_1ClockWise(int deg) {
  degs[2][0] += deg;
}

void leg3_1ClockWise(int deg) {
  degs[0][0] += deg;
}

void leg4_1ClockWise(int deg) {
  degs[1][0] += deg;
}

void leg1_2Up(int deg) {
  degs[3][1] += deg;
}

void leg2_2Up(int deg) {
  degs[2][1] += deg;
}

void leg3_2Up(int deg) {
  degs[0][1] -= deg;
}

void leg4_2Up(int deg) {
  degs[1][1] -= deg;
}

void leg1_3Up(int deg) {
  degs[3][2] += deg;
}

void leg2_3Up(int deg) {
  degs[2][2] += deg;
}

void leg3_3Up(int deg) {
  degs[0][2] -= deg;
}

void leg4_3Up(int deg) {
  degs[1][2] -= deg;
}

void upTest(int deg) {
  for(int i = 0; i < 45; i++) {
    leg1_2Up(deg); leg2_2Up(deg); leg3_2Up(deg); leg4_2Up(deg);
    leg1_3Up(deg); leg2_3Up(deg); leg3_3Up(deg); leg4_3Up(deg);
    updateServos();
  }  
}

void clockWiseTest(int deg) {
  for(int i = 0; i < 45; i += 1) {
    leg1_1ClockWise(deg);
    leg2_1ClockWise(deg);
    leg3_1ClockWise(deg);
    leg4_1ClockWise(deg);
    updateServos();
  }
  for(int i = 0; i < 45; i += 1) {
    leg1_1ClockWise(-deg);
    leg2_1ClockWise(-deg);
    leg3_1ClockWise(-deg);
    leg4_1ClockWise(-deg);
    updateServos();    
  }  
}

void forerakeTest(int deg) {
  for(int i = 0; i < 30; i += 1) {
    leg1_1ClockWise(deg);
    leg2_1ClockWise(deg);
    leg3_1ClockWise(-deg);
    leg4_1ClockWise(-deg);
    updateServos();    
  }
  for(int i = 0; i < 30; i += 1) {
    leg1_1ClockWise(-deg);
    leg2_1ClockWise(-deg);
    leg3_1ClockWise(deg);
    leg4_1ClockWise(deg);
    updateServos();    
  }    
}

