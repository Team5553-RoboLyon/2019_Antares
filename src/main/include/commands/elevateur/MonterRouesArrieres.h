#pragma once

#include <frc/commands/Command.h>

/**
 * Remonte les tiges filtées arrières du robot
 */
class MonterRouesArrieres : public frc::Command
{
 public:
  MonterRouesArrieres();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
