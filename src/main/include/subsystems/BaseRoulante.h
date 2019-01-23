#pragma once

#include <frc/WPILib.h>
#include <ctre/Phoenix.h>
#include "Cablage.h"

class BaseRoulante : public frc::Subsystem
{
 private:
  
 public:
  BaseRoulante();
  void InitDefaultCommand() override;
};
