#include "devices.h"
#include "main.h"


void prog_skills1() {
    chassis.setPose(-65,0,90);
    intake_motors.move(127);
    pros::delay(900);
    intake_motors.move(0);
    chassis.moveToPose(-49, 0, 90, 1000);
    chassis.turnToPoint(-46, -20, 1000, {.forwards=false});
	chassis.moveToPoint(-46, -20, 1000, {.forwards=false}); // clamp right mogo first
	chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(500);
    chassis.moveToPose(-66, -63, 40, 2000, {.forwards=false, .earlyExitRange=1.5}); // go to corner 1
    chassis.waitUntilDone();
    clamp_sol.set_value(false);
    pros::delay(500);
	chassis.moveToPose(-45.5, 0, 0, 2500); // move back to center
    chassis.turnToPoint(-45.5, 20, 1000, {.forwards=false});
    chassis.moveToPose(-45.5, 20, 180, 2000, {.forwards=false});
    chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(300);
    chassis.moveToPose(-66, 63, 150, 1500, {.forwards=false}); // go to corner 2
    chassis.waitUntilDone();
    clamp_sol.set_value(false);
    pros::delay(500);
    chassis.moveToPose(34, 31, 130, 3000); // go to other side of field
    chassis.moveToPose(59, 6, 142, 1000);
    chassis.turnToPoint(59, 20, 1000, {.forwards=false}); 
    chassis.moveToPoint(65, 63, 2000, {.forwards=false});
    chassis.waitUntilDone();
    chassis.moveToPose(59,11,0,2000, {.forwards=false});
    chassis.moveToPose(59,-30,350,2000,{.forwards=false});
    chassis.moveToPose(66,-63,320,2000,{.forwards=false});
    chassis.waitUntilDone();
    
}

void prog_skills2() {
    chassis.setPose(-65,0,90);
    intake_motors.move(127);
    pros::delay(900);
    chassis.moveToPose(-46, 0, 90, 1000);
    chassis.turnToPoint(-53, -17, 1000, {.forwards=false});
	chassis.moveToPoint(-53, -15, 2000, {.forwards=false, .maxSpeed = 60}); // clamp right mogo first
	chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(500);
    chassis.turnToPoint(-54,-50.5,1000);
    chassis.moveToPoint(-54, -54.5, 6000); 
    chassis.waitUntilDone();
    pros::delay(1000);
    chassis.turnToPoint(-70,-68, 1000, {.forwards=false});
    chassis.waitUntilDone();
    clamp_sol.set_value(false);
    chassis.moveToPoint(-65, -60, 1000,{.forwards=false}); 
    chassis.waitUntilDone();
    intake_motors.move(0);
    pros::delay(500);
    chassis.moveToPose(-47, 0, 0, 1000);
    chassis.turnToPoint(-44,5,1000, {.forwards=false});
    chassis.moveToPoint(-44,10,1000, {.forwards=false});
    chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(500);
    chassis.turnToPoint(-44, 20, 1000);
    intake_motors.move(110);
    chassis.moveToPoint(-44, 48.5, 4000, {.maxSpeed = 50});
    chassis.waitUntilDone();
    chassis.turnToPoint(-70,50, 1000, {.forwards=false});
    chassis.waitUntilDone();
    clamp_sol.set_value(false);
    chassis.moveToPoint(-58,60,1000, {.forwards=false});
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.moveToPose(34, 5, 130, 3000); // go to other side of field
    chassis.moveToPose(59, -8, 180, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(65,65,1000, {.forwards=false});

    // chassis.moveToPose(59, 3, 180, 2000);
    // chassis.moveToPose(59, 24, 180, 2000, {.forwards=false});
    // clamp_sol.set_value(true);
    // chassis.moveToPose(60, 59, 220, 2000, {.forwards=false});
    // chassis.moveToPose(65.5, 65.5, 220, 2000, {.forwards=false});
    // clamp_sol.set_value(false);
    // chassis.moveToPose(59,0,0,2000);
    // chassis.moveToPose(59,-25, 0, 2000, {.forwards=false});
    // clamp_sol.set_value(true);
    // chassis.moveToPose(56, -57, 320, 2000);
    // chassis.moveToPose(65, -65, 320, 2000 {.forwards=false});
    // clamp_sol.set_value(false);
    // chassis.moveToPose(36, -24, 270, 2000);
    // intake_motors.move(127);
    // pros::delay(500);
    // chassis.moveToPose(19, -24, 270, 2000);
    // chassis.waitUntilDone();
    // chassis.moveToPose(57, -9, 250, 2000, {.forwards=false});
    // intake_motors.move(0);
    // chassis.moveToPose(65, 0, 270, 2000, {.forwards=false});
    // intake_motors.move(127);
    // pros::delay(1000);
    // intake_motors.move(0);
}

void prog_skills3() {

}   