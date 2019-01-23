#pragma once

#include <frc/WPILib.h>
#include <ctre/Phoenix.h>
#include "Cablage.h"

class Pivot : public frc::PIDSubsystem
{
 public:
  Pivot();
  double ReturnPIDInput() override;
  void UsePIDOutput(double output) override;
  void InitDefaultCommand() override;
};
