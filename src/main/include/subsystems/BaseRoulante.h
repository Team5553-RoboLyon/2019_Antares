#pragma once

// Pour avoir M_PI
#define _USE_MATH_DEFINES
#include <math.h>

/*// Pour écrire dans les fichiers
#include <fstream>
#include <string>*/

#include <frc/WPILib.h>
#include "Cablage.h"

class BaseRoulante : public frc::Subsystem
{
 private:
  frc::PWMVictorSPX m_baseDroite1{PWM_BASE_DROITE_1};
  frc::PWMVictorSPX m_baseDroite2{PWM_BASE_DROITE_2};
  frc::PWMVictorSPX m_baseDroite3{PWM_BASE_DROITE_3};
  frc::SpeedControllerGroup m_baseDroite{m_baseDroite1, m_baseDroite2, m_baseDroite3};

  frc::PWMVictorSPX m_baseGauche1{PWM_BASE_GAUCHE_1};
  frc::PWMVictorSPX m_baseGauche2{PWM_BASE_GAUCHE_2};
  frc::PWMVictorSPX m_baseGauche3{PWM_BASE_GAUCHE_3};
  frc::SpeedControllerGroup m_baseGauche{m_baseGauche1, m_baseGauche2, m_baseGauche3};

  frc::ADXRS450_Gyro m_gyro;
  frc::Encoder m_encodeurDroit{DIO_ENCODEUR_DROIT_A, DIO_ENCODEUR_DROIT_B};
  frc::Encoder m_encodeurGauche{DIO_ENCODEUR_GAUCHE_A, DIO_ENCODEUR_GAUCHE_B};

  frc::DoubleSolenoid m_ballshiffter{PCM_BALLSHIFTER_A, PCM_BALLSHIFTER_B};

  /*std::string m_nomFichier = "/home/lvuser/odometrie.txt";
  std::fstream m_fichierOdometrie;*/

  bool m_vitesse1;

  const double m_circonferenceRoues = 0.155 * M_PI;
  const double m_distanceParTickVitesse1 = ((1.0/20.0)/12.0) * m_circonferenceRoues;
  const double m_distanceParTickVitesse2 = ((1.0/20)/7.0) * m_circonferenceRoues;
  const double m_maxAcceleration = 0.03;
  double m_vitesseDroitePrecedente, m_vitesseGauchePrecedente;

 public:
  BaseRoulante();
  void InitDefaultCommand() override;

  /**
   * Affichage des informations sur le subsystem
   */
  void Log();

  /**
   * Gère l'accelération de la base
   * Recupere la puissance d'un moteur et celle qu'on veut lui mettre
   * Return la puissance avec une accéleration limitée
   */
  double Rampe(double vitessePrecedente, double vitesse);

  /**
   * Set les moteurs de la base aux valeurs données
   * Valeurs positives pour avancer
   */
  void Drive(double gauche, double droite);

  /**
   * Set tous les moteurs de la base à zéro
   */
  void Stop();

  /**
   * Active la première vitesse
   * Adapte la distance calculée par les encodeurs avec le nouveau rapport
   */
  void ActiverVitesse1();

  /**
   * Active la deuxième vitesse
   * Adapte la distance calculée par les encodeurs avec le nouveau rapport
   */
  void ActiverVitesse2();

  /**
   * Met la vitesse différente de celle actuelle
   * Adapte la distance calculée par les encodeurs avec le nouveau rapport
   */
  void ChangerVitesse();

  /**
   * Return la distance parcourue en m par la base droite depuis le dernier reset
   * Valeur positive pour un déplacement en avant
   */
  double GetDistanceDroite();

  /**
   * Return la distance parcourue en m par la base gauche depuis le dernier reset
   * Valeur positive pour un déplacement en avant
   */
  double GetDistanceGauche();

  /**
   * Return les ticks de l'encodeur gauche depuis le dernier reset
   * Valeur positive pour un déplacement en avant
   */
  int GetTicksGauche();

  /**
   * Return les ticks de l'encodeur droit depuis le dernier reset
   * Valeur positive pour un déplacement en avant
   */
  int GetTicksDroite();

  /**
   * Return l'angle parcouru en degré depuis le dernier reset
   * Valeur positive dans le sens des aiguilles d'une montre
   */
  double GetAngle();

  /**
   * Remet les valeurs des encodeurs et du gyro à zéro
   */
  void ResetCapteurs();
};
