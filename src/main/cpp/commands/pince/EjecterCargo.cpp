#include "commands/pince/EjecterCargo.h"
#include "Robot.h"

EjecterCargo::EjecterCargo() : TimedCommand(1.0)
{
  Requires(&Robot::m_pince);
}

void EjecterCargo::Initialize()
{
  Robot::m_pince.EjecterCargo();
}

void EjecterCargo::Execute() {}

void EjecterCargo::End()
{
  Robot::m_pince.StopCargo();
}

void EjecterCargo::Interrupted()
{
  End();
}
