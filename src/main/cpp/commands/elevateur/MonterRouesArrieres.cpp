#include "commands/elevateur/MonterRouesArrieres.h"
#include "Robot.h"

MonterRouesArrieres::MonterRouesArrieres()
{
  Requires(&Robot::m_elevateur);
}

void MonterRouesArrieres::Initialize()
{
  Robot::m_elevateur.SetMoteurAvant(0.0);
  Robot::m_elevateur.SetMoteurArriere(0.0);
}

void MonterRouesArrieres::Execute()
{
  double vitesse = (1 - Robot::m_oi.GetJoystick2().GetThrottle())/2;

  Robot::m_elevateur.SetMoteurArriere(-vitesse);
}

bool MonterRouesArrieres::IsFinished() { return false; }

void MonterRouesArrieres::End()
{
  Robot::m_elevateur.SetMoteurAvant(0.0);
  Robot::m_elevateur.SetMoteurArriere(0.0);
}

void MonterRouesArrieres::Interrupted()
{
  End();
}
