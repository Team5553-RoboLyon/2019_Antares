#include "subsystems/Pince.h"

Pince::Pince() : Subsystem("Pince")
{
  m_positionHatch = true;

  m_roue1.SetInverted(false);
  m_roue2.SetInverted(true);

  // Permet d'afficher des infos sur la pince dans le shuffleboard
  AddChild("Roues", m_roues);
  AddChild("Roues", m_roue1);
  AddChild("Roues", m_roue2);
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
  m_verin.Set(frc::DoubleSolenoid::Value::kForward);
  m_positionHatch = true;
}

void Pince::Fermer()
{
  m_verin.Set(frc::DoubleSolenoid::Value::kReverse);
  m_positionHatch = false;
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
  m_roues.Set(0.5);
}

void Pince::EjecterCargo()
{
  m_roues.Set(-0.5);
}

void Pince::StopCargo()
{
  m_roues.StopMotor();
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
