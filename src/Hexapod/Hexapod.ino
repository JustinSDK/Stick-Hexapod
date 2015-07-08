#include <Servo.h>

Servo servos[4][3];

int degs[4][3] = {
  {90, 180, 180}, // LEG3
  {90, 180, 180}, // LEG4
  {90, 0,   0},   // LEG2
  {90, 0,   0}    // LEG1 
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

void upTest() {
  for(int i = degs[0][1], j = degs[2][1]; degs[0][1] > 135, degs[2][1] < 45; i -= 1, j += 1) {
    degs[0][1] = i; degs[0][2] = i;  // LEG3
    degs[1][1] = i; degs[1][2] = i;  // LEG4
    degs[2][1] = j; degs[2][2] = j;  // LEG2
    degs[3][1] = j; degs[3][2] = j;  // LEG1
    updateServos();
  }  
}

void downTest() {
  for(int i = degs[0][1], j = degs[2][1]; degs[0][1] < 180, degs[2][1] > 0; i += 1, j -= 1) {
    degs[0][1] = i; degs[0][2] = i;  // LEG3
    degs[1][1] = i; degs[1][2] = i;  // LEG4
    degs[2][1] = j; degs[2][2] = j;  // LEG2
    degs[3][1] = j; degs[3][2] = j;  // LEG1
    updateServos();
  }  
}

void upDownTest() {
   upTest();
   downTest();
}

void setup() {
  initServos();  
}

void loop() {
  upDownTest();
}

