#include "commands/AttraperCargo.h"

AttraperCargo::AttraperCargo() : TimedCommand(1.0)
{
  Requires(&Robot::m_pince);
}

void AttraperCargo::Initialize()
{
  Robot::m_pince.AttraperCargo();
}

void AttraperCargo::Execute() {}

void AttraperCargo::End()
{
  Robot::m_pince.StopCargo();
}

void AttraperCargo::Interrupted()
{
  End();
}
