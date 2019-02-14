#include "OI.h"
#include "commands/baseRoulante/ChangerVitesse.h"
#include "commands/pince/ChangerPositionPince.h"
#include "commands/pince/AttraperObjet.h"
#include "commands/pince/EjecterObjet.h"
#include "commands/pivot/SetSetpointPivot.h"
#include "Robot.h"


OI::OI()
{
  m_button1.WhenPressed(new ChangerVitesse());
  m_button2.WhenPressed(new ChangerPositionPince());
  m_button3.WhenPressed(new AttraperObjet());
  m_button4.WhenPressed(new EjecterObjet());

  m_button8.WhenPressed(new SetSetpointPivot(Robot::m_pivot.MILIEU));
  m_button9.WhenPressed(new SetSetpointPivot(Robot::m_pivot.HATCH_ARRIERE));
  m_button10.WhenPressed(new SetSetpointPivot(Robot::m_pivot.HATCH_AVANT));
  m_button11.WhenPressed(new SetSetpointPivot(Robot::m_pivot.CARGO_ARRIERE));
  m_button12.WhenPressed(new SetSetpointPivot(Robot::m_pivot.CARGO_AVANT));
}

frc::Joystick& OI::GetJoystick()
{
   return m_joystick;
}
