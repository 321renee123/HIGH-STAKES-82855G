#include "devices.h"
#include "main.h"

void prog_skills1()
{
    chassis.setPose(-65, 0, 90);
    intake_motors.move(127);
    pros::delay(900);
    intake_motors.move(0);
    chassis.moveToPose(-49, 0, 90, 1000);
    chassis.turnToPoint(-46, -20, 1000, {.forwards = false});
    chassis.moveToPoint(-46, -20, 1000, {.forwards = false}); // clamp right mogo first
    chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(500);
    chassis.moveToPose(-66, -63, 40, 2000, {.forwards = false, .earlyExitRange = 1.5}); // go to corner 1
    chassis.waitUntilDone();
    clamp_sol.set_value(false);
    pros::delay(500);
    chassis.moveToPose(-45.5, 0, 0, 2500); // move back to center
    chassis.turnToPoint(-45.5, 20, 1000, {.forwards = false});
    chassis.moveToPose(-45.5, 20, 180, 2000, {.forwards = false});
    chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(300);
    chassis.moveToPose(-66, 63, 150, 1500, {.forwards = false}); // go to corner 2
    chassis.waitUntilDone();
    clamp_sol.set_value(false);
    pros::delay(500);
    // /
}

void prog_skills2()
{
    chassis.setPose(-65, 0, 90);
    intake_motors.move(127);
    pros::delay(900);
    chassis.moveToPose(-46, 0, 90, 1000);
    chassis.turnToPoint(-53, -17, 1000, {.forwards = false});
    chassis.moveToPoint(-53, -17, 2000, {.forwards = false, .maxSpeed = 50}); // clamp right mogo first
    chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(500);
    chassis.turnToPoint(-54, -50.5, 1000);
    chassis.moveToPoint(-54, -57, 3000, {.maxSpeed = 50});
    chassis.waitUntilDone();
    pros::delay(1000);
    chassis.turnToPoint(-70, -68, 1000, {.forwards = false});
    chassis.waitUntilDone();
    clamp_sol.set_value(false);
    chassis.moveToPoint(-65, -60, 1000, {.forwards = false});
    chassis.waitUntilDone();
    intake_motors.move(0);
    pros::delay(500);
    chassis.moveToPose(-48, 0, 0, 1000);
    chassis.turnToPoint(-50, 5, 1000, {.forwards = false});
    chassis.moveToPoint(-50, 14, 4000, {.forwards = false, .maxSpeed = 50}); // go to second mogo
    chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(500);
    chassis.turnToPoint(-49, 19, 1000);
    intake_motors.move(127);
    chassis.moveToPoint(-49, 35, 4000, {.maxSpeed = 50}); // grab first ring
    chassis.waitUntilDone();
    chassis.moveToPoint(-49, 47, 4000, {.maxSpeed = 50}); // grab second ring
    chassis.waitUntilDone();
    chassis.turnToPoint(-70, 50, 1000, {.forwards = false});
    chassis.waitUntilDone();
    clamp_sol.set_value(false);
    intake_motors.move(0);
    chassis.moveToPoint(-58, 60, 1000, {.forwards = false}); // put into the corner
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.turnToPoint(0, 38, 1000);
    chassis.moveToPoint(0, 38, 4000); // move to other side of the field
    chassis.turnToPoint(52, 10, 1000, {.forwards = false});
    chassis.moveToPoint(52, 10, 4000, {.forwards = false});
    chassis.waitUntilDone();
    pros::delay(500);
    chassis.turnToPoint(65, 60, 1000, {.forwards = false});
    chassis.moveToPoint(65, 60, 3000, {.forwards = false}); // place mogo in corner
    chassis.turnToPoint(55, 55, 1000, {.forwards = false});
    chassis.moveToPoint(55, 55, 3000);
    chassis.turnToPoint(60, -24, 1000, {.forwards = false});
    chassis.moveToPoint(60, -24, 3000, {.forwards = false});
    chassis.turnToPoint(67, -66, 1000, {.forwards = false});
    chassis.moveToPoint(67, -66, 3000, {.forwards = false});
    chassis.turnToPoint(71, -50, 1000, {.forwards = false});
    chassis.moveToPoint(73, -66, 3000, {.forwards = false});
    // chassis.moveToPose(34, 7, 130, 3000); // go to other side of field
    //  chassis.moveToPoint(55, -19, 3000, {.maxSpeed = 90});
    //  chassis.waitUntilDone();
    //  chassis.setPose(0,0,130);
    //  chassis.turnToPoint(0,-70,1000,{.forwards=false});
    //  chassis.moveToPoint(0,-70,9000, {.forwards=false});
    //  chassis.waitUntilDone();
    //  chassis.moveToPoint(0,70,8000);

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

void prog_skills3()
{
    chassis.setPose(-65, 0, 90);
    intake_motors.move(127);
    pros::delay(1500);
    chassis.moveToPoint(-47, 0, 1000);
    chassis.turnToPoint(-50, -19, 500, {.forwards = false}); // clamp mogo
    chassis.moveToPoint(-50, -19, 800, {.forwards = false});
    chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(500);
    chassis.turnToPoint(-20, -18, 700); // get first ring
    chassis.moveToPoint(-20, -18, 1000);
    intake_motors.move(127);
    chassis.turnToPoint(3, -60, 700); // get second ring
    chassis.moveToPoint(3, -60, 1000);
    chassis.turnToPoint(-22, -42, 700); // position to get all three rings
    chassis.moveToPoint(-22, -42, 1000);
    chassis.turnToPoint(-68, -42.5, 500); // intake all three rings
    chassis.moveToPoint(-68, -42.5, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-68, -41, 1000);
    chassis.moveToPoint(-52, -41, 600, {.forwards = false}); // move to the point above the last ring
    chassis.turnToPoint(-52, -63, 700);                      // intake last ring
    chassis.moveToPoint(-50, -63, 1000);
    chassis.turnToPoint(-65, -71, 700, {.forwards = false}); // put mogo into corner
    chassis.waitUntilDone();
    clamp_sol.set_value(false);
    chassis.moveToPoint(-65, -71, 1000, {.forwards = false});
    chassis.turnToPoint(-49, -46, 700); // move out of corner
    chassis.moveToPoint(-49, -46, 700);
    chassis.waitUntilDone();
    // SECOND MOGO
    chassis.turnToPoint(-49, 11, 700, {.forwards = false}); // move to second mogo
    chassis.moveToPoint(-49, 5, 1000, {.forwards = false});
    chassis.waitUntilDone();
    chassis.moveToPoint(-49, 11, 1000, {.forwards = false, .maxSpeed = 50});
    chassis.waitUntilDone();
    pros::delay(200);
    clamp_sol.set_value(true);
    pros::delay(1000);
    chassis.turnToPoint(-20, 14, 700); // get first ring
    chassis.moveToPoint(-20, 14, 1000);
    intake_motors.move(127);
    chassis.turnToPoint(-1, 60, 700); // get second ring
    chassis.moveToPoint(-1, 60, 1000);
    chassis.turnToPoint(-22, 38, 700); // position to get all three rings
    chassis.moveToPoint(-22, 38, 1000);
    chassis.turnToPoint(-70, 38, 500); // intake all three rings
    chassis.moveToPoint(-70, 38, 1500);
    chassis.waitUntilDone();
    chassis.moveToPoint(-77, 38, 1000);
    chassis.moveToPoint(-48, 38, 600, {.forwards = false}); // move to the point above the last ring
    chassis.turnToPoint(-48, 63, 700);                      // intake last ring
    chassis.moveToPoint(-48, 63, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-52, 55, 600, {.forwards = false}); // move backwards
    chassis.turnToPoint(-70, 70, 700, {.forwards = false}); // put mogo into corner
    chassis.waitUntilDone();
    clamp_sol.set_value(false);
    chassis.moveToPoint(-70, 72, 1000, {.forwards = false});
    // chassis.waitUntilDone();
    // pros::delay(500);
    // chassis.turnToPoint(0,38,500);
    // chassis.moveToPoint(0, 38, 1000); // move to other side of the field
    // chassis.turnToPoint(52, 10, 1000, {.forwards=false});
    // chassis.moveToPoint(52, 10, 4000, {.forwards=false});
    // chassis.waitUntilDone();
    // pros::delay(500);
    // chassis.turnToPoint(65,60,1000, {.forwards=false});
    // chassis.moveToPoint(65, 60,3000,{.forwards=false}); //place mogo in corner
    // chassis.turnToPoint(55,55, 1000, {.forwards=false});
    // chassis.moveToPoint(55, 55, 3000);
    // chassis.turnToPoint(60,-24, 1000, {.forwards=false});
    // chassis.moveToPoint(60, -24, 1000, {.forwards=false});
    // chassis.turnToPoint(67,-66, 1000, {.forwards=false});
    // chassis.moveToPoint(67, -66, 3000, {.forwards=false});
    // chassis.turnToPoint(71,-50, 1000, {.forwards=false});
    // chassis.moveToPoint(73, -66, 1000, {.forwards=false});
}

void mogorush_red()
{
    chassis.setPose(-59, -22, 270);
    chassis.moveToPoint(-23, -23, 2000, {.forwards = false, .maxSpeed = 40});
    chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(500);
    chassis.turnToPoint(-23, -45, 1000);
    intake_motors.move(127);
    chassis.moveToPoint(-23, -50, 3000, {.maxSpeed = 90});
    chassis.waitUntilDone();
    chassis.turnToPoint(-24, 0, 3000);
    chassis.moveToPoint(-24, -2, 3000);
    chassis.waitUntilDone();
    intake_motors.move(0);
}

void mogorush_blue()
{
    chassis.setPose(59, -22, 90);
    chassis.moveToPoint(23, -23, 2000, {.forwards = false, .maxSpeed = 40});
    chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(500);
    chassis.turnToPoint(24.5, -45, 1000);
    intake_motors.move(127);
    chassis.moveToPoint(24.5, -50, 3000, {.maxSpeed = 90});
    chassis.waitUntilDone();
    chassis.turnToPoint(24, 0, 3000);
    chassis.moveToPoint(24, -2, 3000);
    chassis.waitUntilDone();
    intake_motors.move(0);
}

void ringside_red()
{
    chassis.setPose(-53, 24, 0);
    chassis.moveToPoint(-53, 1.3, 1000, {.forwards = false});
    chassis.turnToPoint(-60.5, 1.3, 1000, {.forwards = false});
    chassis.moveToPoint(-59, 1.3, 1000, {.forwards = false});
    chassis.waitUntilDone();
    intake_motors.move(127);
    pros::delay(1000);
    chassis.moveToPoint(-40, 1.7, 1000);
    chassis.turnToPoint(-26, 23, 1000, {.forwards = false});
    chassis.moveToPoint(-26, 23, 3500, {.forwards = false, .maxSpeed = 60});
    chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(500);
    chassis.turnToPoint(-28, 52, 1000);
    chassis.moveToPoint(-28, 51, 3000, {.maxSpeed = 100}); // grabbing ring to the side
    chassis.waitUntilDone();
    chassis.turnToPoint(-13, 45, 1000);
    chassis.moveToPoint(-13, 45, 2000, {.maxSpeed = 100}); // grabbing ring on the line
    chassis.waitUntilDone();
    chassis.turnToPoint(-25, 2, 1000);
    chassis.moveToPoint(-21, 9, 2000);
    chassis.moveToPoint(-25, 2, 2000, {.maxSpeed = 50});
}

void ringside_blue()
{
    chassis.setPose(53, 24, 0);
    chassis.moveToPoint(53, 1.3, 1000, {.forwards = false});
    chassis.turnToPoint(60.5, 1.3, 1000, {.forwards = false});
    chassis.moveToPoint(60.5, 1.3, 1000, {.forwards = false});
    chassis.waitUntilDone();
    intake_motors.move(127);
    pros::delay(1000);
    chassis.moveToPoint(40, 1.7, 1000);
    chassis.turnToPoint(26, 23, 1000, {.forwards = false});
    chassis.moveToPoint(26, 23, 3500, {.forwards = false, .maxSpeed = 60});
    chassis.waitUntilDone();
    clamp_sol.set_value(true);
    pros::delay(500);
    chassis.turnToPoint(28, 52, 1000);
    chassis.moveToPoint(28, 51, 3000, {.maxSpeed = 100}); // grabbing ring to the side
    chassis.waitUntilDone();
    chassis.turnToPoint(13, 45, 1000);
    chassis.moveToPoint(12, 45, 2000, {.maxSpeed = 100}); // grabbing ring on the line
    chassis.waitUntilDone();
    chassis.turnToPoint(25, 2, 1000);
    chassis.moveToPoint(25, 2, 2000);
}
