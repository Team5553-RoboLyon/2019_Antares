#pragma once

#include <frc/commands/Command.h>

/**
 * Remonte les tiges filtées avants du robot
 */
class MonterRouesAvant : public frc::Command
{
 public:
  MonterRouesAvant();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
