#include "devices.h"
#include "main.h"


void prog_skills1() {
    chassis.moveTo(0, 0, 5000);
    chassis.moveTo(16.506, 18.054, 5000);
    chassis.moveTo(42.039, 20.891, 5000);
    chassis.moveTo(56.998, 9.027, 5000);
    chassis.moveTo(64.478, 1.032, 5000);
    chassis.moveTo(-17.796, 18.57, 5000);
    chassis.moveTo(-44.361, 20.891, 5000);
    chassis.moveTo(-54.419, 13.153, 5000);
    chassis.moveTo(-64.735, 0, 5000);
    
}

void prog_skills2() {
    chassis.moveToPose(0, 0, 5000, 3000);
	chassis.moveToPose(22.136, 15.304, 5000, 3000);
	chassis.moveToPose(23.451, 40.719, 5000, 3000);
	chassis.moveToPose(58.209, 63.947, 5000, 3000);
	chassis.moveToPose(46.184, 40.309, 5000, 3000);
	chassis.moveToPose(57.935, 17.08, 5000, 3000);
	chassis.moveToPose(45.364, 17.08, 5000, 3000);
	chassis.moveToPose(46.458, 5.329, 5000, 3000);
	chassis.moveToPose(64.767, -0.956, 5000, 3000);


	chassis.setPose(-64, 0, 90);
	chassis.moveToPose(0, 0, 5000, 3000);
	chassis.moveToPose(-16.455, 3.849, 5000, 3000);
	chassis.moveToPose(-31.041, 7.103, 5000, 3000);
	chassis.moveToPose(-58.098, -12.572, 5000, 3000);
	chassis.moveToPose(-61.229, -20.511, 5000, 3000);
	chassis.moveToPose(-39.142, -12.751, 5000, 3000);
	chassis.moveToPose(5.392, -33.596, 5000, 3000);
	chassis.moveToPose(-11.789, -35.311, 5000, 3000);
	chassis.moveToPose(-24.37, -37.005, 5000, 3000);
	chassis.moveToPose(-3.496, -42.897, 5000, 3000);
	chassis.moveToPose(-1.135, -48.814, 5000, 3000);
}

prog_skills3() {
    chassis.moveTo(0, 0, 5000);
    chassis.moveTo(15.99, 18.054, 5000);
    clamp_sol.set_value(true);
    pros::delay(500);
    chassis.moveTo(64.993, 0, 5000);
    clamp_sol.set_value(false);
    pros::delay(500);
    chassis.moveTo(-18.312, 18.827, 5000);
    clamp_sol.set_value(true);
    pros::delay(500);
    chassis.moveTo(-63.704, 0.774, 5000);
    clamp_sol.set_value(false);
    pros::delay(500);
    
}