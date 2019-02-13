#include "subsystems/BaseRoulante.h"
#include "commands/baseRoulante/DriveWithJoystick.h"
#include <frc/smartdashboard/SmartDashboard.h>

BaseRoulante::BaseRoulante() : Subsystem("BaseRoulante")
{
  m_vitesse1 = true;
  m_vitesseDroitePrecedente = 0.0;
  m_vitesseGauchePrecedente = 0.0;

  m_baseGauche.SetInverted(false);
  m_baseDroite.SetInverted(true);

  m_encodeurGauche.SetReverseDirection(false);
  m_encodeurDroit.SetReverseDirection(true);

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
}

void BaseRoulante::Periodic()
{
  frc::SmartDashboard::PutBoolean("Vitessse 1 active", m_vitesse1);
}

void BaseRoulante::InitDefaultCommand()
{
  SetDefaultCommand(new DriveWithJoystick());
}

void BaseRoulante::Drive(double gauche, double droite)
{
  if(gauche > m_vitesseGauchePrecedente + m_maxAcceleration)
    gauche = m_vitesseGauchePrecedente + m_maxAcceleration;
  
  if(droite > m_vitesseDroitePrecedente + m_maxAcceleration)
    droite = m_vitesseDroitePrecedente + m_maxAcceleration;
  
  m_baseGauche.Set(gauche);
	m_baseDroite.Set(droite);

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
  m_encodeurGauche.SetDistancePerPulse(m_distanceParTickVitesse1);
  m_encodeurDroit.SetDistancePerPulse(m_distanceParTickVitesse1);
	m_vitesse1 = true;
}

void BaseRoulante::ActiverVitesse2()
{
  m_ballshiffter.Set(frc::DoubleSolenoid::Value::kForward);
  m_encodeurGauche.SetDistancePerPulse(m_distanceParTickVitesse2);
  m_encodeurDroit.SetDistancePerPulse(m_distanceParTickVitesse2);
	m_vitesse1 = false;
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