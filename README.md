# Lower Limb Exoskeleton (LLE) Prototype Motion Control
This project aims to perform motion and speed control of a LLE prototype using Arduino and SG90 servo motors. The prototype consists of 2 pairs of 3 servo motors connected to two rods representing hip, knee, and ankle joints. Each servo motor is connected to an Arduino Mega microcontroller board and individually controlled for normal walking motion and speed. A gait cycle consisting of angle trajectories of each joint was used as motion reference. 

## Setup
The compiled files for the project include:
1. main_code.ino: main Arduino script consisting of switch motion cases for each servo
2. trajectory.ino: external library used to control speed
3. ...

