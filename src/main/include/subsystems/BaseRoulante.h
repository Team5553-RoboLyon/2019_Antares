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
  void Periodic() override;

  void Drive(double gauche, double droite);
  void BaseRoulante::ChangerVitesse () ;
  void BaseRoulante::ResetPID ();
  void BaseRoulante::ActiverVitesse1 ();
  void BaseRoulante::ActiverVitesse2 ();
  void BaseRoulante::GetEncodeur ();
};
