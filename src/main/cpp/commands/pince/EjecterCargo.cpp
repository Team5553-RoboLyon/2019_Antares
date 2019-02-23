#include "commands/pince/EjecterCargo.h"
#include "Robot.h"

EjecterCargo::EjecterCargo() : TimedCommand(1.0)
{
  Requires(&Robot::m_pince);
}

void EjecterCargo::Initialize()
{
  Robot::m_pince.EjecterCargo();
  m_timer.Reset();
  m_timer.Start();
}

void EjecterCargo::Execute() {}

bool EjecterCargo::IsFinished()
{
  if(Robot::m_oi.m_button4.Get())
    m_timer.Reset();

  return m_timer.Get() > 1.0;
}

void EjecterCargo::End()
{
  Robot::m_pince.StopCargo();
}

void EjecterCargo::Interrupted()
{
  End();
}
