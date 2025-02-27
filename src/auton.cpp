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
    // /
    
}

void prog_skills2() {
    chassis.setPose(-65,0,90);
    intake_motors.move(127);
    pros::delay(900);
    chassis.moveToPose(-46, 0, 90, 1000);
    chassis.turnToPoint(-53, -17, 1000, {.forwards=false});
	chassis.moveToPoint(-53, -17, 2000, {.forwards=false, .maxSpeed = 50}); // clamp right mogo first
	chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(500);
    chassis.turnToPoint(-54,-50.5,1000);
    chassis.moveToPoint(-54, -57, 5000, {.maxSpeed=50}); 
    chassis.waitUntilDone();
    pros::delay(1000);
    chassis.turnToPoint(-70,-68, 1000, {.forwards=false});
    chassis.waitUntilDone();
    clamp_sol.set_value(false);
    chassis.moveToPoint(-65, -60, 1000,{.forwards=false}); 
    chassis.waitUntilDone();
    intake_motors.move(0);
    pros::delay(500);
    chassis.moveToPose(-48, 0, 0, 1000);
    chassis.turnToPoint(-48,5,1000, {.forwards=false});
    chassis.moveToPoint(-50,14, 4000, {.forwards=false, .maxSpeed = 50});
    chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(500);
    chassis.turnToPoint(-49, 19, 1000);
    intake_motors.move(127);
    chassis.moveToPoint(-49, 35, 4000, {.maxSpeed = 50});
    chassis.waitUntilDone();
    chassis.moveToPoint(-49, 45, 4000, {.maxSpeed = 50});
    chassis.waitUntilDone();
    chassis.turnToPoint(-70,50, 1000, {.forwards=false});
    chassis.waitUntilDone();
    clamp_sol.set_value(false);
    intake_motors.move(0);
    chassis.moveToPoint(-58,60, 1000, {.forwards=false});
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.moveToPose(0, 38, 270, 4000); // move to other side of the field
    chassis.moveToPose(45, 16, 320, 4000, {.forwards=false}); 
    chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(500); 
    chassis.turnToPoint(-48,5,1000, {.forwards=false});
    chassis.moveToPose(67, 60, 0, 3000,{.forwards=false});
    //chassis.moveToPose(34, 7, 130, 3000); // go to other side of field
    // chassis.moveToPoint(55, -19, 3000, {.maxSpeed = 90});
    // chassis.waitUntilDone();
    // chassis.setPose(0,0,130);
    // chassis.turnToPoint(0,-70,1000,{.forwards=false});
    // chassis.moveToPoint(0,-70,9000, {.forwards=false});
    // chassis.waitUntilDone();
    // chassis.moveToPoint(0,70,8000);

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

void mogorush_red() {
    chassis.setPose(-59, -22, 270);
    chassis.moveToPoint(-23,-23,2000, {.forwards=false,.maxSpeed = 40});
    chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(500);
    chassis.turnToPoint(-23,-45,1000);
    intake_motors.move(127);
    chassis.moveToPoint(-23,-50,3000, {.maxSpeed=90});
    chassis.waitUntilDone();
    chassis.turnToPoint(-24,0, 3000);
    chassis.moveToPoint(-24,-2,3000);
}

void mogorush_blue(){
    chassis.setPose(59,-22, 90);
    chassis.moveToPoint(23,-23, 2000, {.forwards=false,.maxSpeed=40});
    chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(500);
    chassis.turnToPoint(24.5,-45,1000);
    intake_motors.move(127);
    chassis.moveToPoint(24.5,-50,3000, {.maxSpeed=90});
    chassis.waitUntilDone();
    chassis.turnToPoint(24,0, 3000);
    chassis.moveToPoint(24,-2,3000);
}

void ringside_red() {
    chassis.setPose(-53,10,0);
    chassis.moveToPoint(-53,0,1000, {.forwards=false});
    chassis.turnToPoint(-64,0,1000, {.forwards=false});
    chassis.moveToPoint(-64,0,1000,{.forwards=false});
    chassis.waitUntilDone();
    intake_motors.move(127);
    pros::delay(2000);
    chassis.moveToPoint(-57, 0, 1000);
    chassis.turnToPoint(-23,23,1000, {.forwards=false});
    chassis.moveToPoint(-23,23, 4000, {.maxSpeed = 40, .forwards=false});
    chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(500);
    chassis.turnToPoint(-23,52,1000);
    chassis.moveToPoint(-23,52,3000,{.maxSpeed = 90});
    chassis.turnToPoint(-24,2,1000);
    chassis.moveToPoint(-24,2,2000);
}

void ringside_blue() {
    chassis.setPose(53,10,0);
    chassis.moveToPoint(53,0,1000, {.forwards=false});
    chassis.turnToPoint(64,0,1000, {.forwards=false});
    chassis.moveToPoint(64,0,1000,{.forwards=false});
    chassis.waitUntilDone();
    intake_motors.move(127);
    pros::delay(2000);
    chassis.moveToPoint(57, 0, 1000);
    chassis.turnToPoint(23,23,1000, {.forwards=false});
    chassis.moveToPoint(23,23, 4000, {.maxSpeed = 40, .forwards=false});
    chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(500);
    chassis.turnToPoint(23,52,1000);
    chassis.moveToPoint(23,52,3000,{.maxSpeed = 90});
    chassis.turnToPoint(24,2,1000);
    chassis.moveToPoint(24,2,2000);
}

