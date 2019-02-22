#include "OI.h"

#include "commands/baseRoulante/ChangerVitesse.h"
#include "commands/pince/ChangerPositionPince.h"
#include "commands/pince/AttraperObjet.h"
#include "commands/pince/EjecterObjet.h"
#include "commands/pivot/SetSetpointPivot.h"
#include "commands/elevateur/MonterRobot.h"
#include "commands/elevateur/MonterRouesArrieres.h"
#include "commands/elevateur/MonterRouesAvant.h"

#include "Robot.h"


OI::OI()
{
  m_button1.WhenPressed(new ChangerVitesse());
  m_button2.WhenPressed(new ChangerPositionPince());
  m_button3.WhenPressed(new AttraperObjet());
  m_button4.WhenPressed(new EjecterObjet());

  m_button5.WhenPressed(new SetSetpointPivot(Pivot::MILIEU));
  m_button7.WhenPressed(new SetSetpointPivot(Pivot::BATEAU_CARGO_AVANT));
  m_button8.WhenPressed(new SetSetpointPivot(Pivot::BATEAU_CARGO_ARRIERE));
  m_button9.WhenPressed(new SetSetpointPivot(Pivot::HATCH_AVANT));
  m_button10.WhenPressed(new SetSetpointPivot(Pivot::HATCH_ARRIERE));
  m_button11.WhenPressed(new SetSetpointPivot(Pivot::CARGO_AVANT));
  m_button12.WhenPressed(new SetSetpointPivot(Pivot::CARGO_ARRIERE));

  m_button1Joystick2.WhileActive(new MonterRobot());
  m_button3Joystick2.WhileActive(new MonterRouesArrieres());
  m_button5Joystick2.WhileActive(new MonterRouesAvant());
}

frc::Joystick& OI::GetJoystick1()
{
   return m_joystick1;
}

frc::Joystick& OI::GetJoystick2()
{
   return m_joystick2;
}