#include "devices.h"
#include "main.h"


void prog_skills1() {
    // chassis.moveTo(0, 0, 5000);
    // chassis.moveTo(16.506, 18.054, 5000);
    // chassis.moveTo(42.039, 20.891, 5000);
    // chassis.moveTo(56.998, 9.027, 5000);
    // chassis.moveTo(64.478, 1.032, 5000);
    // chassis.moveTo(-17.796, 18.57, 5000);
    // chassis.moveTo(-44.361, 20.891, 5000);
    // chassis.moveTo(-54.419, 13.153, 5000);
    // chassis.moveTo(-64.735, 0, 5000);
    
}

void prog_skills2() {
    // chassis.moveToPose(0, 0, 5000, 3000);
	// chassis.moveToPose(22.136, 15.304, 5000, 3000);
	// chassis.moveToPose(23.451, 40.719, 5000, 3000);
	// chassis.moveToPose(58.209, 63.947, 5000, 3000);
	// chassis.moveToPose(46.184, 40.309, 5000, 3000);
	// chassis.moveToPose(57.935, 17.08, 5000, 3000);
	// chassis.moveToPose(45.364, 17.08, 5000, 3000);
	// chassis.moveToPose(46.458, 5.329, 5000, 3000);
	// chassis.moveToPose(64.767, -0.956, 5000, 3000);


	// chassis.setPose(-64, 0, 90);
	// chassis.moveToPose(0, 0, 5000, 3000);
	// chassis.moveToPose(-16.455, 3.849, 5000, 3000);
	// chassis.moveToPose(-31.041, 7.103, 5000, 3000);
	// chassis.moveToPose(-58.098, -12.572, 5000, 3000);
	// chassis.moveToPose(-61.229, -20.511, 5000, 3000);
	// chassis.moveToPose(-39.142, -12.751, 5000, 3000);
	// chassis.moveToPose(5.392, -33.596, 5000, 3000);
	// chassis.moveToPose(-11.789, -35.311, 5000, 3000);
	// chassis.moveToPose(-24.37, -37.005, 5000, 3000);
	// chassis.moveToPose(-3.496, -42.897, 5000, 3000);
	// chassis.moveToPose(-1.135, -48.814, 5000, 3000);
}

void prog_skills3() {
    // chassis.setPose(-65,0,90);
    // intake_motors.move(127);
    // pros::delay(900);
    // intake_motors.move(0);
    // chassis.moveToPose(-49, 0, 90, 1000);
    // chassis.turnToPoint(-46, -20, 1000, {.forwards=false});
	// chassis.moveToPoint(-46, -20, 1000, {.forwards=false}); // clamp right mogo first
	// chassis.waitUntilDone();
    // clamp_sol.set_value(true);
    // pros::delay(500);
    // chassis.moveToPose(-66, -63, 40, 2000, {.forwards=false, .earlyExitRange=1.5}); // go to corner 1
    // chassis.waitUntilDone();
    // clamp_sol.set_value(false);
    // pros::delay(500);
	// chassis.moveToPose(-46, 0, 0, 2500); // move back to center
    // chassis.turnToPoint(-46, 20, 1000, {.forwards=false});
    // chassis.moveToPose(-46, 20, 180, 2000, {.forwards=false});
    // chassis.waitUntilDone();
    // clamp_sol.set_value(true);
    // pros::delay(300);
    // chassis.moveToPose(-66, 63, 150, 1500, {.forwards=false}); // go to corner 2
    // chassis.waitUntilDone();
    // clamp_sol.set_value(false);
    // pros::delay(500);
    // chassis.moveToPose(34, 31, 130, 3000); // go to other side of field
    // chassis.moveToPose(59, 6, 142, 1000);
    // chassis.turnToPoint(59, 20, 1000, {.forwards=false}); 
    // chassis.moveToPoint(65, 63, 2000, {.forwards=false});
    // chassis.waitUntilDone();
    // chassis.moveToPose(59,11,0,2000, {.forwards=false});
    // chassis.moveToPose(59,-30,350,2000,{.forwards=false});
    // chassis.moveToPose(66,-63,320,2000,{.forwards=false});
    // chassis.waitUntilDone();
    chassis.setPose(-65,0,90);
    intake_motors.move(127);
    pros::delay(900);
    intake_motors.move(0);
    chassis.moveToPose(-47.5, 2, 0, 2000);
    chassis.moveToPose(-47, -24, 0, 2000, {.forwards=false});
    chassis.waitUntilDone();
    clamp_sol.set_value(true);
    // chassis.moveToPose(-58.2, -32.7, 208, 2000);
    // intake_motors.move(-127);
    // chassis.moveToPose(-57.5, -50, 180, 2000);
    // chassis.moveToPose(-57.8, -58, 40, 2000);
    // chassis.moveToPose(-65.5, -65.5, 40, 2000);
    // clamp_sol.set_value(false);
    // intake_motors.move(0);
    // chassis.moveToPose(-46.3, 5.43, 180, 2000);
    // chassis.moveToPose(-46.6, 23.9, 180, 2000);
    // clamp_sol.set_value(true);
    // chassis.moveToPose(-59, 36.3, 0, 2000);
    // intake_motors.move(127);
    // chassis.moveToPose(-59, 48, 0, 2000);
    // chassis.moveToPose(-60, 57, 140, 2000);
    // chassis.moveToPose(-66, 66, 140, 2000);
    // clamp_sol.set_value(false);
    // intake_motors.move(0);
    // chassis.moveToPose(25, 35, 140, 2000);
    // chassis.moveToPose(59, 3, 180, 2000);
    // chassis.moveToPose(59, 24, 180, 2000);
    // clamp_sol.set_value(true);
    // chassis.moveToPose(60, 59, 220, 2000);
    // chassis.moveToPose(65.5, 65.5, 220, 2000);
    // clamp_sol.set_value(false);
    // chassis.moveToPose(59,  -25, 0, 2000);
    // clamp_sol.set_value(true);
    // chassis.moveToPose(56, -57, 320, 2000);
    // chassis.moveToPose(65, -65, 320, 2000);
    // clamp_sol.set_value(false);
    // chassis.moveToPose(36, -24, 270, 2000);
    // intake_motors.move(127);
    // pros::delay(500);
    // intake_motors.move(0);
    // chassis.moveToPose(19, -24, 270, 2000);
    // intake_motors.move(0);
    // chassis.moveToPose(65, 0, 270, 2000);
    // intake_motors.move(127);
    // pros::delay(1000);
    // intake_motors.move(0);
}   