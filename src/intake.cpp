#include "main.h"
#include "smart_ports.h"

class Intake {
private:
  pros::Motor left_intake {LEFT_INTAKE};
  pros::Motor right_intkae {RIGHT_INTAKE};

  pros::Controller driver {CONTROLLER_MASTER};

  bool mIsToggled;

public:

  Intake() {
    mIsToggled = false;
  }

  void uIntake() {

    if (mIsToggled) {
      if (driver.get_digital_new_press(DIGITAL_L1)) {
        left_intake.move_voltage(0);
        mIsToggled = false;
      } else if (driver.get_digital_new_press(DIGITAL_L2)) {
        mIsToggled = false;
        left_intake.move_voltage(0);
      }
    } else {

      const int SPEED = 12000;

      if (driver.get_digital_new_press(DIGITAL_L1)) {
        left_intake.move_voltage(SPEED);
        mIsToggled = true;
      } else if (driver.get_digital_new_press(DIGITAL_L2)) {
        mIsToggled = true;
        left_intake.move_voltage(-SPEED);
      }

    }

  }
};
