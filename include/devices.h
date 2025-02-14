#pragma once
// #include "main.h"
#include "lemlib/api.hpp"

/*
left front - 8
left middle - 19
left back - 18


right front - 6
right middle - 7
right back - 20

wall stake mech - 15

intake - 17, 10
*/

#define CLAMP_PORT 'A'
#define IMU_PORT 5
#define VERT_TRACKING_WHEEL 9 // arbitrary port number
#define HOR_TRACKING_WHEEL 16 // arbitrary port number

inline pros::Controller master(pros::E_CONTROLLER_MASTER);

inline bool clamp_state = false;

inline pros::MotorGroup left_drive({ -18, -19, -8 }, pros::v5::MotorGears::blue);
inline pros::MotorGroup right_drive({ 20, 7, 6 }, pros::v5::MotorGears::blue);

inline lemlib::ExpoDriveCurve steer_curve(3, // joystick deadband out of 127
                                  10, // minimum output where drivetrain will move out of 127
                                  1.02 // expo curve gain
);


inline lemlib::ExpoDriveCurve t_curve(0, // joystick deadband out of 127
                                     10, // minimum output where drivetrain will move out of 127
                                     1 // expo curve gain
);

inline lemlib::Drivetrain drivetrain(&left_drive, // left motor group
                              &right_drive, // right motor group`
                              12.5, // 12.5 inch track width 
                              lemlib::Omniwheel::NEW_325, // 3.25" omnis 
                              450, // 450 rpm drivetrain
                              2 // horizontal drift
);


inline pros::MotorGroup intake_motors({17, -10}); 
//inline Motor intake_motor(INTAKE_PORT);M
inline pros::ADIDigitalOut clamp_sol(CLAMP_PORT, clamp_state);
inline pros::Imu imu(IMU_PORT);

//UNCOMMENT THIS:
inline pros::Rotation vert_tracking(VERT_TRACKING_WHEEL);
inline pros::Rotation hor_tracking(HOR_TRACKING_WHEEL);

//uncomment this:
inline lemlib::TrackingWheel vertical_tracking_wheel(&vert_tracking, lemlib::Omniwheel::NEW_275_HALF, 0.5); // arbitrary offset number!!!!!!!!!!!
inline lemlib::TrackingWheel horizontal_tracking_wheel(&hor_tracking, lemlib::Omniwheel::NEW_275_HALF, -1.25); // arbitrary offset number!!!!!!!!

// odom sensors


inline lemlib::OdomSensors sensors(&vertical_tracking_wheel,
                             nullptr,
                             &horizontal_tracking_wheel,
                             nullptr,
                             &imu
 );

// lateral PID controller
// RMB TO RESTORE OG VALUES
inline lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                               0, // integral gain (kI)
                                               3, // derivative gain (kD)
                                               0, // anti windup
                                               0, // small error range, in inches
                                               0, // small error range timeout, in milliseconds
                                               0, // large error range, in inches
                                               0, // large error range timeout, in milliseconds
                                               0 // maximum acceleration (slew)
 );


// angular PID controller
// RMB TO RESTORE OG VALUES
inline lemlib::ControllerSettings angular_controller(2.5, // proportional gain (kP)
                                               0, // integral gain (kI)
                                               12.6, // derivative gain (kD)
                                               0, // anti windup
                                               0, // small error range, in degrees
                                               0, // small error range timeout, in milliseconds
                                               0, // large error range, in degrees
                                               0, // large error range timeout, in milliseconds
                                               0 // maximum acceleration (slew)
);


inline lemlib::Chassis chassis(drivetrain,
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors,
                        &t_curve,
                        &steer_curve
);

