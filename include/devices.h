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

// // start of imu
// #include "lemlib/util.hpp"
// #include "pros/error.h"
// #include "devices.h"
// #include <cmath>
// #include <sstream>

// // lemlib::OdomSensors* Robot::odomSensors = nullptr;
// // lemlib::Chassis* Robot::chassis = nullptr;

// class HeadingSource {
//   public:
//     // returns the heading of the source
//     /** returns NaN if messed up */
//     virtual double getHeading() const = 0;
//     virtual bool calibrate() = 0;
//     virtual bool isDoneCalibrating() const = 0;

//     void disable() { _isEnabled = false; }

//     void enable() { _isEnabled = true; }

//     bool isEnabled() { return _isEnabled; }
//   private:
//     bool _isEnabled = true;
// };

// class IMUHeadingSource : public HeadingSource {
//   public:
//     IMUHeadingSource(pros::IMU* imu, const float _gain = 1)
//       : imu(imu), gain(_gain) {}

//     double getHeading() const override {
//       if (imu->get_rotation() == PROS_ERR_F) return NAN;
//       return imu->get_rotation() * gain;
//     }

//     bool calibrate() override { return imu->reset(false); }

//     bool isDoneCalibrating() const override { return !imu->is_calibrating(); }
//   protected:
//     /**
//      * @brief adjusts imu output to account for linear drift
//      */
//     float gain;
//   private:
//     pros::IMU* imu;
// };

// // only make one of these!!!
// class MockIMU : public pros::IMU {
//   public:
//     MockIMU(std::vector<HeadingSource*> sources)
//       : pros::IMU(0), sources(sources) {}

//     // used by lemlib to check that the IMU is working
//     double get_heading() const override {
//       const float possiblyNegativeHeading =
//           std::remainder(this->get_rotation(), 360);
//       if (possiblyNegativeHeading < 0) return 360 + possiblyNegativeHeading;
//       else return possiblyNegativeHeading;
//     }

//     double get_rotation() const override {
//       static int lastCall = pros::millis();
//       static std::vector<double> prevHeadings(this->sources.size(), 0);
//       static double prevReturnedHeading = 0;
//       // return the average of the closest sources that are not messed up
//       std::vector<double> deltaHeadings;
//       std::vector<double> newHeadings;
//       std::stringstream printSS;
//       static const char* telemetryPrefix = "!:";
//       printSS << telemetryPrefix;
//       printSS << pros::millis() - lastCall << ",";
//       lastCall = pros::millis();
//       for (int i = 0; i < sources.size(); i++) {
//         char buffer[10];
//         float heading = sources[i]->getHeading();

//         if (!sources[i]->isEnabled() && !std::isnan(heading)) {
//           newHeadings.push_back(heading);
//           sprintf(buffer, "DIS");

//         } else if (!std::isnan(heading)) {
//           newHeadings.push_back(heading);
//           deltaHeadings.push_back(heading - prevHeadings[i]);
//           sprintf(buffer, "%0.4f", heading - prevHeadings[i]);
//         } else {
//           newHeadings.push_back(prevHeadings[i]);
//           sprintf(buffer, "NAN");
//         }
//         printSS << buffer << ",";
//       }
//       double out = 0;

//       if (deltaHeadings.size() == 0) {
//         out = prevReturnedHeading;
//       } else if (deltaHeadings.size() == 1) {
//         out = prevReturnedHeading + deltaHeadings[0];
//       } else if (deltaHeadings.size() == 2) {
//         out = prevReturnedHeading + (deltaHeadings[0] + deltaHeadings[1]) / 2;
//       } else {
//         std::sort(deltaHeadings.begin(), deltaHeadings.end());
//         // // take the median of the deltaHeadings
//         // auto size = deltaHeadings.size();
//         // if (size % 2 == 0)
//         //   out = prevReturnedHeading +
//         //         (deltaHeadings[size / 2 - 1] + deltaHeadings[size / 2]) / 2;
//         // else out = prevReturnedHeading + deltaHeadings[size / 2];

//         // take the average of the two closest values
//         std::vector<double> headingDiffs;
//         for (int i = 0; i < deltaHeadings.size() - 1; i++) {
//           headingDiffs.push_back(deltaHeadings[i + 1] - deltaHeadings[i]);
//         }
//         double smallestDiff = headingDiffs[0];
//         int smallestDiffIndex = 0;
//         for (int i = 1; i < headingDiffs.size(); i++) {
//           if (headingDiffs[i] < smallestDiff) {
//             smallestDiff = headingDiffs[i];
//             smallestDiffIndex = i;
//           }
//         }

