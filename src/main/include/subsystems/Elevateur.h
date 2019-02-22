#pragma once

#include <frc/WPILib.h>
#include "Cablage.h"

class Elevateur : public frc::Subsystem
{
 private:
  frc::PWMVictorSPX m_moteurAvant{PWM_ELEVATEUR_AVANT};
  frc::PWMVictorSPX m_moteurArriere{PWM_ELEVATEUR_ARRIERE};
  frc::PWMVictorSPX m_roues{PWM_ROUES_ELEVATEUR};

  bool m_robotEnHaut;

 public:
  Elevateur();
  void InitDefaultCommand() override;
  
  /**
   * Affichage des informations sur le subsystem
   */
  void Log();

  /**
   * Set les moteurs pour monter (+) ou descendre (-) le robot à l'avant
   */
  void SetMoteurAvant(double vitesse);
  
  /**
   * Set les moteurs pour monter (+) ou descendre (-) le robot à l'arrière
   */
  void SetMoteurArriere(double vitesse);
  
  /**
   * Set les moteurs des roues pour faire avancer (+) le robot
   */
  void SetRoues(double vitesse);
};
