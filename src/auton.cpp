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
    chassis.setPose(-65,0,90);
    intake_motors.move(127);
    pros::delay(900);
    intake_motors.move(0);
    chassis.moveToPose(-49, 0, 90, 1000);
    chassis.turnToPoint(-50, -20, 1000, {.forwards=false});
	chassis.moveToPoint(-50, -20, 1000, {.forwards=false}); // clamp right mogo first
	chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(500);
    chassis.moveToPose(-67, -63, 30, 2000, {.forwards=false, .earlyExitRange=1.5}); // go to corner 1
    chassis.waitUntilDone();
    clamp_sol.set_value(false);
    pros::delay(500);
	chassis.moveToPose(-46, 0, 0, 2500); // move back to center
    chassis.turnToPoint(-46, 20, 1000, {.forwards=false});
    chassis.moveToPose(-46, 20, 180, 2000, {.forwards=false});
    chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(300);
    chassis.moveToPose(-64, 63, 150, 1500, {.forwards=false}); // go to corner 2
    chassis.waitUntilDone();
    clamp_sol.set_value(false);
    pros::delay(500);
    chassis.moveToPose(32, 30, 120, 3000); // go to other side of field
    chassis.moveToPoint(58.5, 3, 1000);
    chassis.turnToPoint(58.5, 20, 1000, {.forwards=false}); 
    chassis.moveToPoint(64, 63, 2000, {.forwards=false});
    
}   