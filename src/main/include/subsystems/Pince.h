#pragma once

#include <frc/WPILib.h>
#include <ctre/Phoenix.h>
#include "Cablage.h"

class Pince : public frc::Subsystem
{
 private:
  
 public:
  Pince();
  void InitDefaultCommand() override;
};
