void initServos();
void updateServos();
void forLoop(int to,  void (*fn)(int), int arg);

// servo setup

void leg1_1ClockwiseSet(int deg);
void leg2_1ClockwiseSet(int deg);
void leg3_1ClockwiseSet(int deg);
void leg4_1ClockwiseSet(int deg);

void leg1_2DownSet(int deg);
void leg2_2DownSet(int deg);
void leg3_2DownSet(int deg);
void leg4_2DownSet(int deg);
void leg1_3DownSet(int deg);
void leg2_3DownSet(int deg);
void leg3_3DownSet(int deg);
void leg4_3DownSet(int deg);

// basic movement

void leg1Up(int deg);
void leg2Up(int deg);
void leg3Up(int deg);
void leg4Up(int deg);

void hexapodUp(int deg);

void hexapodClockwise(int deg);

void hexapodForerake(int deg);

void leg1_1Clockwise(int deg);
void leg2_1Clockwise(int deg);
void leg3_1Clockwise(int deg);
void leg4_1Clockwise(int deg);

void legClockwise(void (*legClockwise)(int), int deg);
