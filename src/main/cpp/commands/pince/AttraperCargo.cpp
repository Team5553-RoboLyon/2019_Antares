#include "commands/pince/AttraperCargo.h"
#include "Robot.h"

AttraperCargo::AttraperCargo() : TimedCommand(1.0)
{
  Requires(&Robot::m_pince);
}

void AttraperCargo::Initialize()
{
  Robot::m_pince.AttraperCargo();
}

void AttraperCargo::Execute()
{
  if(TimeSinceInitialized() > 0.6)
    Robot::m_pince.StopCargoRampe();
}

void AttraperCargo::End()
{
  Robot::m_pince.StopCargo();
}

void AttraperCargo::Interrupted()
{
  End();
}
