#define MICROSECONDS 250

void initServos();
void updateServos();
void forLoop(int to,  void (*fn)(int), int arg);

// step servo degrees data 

void joint1_1ClkDataStep(int deg);
void joint2_1ClkDataStep(int deg);
void joint3_1ClkDataStep(int deg);
void joint4_1ClkDataStep(int deg);

void joint1_2DownDataStep(int deg);
void joint2_2DownDataStep(int deg);
void joint3_2DownDataStep(int deg);
void joint4_2DownDataStep(int deg);

void joint1_3DownDataStep(int deg);
void joint2_3DownDataStep(int deg);
void joint3_3DownDataStep(int deg);
void joint4_3DownDataStep(int deg);

// basic step action

void leg1UpStep(int deg);
void leg2UpStep(int deg);
void leg3UpStep(int deg);
void leg4UpStep(int deg);

void hexapodUpStep(int deg);

void hexapodClockwiseStep(int deg);

void joint1_1ClkStep(int deg);
void joint2_1ClkStep(int deg);
void joint3_1ClkStep(int deg);
void joint4_1ClkStep(int deg);


