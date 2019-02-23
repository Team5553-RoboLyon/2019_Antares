#include "commands/pince/AttraperCargo.h"
#include "Robot.h"

AttraperCargo::AttraperCargo() : TimedCommand(1.0)
{
  Requires(&Robot::m_pince);
}

void AttraperCargo::Initialize()
{
  Robot::m_pince.AttraperCargo();
  m_timer.Reset();
  m_timer.Start();
}

void AttraperCargo::Execute()
{
  if(m_timer.Get() > 0.4)
    Robot::m_pince.StopCargoRampe();
}

bool AttraperCargo::IsFinished()
{
  if(Robot::m_oi.m_button3.Get())
    m_timer.Reset();

  return m_timer.Get() > 1.0;
}

void AttraperCargo::End()
{
  Robot::m_pince.StopCargo();
}

void AttraperCargo::Interrupted()
{
  End();
}
