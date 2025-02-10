#pragma once
#include "main.h"
#include "lemlib/api.hpp"

/*
left front - 14
left middle - 16
left back - 8


right front - 18
right middle - 17
right back -12

wall stake mech - 15

intake - 20
*/

//#define INTAKE_PORT 13
//#define INTAKE1_PORT 2
#define CLAMP_PORT 'A'
#define WALL_STAKE_MECH_PORT 14
#define IMU_PORT 1 
#define VERT_TRACKING_WHEEL 19 // arbitrary port number
#define HOR_TRACKING_WHEEL null // arbitrary port number

inline pros::Controller master(pros::E_CONTROLLER_MASTER);

inline bool clamp_state = false;

inline pros::MotorGroup left_drive({ -10, -9, -17 }, pros::v5::MotorGears::blue, pros::v5::MotorUnits::rotations);
inline pros::MotorGroup right_drive({ 16, 18, 20 }, pros::v5::MotorGears::blue, pros::v5::MotorUnits::rotations);

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
                              11.6, // 11.6 inch track width 
                              lemlib::Omniwheel::NEW_325, // 3.25" omnis 
                              450, // 450 rpm drivetrain
                              2 // horizontal drift
);


inline pros::MotorGroup intake_motors({13, 12}); 
//inline Motor intake_motor(INTAKE_PORT);
inline Motor wall_stake_mech (WALL_STAKE_MECH_PORT);
inline ADIDigitalOut clamp_sol(CLAMP_PORT, clamp_state);
inline Imu imu(IMU_PORT);

//UNCOMMENT THIS:
inline Rotation vert_tracking(VERT_TRACKING_WHEEL);
inline Rotation hor_tracking(HOR_TRACKING_WHEEL);

//uncomment this:
inline lemlib::TrackingWheel vertical_tracking_wheel(&vert_tracking, lemlib::Omniwheel::NEW_275_HALF, -1); // arbitrary offset number!!!!!!!!!!!
inline lemlib::TrackingWheel horizontal_tracking_wheel(&hor_tracking, lemlib::Omniwheel::NEW_275_HALF, -1); // arbitrary offset number!!!!!!!!

// odom sensors


inline lemlib::OdomSensors sensors(nullptr,
                             nullptr,
                             nullptr,
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
inline lemlib::ControllerSettings angular_controller(2, // proportional gain (kP)
                                               0, // integral gain (kI)
                                               10, // derivative gain (kD)
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

