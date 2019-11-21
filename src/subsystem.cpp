#include "main.h"
#include "smart_ports.h"

class Subsystem {
private:
  pros::Controller driver {CONTROLLER_MASTER};

  pros::Motor lift {LIFT};
  pros::Motor arm {ARM};

  bool mIsBrake = false;
  bool mIsAssisted = false;

  int mLowTower = 0;
  int mMidTower = 0;
  int mHighTower = 0;


  /*////////////////////////////////

          PRIVATE FUNCTIONS

  ////////////////////////////////*/

  void aAssitedLift() {
    if (driver.get_digital_new_press(DIGITAL_A)) {
      //ramp down to score
    } else if (driver.get_digital_new_press(DIGITAL_Y)) {
      //go to mLowTower
    } else if (driver.get_digital_new_press(DIGITAL_X)) {
      //go to mMidTower
    } else if (driver.get_digital_new_press(DIGITAL_B)) {
      //go to mHighTower
    }
  }

  void aAssitedArm() {
    if (driver.get_digital_new_press(DIGITAL_LEFT)) {
        //go to mLowTower
      } else if (driver.get_digital_new_press(DIGITAL_UP)) {
        //go to mMidTower
      } else if (driver.get_digital_new_press(DIGITAL_RIGHT)) {
        //go to mHighTower
      } else if (driver.get_digital_new_press(DIGITAL_DOWN)) {
        //go to intake level
      }
  }

public:

  Subsystem(bool iIsBrake, bool iIsAssisted) {
    mIsBrake = iIsBrake;
    mIsAssisted = iIsAssisted;

    if (mIsBrake) {
      lift.set_brake_mode(MOTOR_BRAKE_HOLD);
      arm.set_brake_mode(MOTOR_BRAKE_HOLD);
    }
  }

  void uMoveLift() {

    if (mIsAssisted) {
      aAssitedLift();
    } else {

      const int SPEED = 12000;
      if (driver.get_digital(DIGITAL_R1)) {
        arm.move_voltage(SPEED);
      } else if (driver.get_digital(DIGITAL_R2)) {
        arm.move_voltage(-SPEED);
      }
    }
  }

  void uMoveArm() {
    if (mIsAssisted) {
      aAssitedArm();
    } else {

        const int SPEED = 12000;
        if (driver.get_digital(DIGITAL_X)) {
          arm.move_voltage(SPEED);
        } else if (driver.get_digital(DIGITAL_B)) {
          arm.move_voltage(-SPEED);
        }
      }
    }


  /*////////////////////////////////

            GETTERS

  ////////////////////////////////*/

  bool gIsBrake() {
    return false;
  }

  int gArmPosition() {
    return 0;
  }

  int gLiftPosition() {
    return 0;
  }

};
