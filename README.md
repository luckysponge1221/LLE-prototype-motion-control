# Lower Limb Exoskeleton (LLE) Prototype Motion Control
This project aims to perform motion and speed control of a LLE prototype using Arduino and SG90 servo motors. The prototype consists of 2 pairs of 3 servo motors connected to two rods representing hip, knee, and ankle joints. Each servo motor is connected to an Arduino Mega microcontroller board and individually controlled for normal walking motion and speed. A gait cycle consisting of angle trajectories of each joint was used as motion reference. From the gait cycle, coordinates of percentage of gait and angle were obtained to then be used as turning points of speed control. 

## Setup
The compiled files for the project include:
1. main_code.ino: main Arduino script consisting of switch motion cases for each servo
2. trajectory.h: external library used to control speed when given inputs target angle and time
3. motion_trajectory_reference.ino: angle trajectory equations in code 

