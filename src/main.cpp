#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "devices.h"
#include "auton.h"

/**
 * A callback function for LLEMU's center button.
 *git
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
	chassis.calibrate();
	pros::Task screenTask([&]()
                          {
	while (true) {
		// print robot location to the brain screen 
		pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
		pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
		pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
		// log position telemetry
		// delay to save resources
		pros::delay(50);
	} });

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */	
void autonomous() {
	// ringside_red();
	// mogorush_red(); //nextws
	// ringside_blue();
	mogorush_blue();
	// prog_skills3();
	
}

/**
 * Runs the opera`tor control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	while (true) {
        // get left y and right x positions
        int leftY = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // move the robot
        chassis.arcade(leftY, rightX);

		// intake
		bool intake = master.get_digital(pros::E_CONTROLLER_DIGITAL_L1); 
		bool intake_rev = master.get_digital(pros::E_CONTROLLER_DIGITAL_L2); 

		if (intake){		
			intake_motors.move(127);
		} else if (intake_rev){
		    intake_motors.move(-127);
		} else {
			intake_motors.move(0);
		}
      
	  	// toggle clamp
		if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
			clamp_state = !clamp_state;
			clamp_sol.set_value(clamp_state);
		}

        // delay to save resources
        pros::delay(5);
    }
	

}