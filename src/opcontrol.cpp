#include "main.h"
#include "opcontrol_subsystems.h"

void opcontrol() {

Drivetrain drivetrain (false, false);
Subsystem subsystem (false, true);
Intake intake;

  while ( true) {
    drivetrain.uMove();
    subsystem.uMoveArm();
    subsystem.uMoveLift();
    intake.uIntake();
  }

}
