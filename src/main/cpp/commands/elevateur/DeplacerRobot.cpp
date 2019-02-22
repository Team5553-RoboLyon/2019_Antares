#include "commands/elevateur/DeplacerRobot.h"
#include "Robot.h"

DeplacerRobot::DeplacerRobot()
{
  Requires(&Robot::m_elevateur);
  m_pov = -1;
}

void DeplacerRobot::Initialize() {}

void DeplacerRobot::Execute()
{
  //On récupère la position du POV du joystick
  m_pov = Robot::m_oi.GetJoystick2().GetPOV();

  //On avance ou recule en foncion de la position du joystick (Positions: 0=haut et 180=bas)
  if(m_pov == 0)
  {
    // On avance
    Robot::m_elevateur.SetRoues(0.2);
  }
  else if(m_pov == 180)
  {
    // On recule
    Robot::m_elevateur.SetRoues(-0.2);
  }
}

bool DeplacerRobot::IsFinished() { return false; }

void DeplacerRobot::End() {}

void DeplacerRobot::Interrupted() {}
