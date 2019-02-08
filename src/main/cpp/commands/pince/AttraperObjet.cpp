#include "commands/pince/AttraperObjet.h"
#include "commands/pince/AttraperCargo.h"
#include "commands/pince/AttraperHatch.h"
#include "Robot.h"


// Command OnTrue = AttraperHatch() et Command OnFalse = new AttraperCargo()
AttraperObjet::AttraperObjet() : frc::ConditionalCommand(new AttraperHatch(), new AttraperCargo())
{

}

// Fonction appelée pour savoir quelle command éxécuter
bool AttraperObjet::Condition()
{
  // Si la pince est ouverte alors il faut attraper un hatch
  // Si IsOuverte() return true alors on run la Command OnTrue = AttraperHatch()
  return Robot::m_pince.IsOuverte();
}