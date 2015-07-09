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
  upTest(1);  
}

void loop() {
  for(int i = 0; i < 3; i++) { // up down 3 times
    upTest(1); upTest(-1);    
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

void leg1_1Clockwise(int deg) {
  degs[3][0] += deg;
}

void leg2_1Clockwise(int deg) {
  degs[2][0] += deg;
}

void leg3_1Clockwise(int deg) {
  degs[0][0] += deg;
}

void leg4_1Clockwise(int deg) {
  degs[1][0] += deg;
}

void leg1_2Down(int deg) {
  degs[3][1] += deg;
}

void leg2_2Down(int deg) {
  degs[2][1] += deg;
}

void leg3_2Down(int deg) {
  degs[0][1] -= deg;
}

void leg4_2Down(int deg) {
  degs[1][1] -= deg;
}

void leg1_3Down(int deg) {
  degs[3][2] += deg;
}

void leg2_3Down(int deg) {
  degs[2][2] += deg;
}

void leg3_3Down(int deg) {
  degs[0][2] -= deg;
}

void leg4_3Down(int deg) {
  degs[1][2] -= deg;
}

void leg1UpTest(int deg) {
  for(int i = 0; i < 45; i++) {
    leg1_2Down(deg); leg1_3Down(deg); 
    updateServos();
  }  
}

void leg2UpTest(int deg) {
  for(int i = 0; i < 45; i++) {
    leg2_2Down(deg); leg2_3Down(deg); 
    updateServos();
  }  
}

void leg3UpTest(int deg) {
  for(int i = 0; i < 45; i++) {
    leg3_2Down(deg); leg3_3Down(deg); 
    updateServos();
  }  
}

void leg4UpTest(int deg) {
  for(int i = 0; i < 45; i++) {
    leg4_2Down(deg); leg4_3Down(deg); 
    updateServos();
  }  
}

void upTest(int deg) {
  for(int i = 0; i < 45; i++) {
    leg1_2Down(deg); leg2_2Down(deg); leg3_2Down(deg); leg4_2Down(deg);
    leg1_3Down(deg); leg2_3Down(deg); leg3_3Down(deg); leg4_3Down(deg);
    updateServos();
  }  
}

void clockwiseTest(int deg) {
  for(int i = 0; i < 45; i++) {
    leg1_1Clockwise(deg);
    leg2_1Clockwise(deg);
    leg3_1Clockwise(deg);
    leg4_1Clockwise(deg);
    updateServos();
  }
  for(int i = 0; i < 45; i++) {
    leg1_1Clockwise(-deg);
    leg2_1Clockwise(-deg);
    leg3_1Clockwise(-deg);
    leg4_1Clockwise(-deg);
    updateServos();    
  }  
}

void forerakeTest(int deg) {
  for(int i = 0; i < 30; i++) {
    leg1_1Clockwise(deg);
    leg2_1Clockwise(deg);
    leg3_1Clockwise(-deg);
    leg4_1Clockwise(-deg);
    updateServos();    
  }
  for(int i = 0; i < 30; i++) {
    leg1_1Clockwise(-deg);
    leg2_1Clockwise(-deg);
    leg3_1Clockwise(deg);
    leg4_1Clockwise(deg);
    updateServos();    
  }    
}

void turnRightTest(int deg) {
  for(int i = 0; i < 45; i++) {
    leg1_1Clockwise(-deg);
    leg2_1Clockwise(-deg);
    leg3_1Clockwise(-deg);
    leg4_1Clockwise(-deg);
    updateServos();
  }
  // leg one by one
  int multipleDeg = deg * 2;
  int absMultipleDeg = abs(multipleDeg);
  
  leg1_2Down(-15); leg1_3Down(-15); 
  for(int i = 0; i < 45; i += absMultipleDeg) {
      leg1_1Clockwise(multipleDeg);
      updateServos();
  }  
  leg1_2Down(15); leg1_3Down(15); 

  leg3_2Down(-15); leg3_3Down(-15);   
  for(int i = 0; i < 45; i += absMultipleDeg) {
      leg3_1Clockwise(multipleDeg);
      updateServos();
  }  
  leg3_2Down(15); leg3_3Down(15); 
  
  leg2_2Down(-15); leg2_3Down(-15); 
  for(int i = 0; i < 45; i += absMultipleDeg) {
      leg2_1Clockwise(multipleDeg);
      updateServos();
  } 
  leg2_2Down(15); leg2_3Down(15);  
    
  leg4_2Down(-15); leg4_3Down(-15); 
  for(int i = 0; i < 45; i += absMultipleDeg) {
      leg4_1Clockwise(multipleDeg);
      updateServos();
  } 
  leg4_2Down(15); leg4_3Down(15);   
}

