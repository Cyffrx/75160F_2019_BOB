class Drivetrain {
public:
  Drivetrain(bool iIsAssisted, bool iIsBrake);
  void uMove();
  bool gIsBrake();
  bool gIsAssisted();
};

class Subsystem {
public:
  Subsystem(bool iIsAssisted, bool iIsBrake);
  void uMoveLift();
  void uMoveArm();

  bool gIsBrake();
  bool gArmPosition();
  bool gLiftPosition();
};

class Intake {
public:
  Intake();
  void uIntake();
};
