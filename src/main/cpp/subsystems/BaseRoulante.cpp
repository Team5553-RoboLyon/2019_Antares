#include "subsystems/BaseRoulante.h"
#include "commands/baseRoulante/DriveWithJoystick.h"

#include <time.h>

BaseRoulante::BaseRoulante() : Subsystem("BaseRoulante")
{
  m_vitesse1 = true;
  m_vitesseDroitePrecedente = 0.0;
  m_vitesseGauchePrecedente = 0.0;

  // Inversion des moteur d'un côté de la base
  // Les vitesse positives permettent ainsi d'avancer
  m_baseGauche.SetInverted(true);
  m_baseDroite.SetInverted(false);

  // Inversion des encodeurs d'un côté de la base
  // Anvancer fait ainsi augmenter la distance
  m_encodeurGauche.SetReverseDirection(true);
  m_encodeurDroit.SetReverseDirection(false);

  // Set le ratio pour convertir les ticks en mètres
  m_encodeurGauche.SetDistancePerPulse(m_distanceParTickVitesse1);
  m_encodeurDroit.SetDistancePerPulse(m_distanceParTickVitesse1);

  // Permet d'afficher des infos sur la base dans le shuffleboard
  AddChild("Base Droite", m_baseDroite);
  AddChild("Base Droite 1", m_baseDroite1);
  AddChild("Base Droite 2", m_baseDroite2);
  AddChild("Base Droite 3", m_baseDroite3);

  AddChild("Base Gauche", m_baseGauche);
  AddChild("Base Gauche 1", m_baseGauche1);
  AddChild("Base Gauche 2", m_baseGauche2);
  AddChild("Base Gauche 3", m_baseGauche3);

  AddChild("Gyro", m_gyro);
  AddChild("Encodeur Droit", m_encodeurDroit);
  AddChild("Encodeur Gauche", m_encodeurGauche);
  AddChild("Ballshiffter", m_ballshiffter);

  // Ouverture et fermeture du fichier pour effacer toutes les données
  m_fichierOdometrie.open(m_nomFichier, std::ios::out | std::ios::trunc);
  m_fichierOdometrie << "timestamp ticksDroite ticksGauche vitesse1Activee" << std::endl;
  m_fichierOdometrie.close();
}

void BaseRoulante::InitDefaultCommand()
{
  // Par défaut, on éxécute cette command
  SetDefaultCommand(new DriveWithJoystick());
}

void BaseRoulante::Log()
{
  // Affiche l'êtat du ballshifter sur le ShuffleBoard
  frc::SmartDashboard::PutBoolean("Vitessse 1 active", m_vitesse1);
  frc::SmartDashboard::PutNumber("Ticks Gauche", m_encodeurGauche.Get());
  frc::SmartDashboard::PutNumber("Ticks Droite", m_encodeurDroit.Get());

  // Ecrit dans les fichiers l'etat de la base
  m_fichierOdometrie.open(m_nomFichier, std::ios::out | std::ios::app);

  struct timespec now;
  clock_gettime(CLOCK_MONOTONIC, &now);
  m_fichierOdometrie << now.tv_nsec << " " << m_encodeurDroit.Get() << " " << m_encodeurGauche.Get() << " " << m_vitesse1 << std::endl;
  m_fichierOdometrie.close();
}

double BaseRoulante::Rampe(double vitessePrecedente, double vitesse)
{
  // Si la vitesse est superieure à zero alors l'acceleration se fait dans le sens croissant : 0.5 -> 1
  if(vitesse > 0 && vitesse > vitessePrecedente + m_maxAcceleration)
  {
    vitesse = vitessePrecedente + m_maxAcceleration;
  }
  // Si la vitesse est inferieure à zero alors l'acceleration se fait dans le sens décroissant : -0.5 -> -1
  else if(vitesse < 0 && vitesse < vitessePrecedente - m_maxAcceleration)
  {
    vitesse = vitessePrecedente - m_maxAcceleration;
  }

  return vitesse;
}

void BaseRoulante::Drive(double gauche, double droite)
{
  droite *= 0.972;

  // On change la valeur pour réduire l'accéleration
  gauche = Rampe(m_vitesseGauchePrecedente, gauche);
  droite = Rampe(m_vitesseDroitePrecedente, droite);
  
  // On change la puissance des moteurs
  m_baseGauche.Set(gauche);
	m_baseDroite.Set(droite);

  // On actualise les vitesses stockées
  m_vitesseDroitePrecedente = droite;
  m_vitesseGauchePrecedente = gauche;
}

void BaseRoulante::Stop()
{
  m_baseGauche.StopMotor();
	m_baseDroite.StopMotor();
}

void BaseRoulante::ActiverVitesse1()
{
  m_ballshiffter.Set(frc::DoubleSolenoid::Value::kReverse);
	m_vitesse1 = true;

  // Changement du ratio ticks/mètres pour coller à la nouvelle réduction
  m_encodeurGauche.SetDistancePerPulse(m_distanceParTickVitesse1);
  m_encodeurDroit.SetDistancePerPulse(m_distanceParTickVitesse1);
}

void BaseRoulante::ActiverVitesse2()
{
  m_ballshiffter.Set(frc::DoubleSolenoid::Value::kForward);
	m_vitesse1 = false;

  // Changement du ratio ticks/mètres pour coller à la nouvelle réduction
  m_encodeurGauche.SetDistancePerPulse(m_distanceParTickVitesse2);
  m_encodeurDroit.SetDistancePerPulse(m_distanceParTickVitesse2);
}

void BaseRoulante::ChangerVitesse()
{
  if(m_vitesse1)
		ActiverVitesse2();
	else
		ActiverVitesse1();
}

double BaseRoulante::GetDistanceDroite()
{
  return m_encodeurDroit.GetDistance();
}

double BaseRoulante::GetDistanceGauche()
{
  return m_encodeurGauche.GetDistance();
}

double BaseRoulante::GetAngle()
{
  return m_gyro.GetAngle();
}

void BaseRoulante::ResetCapteurs()
{
  m_encodeurDroit.Reset();
  m_encodeurGauche.Reset();
	m_gyro.Reset();
}