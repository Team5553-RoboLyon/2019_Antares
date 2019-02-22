#include "commands/elevateur/MonterRouesAvant.h"
#include "Robot.h"

MonterRouesAvant::MonterRouesAvant()
{
  Requires(&Robot::m_elevateur);
}

void MonterRouesAvant::Initialize()
{
  Robot::m_elevateur.SetMoteurAvant(0.0);
  Robot::m_elevateur.SetMoteurAvant(0.0);
}

void MonterRouesAvant::Execute()
{
  double vitesse = (1 - Robot::m_oi.GetJoystick2().GetThrottle())/2;

  Robot::m_elevateur.SetMoteurAvant(-vitesse);
}

bool MonterRouesAvant::IsFinished() { return false; }

void MonterRouesAvant::End()
{
  Robot::m_elevateur.SetMoteurAvant(0.0);
  Robot::m_elevateur.SetMoteurAvant(0.0);
}

void MonterRouesAvant::Interrupted()
{
  End();
}
