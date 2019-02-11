#pragma once

#include <frc/WPILib.h>
#include <ctre/Phoenix.h>
#include "Cablage.h"

class Pince : public frc::Subsystem
{
 private:
  frc::PWMVictorSPX m_roue1{PWM_ROUES_PINCE_1};
  frc::PWMVictorSPX m_roue2{PWM_ROUES_PINCE_2};
  frc::SpeedControllerGroup m_roues{m_roue1, m_roue2};

  frc::DoubleSolenoid m_verin{PCM_VERIN_PINCE_A, PCM_VERIN_PINCE_B};
  frc::DoubleSolenoid m_pistons{PCM_PISTONS_PINCE_A, PCM_PISTONS_PINCE_B};
  frc::DoubleSolenoid m_hatchPince{PCM_HATCH_PINCE_A, PCM_HATCH_PINCE_B};

  bool m_positionHatch;

 public:
  Pince();
  void InitDefaultCommand() override;

  /**
   * Ouvre la pince pour pouvoir attraper des hatch panels
   */
  void Ouvrir();

  /**
   * Ferme la pince pour pouvoir attraper des cargos
   */
  void Fermer();

  /**
   * Ouvre la pince si elle est fermée et vice-versa
   * Change le type d'objet à attraper
   */
  void ChangerPosition();

  /**
   * Return true si pince en position hatch
   */
  bool IsOuverte();

  /**
   * Aspire le cargo en faisant tourner les roues
   */
  void AttraperCargo();

  /**
   * Ejecte le cargo en faisant tourner les roues
   */
  void EjecterCargo();

   /**
   * Stoppe les roues de la pince à cargo
   */
  void StopCargo();

  /**
   * Attrape un hatch panel en ouvrant la petite pince
   */
  void AttraperHatch();

  /**
   * Relache un hatch panel en fermant la petite pince
   */
  void RelacherHatch();

  /**
   * Rentre les pistons
   */
  void RentrerPistons();

  /**
   * Sort les pistons pour ejecter les hatchs panels
   */
  void SortirPistons();
};
