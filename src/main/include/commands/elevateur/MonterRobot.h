#pragma once

#include <frc/commands/Command.h>

/**
 * Monte le robot à l'aide des tiges filtées avec le Throttle du joystick
*/
class MonterRobot : public frc::Command
{
 public:
  MonterRobot();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
