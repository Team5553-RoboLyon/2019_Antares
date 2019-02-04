#include "subsystems/BaseRoulante.h"

BaseRoulante::BaseRoulante() : Subsystem("BaseRoulante")
{
    m_vitesse1 = true;

    m_baseGauche.SetInverted(false);
    m_baseDroite.SetInverted(true);

    m_encodeurGauche.SetReverseDirection(false);
    m_encodeurDroit.SetReverseDirection(true);

    m_encodeurGauche.SetDistancePerPulse(m_distanceParTickVitesse1);
    m_encodeurDroit.SetDistancePerPulse(m_distanceParTickVitesse1);

    // Permet d'afficher des infos sur la base dans le shuffleboard
    AddChild("Base Droite", m_baseDroite);
    AddChild("Base Gauche", m_baseGauche);
    AddChild("Gyro", m_gyro);
    AddChild("Encodeur Droit", m_encodeurDroit);
    AddChild("Encodeur Gauche", m_encodeurGauche);
    AddChild("Ballshiffter", m_ballshiffter);
}

void BaseRoulante::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void BaseRoulante::Periodic()
{

} 

void BaseRoulante::Drive(double gauche, double droite)
{
  m_baseGauche.Set(gauche);
	m_baseDroite.Set(droite);
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