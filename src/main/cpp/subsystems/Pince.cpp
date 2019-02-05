#include "subsystems/Pince.h"

Pince::Pince() : Subsystem("Pince")
{
  m_positionCargo = false;

  // Permet d'afficher des infos sur la base dans le shuffleboard
  AddChild("Roues", m_roues);
  AddChild("Verin", m_verin);
  AddChild("Pistons", m_pistons);
  AddChild("Pince à hatchs", m_hatchPince);
}

void Pince::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Pince::Ouvrir()
{
  m_verin.Set(frc::DoubleSolenoid::Value::kReverse);
  m_positionCargo = false;
}

void Pince::Fermer()
{
  m_verin.Set(frc::DoubleSolenoid::Value::kForward);
  m_positionCargo = true;
}

void Pince::ChangerPosition()
{
  if(m_positionCargo)
    Ouvrir();
  else
    Fermer();
}

void Pince::AttraperCargo()
{
  m_roues.Set(0.5);
}

void Pince::EjecterCargo()
{
  m_roues.Set(-0.5);
}

void Pince::AttraperHatch()
{
  m_hatchPince.Set(frc::DoubleSolenoid::Value::kReverse);
}

void Pince::RelacherHatch()
{
  m_hatchPince.Set(frc::DoubleSolenoid::Value::kForward);
}

void Pince::RentrerPistons()
{
  m_pistons.Set(frc::DoubleSolenoid::Value::kReverse);
}

void Pince::SortirPistons()
{
  m_pistons.Set(frc::DoubleSolenoid::Value::kForward);
}
