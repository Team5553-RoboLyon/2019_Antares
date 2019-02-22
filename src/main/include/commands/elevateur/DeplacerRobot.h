#pragma once

#include <frc/commands/Command.h>

/**
 * Deplace le robot en avant ou en arrière lorsqu'il est en haut
 */
class DeplacerRobot : public frc::Command
{
 public:
  DeplacerRobot();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

 private:
  int m_pov;
};
