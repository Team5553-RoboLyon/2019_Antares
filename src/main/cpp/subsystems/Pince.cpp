#include "subsystems/Pince.h"
#include "Robot.h"

Pince::Pince() : Subsystem("Pince")
{
  m_positionHatch = true;

  // Inversion de l'un des moteurs
  // Ils doivent tourner dans des sens inverses pour être syncro
  m_roue1.SetInverted(false);
  m_roue2.SetInverted(true);

  // Permet d'afficher des infos sur la pince dans le shuffleboard
  AddChild("Roues", m_roues);
  AddChild("Roues 1", m_roue1);
  AddChild("Roues 2", m_roue2);
  AddChild("Verin", m_verin);
  AddChild("Pistons", m_pistons);
  AddChild("Pince à hatchs", m_hatchPince);
}

void Pince::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Pince::Log() {}

void Pince::Ouvrir()
{
  // Ne pas ouvrir la pince si le pivot est sous 90° ou -90°
  if(abs(Robot::m_pivot.GetSetpoint()) <= 90.0)
  {
    m_verin.Set(frc::DoubleSolenoid::Value::kForward);
    m_positionHatch = true;

    // Quand la pince est ouverte, on restreint les angles du pivot possibles
    Robot::m_pivot.SetInputRange(-90.0, 90.0);
  }
}

void Pince::Fermer()
{
  m_verin.Set(frc::DoubleSolenoid::Value::kReverse);
  m_positionHatch = false;

  // Quand la pince est fermé, le pivot peut aller de -105° à 105°
  Robot::m_pivot.SetInputRange(-105.0, 105.0);
}

void Pince::ChangerPosition()
{
  if(m_positionHatch)
    Fermer();
  else
    Ouvrir();
}

bool Pince::IsOuverte()
{
  return m_positionHatch;
}

void Pince::AttraperCargo()
{
  m_roues.Set(0.4);
}

void Pince::EjecterCargo()
{
  m_roues.Set(-1.0 );
}

void Pince::StopCargo()
{
  m_roues.StopMotor();
}

void Pince::StopCargoRampe()
{
  double vitesse;
  
  if (m_vitessePrecedente >=  0)
  {
    vitesse = m_vitessePrecedente - m_maxDeceleration;
  }
  else
  {
    vitesse = 0.0;
  }
  
  m_vitessePrecedente = vitesse;
  m_roues.Set(vitesse);
}

void Pince::AttraperHatch()
{
  m_hatchPince.Set(frc::DoubleSolenoid::Value::kForward);
}

void Pince::RelacherHatch()
{
  m_hatchPince.Set(frc::DoubleSolenoid::Value::kReverse);
}

void Pince::RentrerPistons()
{
  m_pistons.Set(frc::DoubleSolenoid::Value::kForward);
}

void Pince::SortirPistons()
{
  m_pistons.Set(frc::DoubleSolenoid::Value::kReverse);
}
