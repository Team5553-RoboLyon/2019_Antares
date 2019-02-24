#include "commands/pivot/AjusterPivot.h"
#include "Robot.h"

AjusterPivot::AjusterPivot()
{
  Requires(&Robot::m_pivot);
  m_pov = -1;
}

void AjusterPivot::Initialize() {}

void AjusterPivot::Execute()
{
  //On récupère la position du POV du joystick
  m_pov = Robot::m_oi.GetJoystick().GetPOV();

  //On augmente ou diminue sa consigne en foncion de la position du joystick (Positions: 0=haut et 180=bas)
  if(m_pov == 0)
  {
    //SetSetpointRelative(12) = on ajoute 12 au dernier setpoint d�fini
    Robot::m_pivot.SetSetpointRelative(1.5);
  }
  else if(m_pov == 180)
  {
    //SetSetpointRelative(-12) = on soustrait 12 au dernier setpoint d�fini
    Robot::m_pivot.SetSetpointRelative(-1.5);
  }
  else if(m_pov == 90)
  {
    Robot::m_pivot.SetSetpoint(Pivot::FUSEE_ARRIERE);
  }
  else if(m_pov == 270)
  {
    Robot::m_pivot.SetSetpoint(Pivot::FUSEE_AVANT);
  }
}

bool AjusterPivot::IsFinished()
{
  //Cette commande n'a pas de fin, elle peut être éxécutée sans arrêt
  return false;
}

void AjusterPivot::End() {}

void AjusterPivot::Interrupted() {}
