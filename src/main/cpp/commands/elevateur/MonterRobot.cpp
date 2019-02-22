#include "commands/elevateur/MonterRobot.h"
#include "Robot.h"

MonterRobot::MonterRobot()
{
  Requires(&Robot::m_elevateur);
}

void MonterRobot::Initialize()
{
  Robot::m_elevateur.SetMoteurAvant(0.0);
  Robot::m_elevateur.SetMoteurAvant(0.0);
}

void MonterRobot::Execute()
{
  double vitesse = (1 - Robot::m_oi.GetJoystick2().GetThrottle())/2;

  Robot::m_elevateur.SetMoteurAvant(vitesse);
  Robot::m_elevateur.SetMoteurArriere(vitesse);
}

bool MonterRobot::IsFinished() { return false; }

void MonterRobot::End()
{
  Robot::m_elevateur.SetMoteurAvant(0.0);
  Robot::m_elevateur.SetMoteurAvant(0.0);
}

void MonterRobot::Interrupted()
{
  End();
}
