#include <trajectory.h>
#include <Servo.h>

Trajectory servoTrajectoryHL(30);
Trajectory servoTrajectoryKL(30);
Trajectory servoTrajectoryAL(30);
Trajectory servoTrajectoryHR(30);
Trajectory servoTrajectoryKR(30);
Trajectory servoTrajectoryAR(30);

Servo hipR;
Servo kneeR;
Servo ankleR;
Servo hipL;
Servo kneeL;
Servo ankleL;

// --- Define global variables ---
// The controller will be updated at a rate of 100Hz
#define UPDATE_FREQUENCY 100
#define UPDATE_TIME (1000 / UPDATE_FREQUENCY)
unsigned long updateTimer = 0;

int moveNumberHipL = 0;
int moveNumberKneeL = 0;
int moveNumberAnkleL = 0;
int moveNumberHipR = 0;
int moveNumberKneeR = 0;
int moveNumberAnkleR = 0;

float sudutHipL, sudutHipR, sudutKneeL, sudutKneeR, sudutAnkleL, sudutAnkleR;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Starting program");
  
  hipR.attach(A0);    // attaches hip R Servo on pin A0 to the servo object
  kneeR.attach(A1);   // attaches knee R Servo on pin A1 to the servo object
  ankleR.attach(A2);  // attaches ankle R Servo on pin A2 to the servo object
  hipL.attach(A3);    // attaches hip L Servo on pin A3 to the servo object
  kneeL.attach(A4);   // attaches knee L Servo on pin A4 to the servo object
  ankleL.attach(A5);  // attaches ankle L Servo on pin A5 to the servo object

  servoTrajectoryHL.reset(90);
  servoTrajectoryKL.reset(90);
  servoTrajectoryKL.reset(90);
  servoTrajectoryHR.reset(0);
  servoTrajectoryKR.reset(0);
  servoTrajectoryKR.reset(90);

};

