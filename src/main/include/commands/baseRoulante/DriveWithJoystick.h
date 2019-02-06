#pragma once

#include <frc/commands/Command.h>

/**
 * Conduire la Base Roulante avec le joystick
 * Pas de fin
 */
class DriveWithJoystick : public frc::Command
{
 public:
  DriveWithJoystick();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
