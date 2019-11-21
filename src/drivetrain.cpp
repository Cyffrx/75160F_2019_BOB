#include "main.h"
#include "smart_ports.h"

class Drivetrain {
private:
  pros::Motor left_front {LEFT_FRONT};
  pros::Motor left_back {LEFT_BACK};
  pros::Motor right_front {RIGHT_FRONT};
  pros::Motor right_back {RIGHT_BACK};

  pros::Controller driver {CONTROLLER_MASTER};

  bool mIsBrake;
  bool mIsAssisted;

/*////////////////////////////////

        PRIVATE FUNCTIONS

////////////////////////////////*/


  void aAssistedMove() {
    /*
      INTENTIONALLY LEFT BLANK
    */
  }

  void uInput() {
    int left_y = driver.get_analog(ANALOG_LEFT_Y);
    int left_x = driver.get_analog(ANALOG_LEFT_X);
    int right_x = driver.get_analog(ANALOG_RIGHT_X);

    // converts -127 -> 127 to -12000 -> 12000

    left_x = left_x*12000/127;
    left_y = left_y*12000/127;
    right_x = right_x*12000/127;

    left_front.move_voltage(left_y + left_x + right_x);
    left_back.move_voltage(left_y - left_x + right_x);
    right_front.move_voltage(left_y - left_x - right_x);
    right_back.move_voltage(left_y + left_x - right_x);
  }

public:
  Drivetrain(bool iIsAssisted, bool iIsBrake) {
    mIsAssisted = iIsAssisted;
    mIsBrake = iIsBrake;

    if (mIsBrake) {
      left_front.set_brake_mode(MOTOR_BRAKE_HOLD);
      left_back.set_brake_mode(MOTOR_BRAKE_HOLD);
      right_front.set_brake_mode(MOTOR_BRAKE_HOLD);
      right_back.set_brake_mode(MOTOR_BRAKE_HOLD);
    }
  }

  void uMove() {
    uInput();

    if (mIsAssisted)
      aAssistedMove();

  }


  /*////////////////////////////////

            GETTERS

  ////////////////////////////////*/

  bool gIsBrake() {
    return mIsBrake;
  }

  bool gIsAssisted() {
    return mIsAssisted;
  }
};
