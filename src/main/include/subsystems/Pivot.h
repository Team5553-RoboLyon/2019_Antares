#pragma once

// Pour avoir M_PI
#define _USE_MATH_DEFINES
#include <math.h>

#include <frc/WPILib.h>
#include <rev/CANSparkMax.h>
#include "Cablage.h"

class Pivot : public frc::PIDSubsystem
{
 private:
  rev::CANSparkMax m_moteur{CAN_PIVOT, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANEncoder m_encodeur{m_moteur};

  double m_vitessePrecedente;
  const double m_angleParTick = 2.0;
  const double m_coefGravite = 0.04;
  const double m_maxAcceleration = 0.1;

 public:
  Pivot();
  void Periodic() override;
  double ReturnPIDInput() override;
  void UsePIDOutput(double output) override;
  void InitDefaultCommand() override;

  /**
   * Gère l'accelération du pivot
   * Recupere la puissance qu'on veut mettre au moteur
   * Return la puissance avec une accéleration limitée
   */
  double Rampe(double vitesse);

  /**
   * Convertir un angle en degrés en radians
   */
  double Deg2rad(double angle){ return (angle*M_PI)/180.0; };
  
  /**
   * Return l'angle du pivot en degrés
   */
  double GetAngle();

  /**
   * Return l'angle du pivot en radians
   */
  double GetAngleRad();

  /**
   * Valeurs d'angles prédéfinies pour aller à une position donnée
   */
  const double MILIEU = 0.0;
  const double CARGO_AVANT = 105.0;
  const double CARGO_ARRIERE = -105.0;
  const double HATCH_AVANT = 90.0;
  const double HATCH_ARRIERE = -90.0;
  const double FUSEE_AVANT = 45.0;
  const double FUSEE_ARRIERE = -45.0;
};
