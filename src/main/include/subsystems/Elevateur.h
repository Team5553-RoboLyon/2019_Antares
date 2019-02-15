#pragma once

#include <frc/WPILib.h>
#include "Cablage.h"

class Elevateur : public frc::PIDSubsystem
{
 public:
  Elevateur();
  double ReturnPIDInput() override;
  void UsePIDOutput(double output) override;
  void InitDefaultCommand() override;

  /**
   * Affichage des informations sur le subsystem
   */
  void Log();
};
