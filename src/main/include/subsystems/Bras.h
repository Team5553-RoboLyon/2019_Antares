#pragma once

#include <frc/WPILib.h>
#include <ctre/Phoenix.h>
#include "Cablage.h"

class Bras : public frc::PIDSubsystem
{
 public:
  Bras();
  double ReturnPIDInput() override;
  void UsePIDOutput(double output) override;
  void InitDefaultCommand() override;
};