// NORMAL WALKING
void nextMove() {
  switch (moveNumberHipL) {
    case 0:
      servoTrajectoryHL.setTargetPos(72, 0.08);
      break;

    case 1:
      // First we move to the 180° position as fast as possible
      servoTrajectoryHL.setTargetPos(108, 0.27);
      break;

    case 2:
      // Then move back to 20° as fast as possible
      servoTrajectoryHL.setTargetPos(69, 0.55);
      break;

    case 3:
      // Next move to 180°, but over the course of 5 seconds
      servoTrajectoryHL.setTargetPos(108, 0.10);
      break;
    
    case 4:
      moveNumberHipL = -1;
      break;
   }

  switch (moveNumberKneeL) {
    case 0:
      servoTrajectoryKL.setTargetPos(92, 0.01); 
      break;

    case 1:
      // First we move to the 180° position as fast as possible
      servoTrajectoryKL.setTargetPos(109, 0.16); 
      break;

    case 2:
      // Then move back to 20° as fast as possible
      servoTrajectoryKL.setTargetPos(98, 0.29); 
      break;

    case 3:
      // Next move to 180°, but over the course of 5 seconds
      servoTrajectoryKL.setTargetPos(148, 0.31);
      break;

    case 4: 
      servoTrajectoryKL.setTargetPos(92, 0.24);
      break;

    case 5:
      moveNumberKneeL = -1;
      break;
  }

  switch (moveNumberAnkleL) {
    case 0:
      servoTrajectoryAL.setTargetPos(88, 0.04);
      break;

    case 1:
      // First we move to the 180° position as fast as possible
      servoTrajectoryAL.setTargetPos(88, 0.08);
      break;

    case 2:
      // Then move back to 20° as fast as possible
      servoTrajectoryAL.setTargetPos(69, 0.19);
      break;

    case 3:
      // Next move to 180°, but over the course of 5 seconds
      servoTrajectoryAL.setTargetPos(88, 0.16);
      break;

    case 4: 
      servoTrajectoryAL.setTargetPos(41, 0.25);
      break;
    
    case 5: 
      servoTrajectoryAL.setTargetPos(88, 0.28);
      break;
    
    case 6:
      moveNumberAnkleL = -1;
      break;
  }

  switch (moveNumberHipR) {
    case 0:
      servoTrajectoryHR.setTargetPos(0, 0.01);
      break;

    case 1:
      // First we move to the 180° position as fast as possible
      servoTrajectoryHR.setTargetPos(21, 0.40);
      break;

    case 2:
      // Then move back to 20° as fast as possible
      servoTrajectoryHR.setTargetPos(0, 0.60);
      break;
    
    case 3:
      moveNumberHipR = -1;
      break;
  }

  switch (moveNumberKneeR) {
    case 0:
      servoTrajectoryKR.setTargetPos(11, 0.01);
      break;

    case 1:
      // First we move to the 180° position as fast as possible
      servoTrajectoryKR.setTargetPos(54, 0.21);
      break;

    case 2:
      // Then move back to 20° as fast as possible
      servoTrajectoryKR.setTargetPos(2, 0.30);
      break;

    case 3:
      // Next move to 180°, but over the course of 5 seconds
      servoTrajectoryKR.setTargetPos(19, 0.15);
      break;

    case 4: 
      servoTrajectoryKR.setTargetPos(8, 0.26);
      break;

    case 5: 
      servoTrajectoryKR.setTargetPos(9, 0.08);
      break;

    case 6:
      moveNumberKneeR = -1;
      break;
  }

  switch (moveNumberAnkleR) {
    case 0:
      servoTrajectoryAR.setTargetPos(85, 0.03);
      break;

    case 1:
      // First we move to the 180° position as fast as possible
      servoTrajectoryAR.setTargetPos(41, 0.24);
      break;

    case 2:
      // Then move back to 20° as fast as possible
      servoTrajectoryAR.setTargetPos(88, 0.26);
      break;

    case 3:
      // Next move to 180°, but over the course of 5 seconds
      servoTrajectoryAR.setTargetPos(88, 0.08);
      break;

    case 4: 
      servoTrajectoryAR.setTargetPos(69, 0.19);
      break;
    
    case 5: 
      servoTrajectoryAR.setTargetPos(88, 0.23);
      break;
    
    case 6:
      moveNumberAnkleR = -1;
      break;
  }
  
	moveNumberHipL++; 
  moveNumberKneeL++;
  moveNumberAnkleL++;
  moveNumberHipR++;
  moveNumberKneeR++;
  moveNumberAnkleR++;

}

void loop() {
  // put your main code here, to run repeatedly:

  // Update the servo position at regular intervals
	if (updateTimer <= millis()) {
		if (updateTimer <= millis() - UPDATE_TIME) updateTimer = millis() + UPDATE_TIME;
		else updateTimer += UPDATE_TIME;

		// Update the controller
		float currentAngleHL = servoTrajectoryHL.update();
    float currentAngleKL = servoTrajectoryKL.update();
    float currentAngleAL = servoTrajectoryAL.update();
    float currentAngleHR = servoTrajectoryHR.update();
    float currentAngleKR = servoTrajectoryKR.update();
    float currentAngleAR = servoTrajectoryAR.update();

		// Set the new servo position; the function only takes integer numbers
		hipL.write(round(currentAngleHL));
    kneeL.write(round(currentAngleKL));
    ankleL.write(round(currentAngleAL));
    hipR.write(round(currentAngleHR));
    kneeR.write(round(currentAngleKR));
    ankleR.write(round(currentAngleAR));

		// Output the target position, along with the current position and velocity
		Serial.print("Target: ");
		Serial.print(servoTrajectoryAL.getTarget());
		Serial.print(", Angle:  ");
		Serial.print(servoTrajectoryAL.getPos());
		Serial.print(", Velocity: ");
		Serial.println(servoTrajectoryAL.getVel());

		// Only once the servo has reached the desired position, complete the next move
		if (servoTrajectoryHL.ready() && servoTrajectoryKL.ready() && servoTrajectoryAL.ready()) {
			nextMove();
		}
	}
}