//         out = prevReturnedHeading + (deltaHeadings[smallestDiffIndex] +
//                                      deltaHeadings[smallestDiffIndex + 1]) /
//                                         2;
//       }
//       if (std::isnan(out)) out = prevReturnedHeading;
//       printSS << out << "\n";
//       // printf("%s", printSS.str().c_str());

//       newHeadings.swap(prevHeadings);
//       prevReturnedHeading = out;
//       return out;
//     }

//     int32_t reset(bool idk) const override { return 1; }

//     bool calibrate() {
//       enum CALIBRATION_STATE { NOT_CALIBRATING, CALIBRATING, DONE_CALIBRATING };

//       std::vector<CALIBRATION_STATE> calibrationStates(this->sources.size(),
//                                                        NOT_CALIBRATING);
//       int doneCount = 0;
//       int timer = pros::millis() + 8000;
        
//       while (doneCount < sources.size() && !(timer - pros::millis() > 8000)) {
//         for (int i = 0; i < sources.size(); i++) switch (calibrationStates[i]) {
//             case NOT_CALIBRATING:
//               if (sources[i]->calibrate()) {
//                 calibrationStates[i] = CALIBRATING;
//               }
//               break;
//             case CALIBRATING:
//               if (sources[i]->isDoneCalibrating()) {
//                 calibrationStates[i] = DONE_CALIBRATING;
//                 doneCount++;
//               }
//               break;
//             case DONE_CALIBRATING: break;
//           }
//         pros::delay(10);
//       }
//       if (doneCount == 0) return false;
//       else if (doneCount == sources.size()) return true;
//       else {
//         // if only some sources are done calibrating, return true and only use
//         // those
//         std::vector<HeadingSource*> calibratedSources;
//         for (int i = 0; i < sources.size(); i++)
//           if (calibrationStates[i] == DONE_CALIBRATING)
//             calibratedSources.push_back(sources[i]);
//         sources.swap(calibratedSources);
//         return true;
//       }
//     }

//     bool is_calibrating() const override {
//       for (auto source : sources)
//         if (!source->isDoneCalibrating()) return true;
//       return false;
//     }

//     std::vector<HeadingSource*> sources;
// };
// // end imu stuff

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
                              8 // horizontal drift
);


inline pros::MotorGroup intake_motors({17, -10}); 
//inline Motor intake_motor(INTAKE_PORT);M
inline pros::ADIDigitalOut clamp_sol(CLAMP_PORT, clamp_state);
inline pros::Imu imu({IMU_PORT});

// imu = new IMUHeadingSource(&imu);
// inline auto mockIMU = new MockIMU(imu);

//UNCOMMENT THIS:
inline pros::Rotation vert_tracking(VERT_TRACKING_WHEEL);
inline pros::Rotation hor_tracking(HOR_TRACKING_WHEEL);

//uncomment this:
inline lemlib::TrackingWheel vertical_tracking_wheel(&vert_tracking, lemlib::Omniwheel::OLD_275_HALF, 0.5); // arbitrary offset number!!!!!!!!!!!
inline lemlib::TrackingWheel horizontal_tracking_wheel(&hor_tracking, lemlib::Omniwheel::OLD_275_HALF, -1.25); // arbitrary offset number!!!!!!!!

// odom sensors


inline lemlib::OdomSensors sensors(&vertical_tracking_wheel,
                             nullptr,
                             &horizontal_tracking_wheel,
                             nullptr,
                             &imu
 );

// lateral PID controller
// RMB TO RESTORE OG VALUES
inline lemlib::ControllerSettings lateral_controller(5, // proportional gain (kP)
                                               0, // integral gain (kI)
                                            37, // derivative gain (kD)
                                               0, // anti windup
                                               0, // small error range, in inches
                                               0, // small error range timeout, in milliseconds
                                               0, // large error range, in inches
                                               0, // large error range timeout, in milliseconds
                                               0 // maximum acceleration (slew)
 );


// angular PID controller
// RMB TO RESTORE OG VALUES
inline lemlib::ControllerSettings angular_controller(0.7, // proportional gain (kP)
                                               0, // integral gain (kI)
                                               0.64, // derivative gain (kD)
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

