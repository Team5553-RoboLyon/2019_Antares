#pragma once

#include <frc/commands/Command.h>
#include "Robot.h"

/**
 * Change la position du pivot 
 * Fin quand le pivot a atteint le setpoint
 */
class SetSetpointPivot : public frc::Command
{
 private:
  double m_setpoint;

 public:
  SetSetpointPivot(double setpoint);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
