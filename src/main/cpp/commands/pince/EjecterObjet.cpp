#include "commands/pince/EjecterObjet.h"
#include "commands/pince/EjecterCargo.h"
#include "commands/pince/EjecterHatch.h"
#include "Robot.h"


// Command OnTrue = EjecterHatch() et Command OnFalse = new EjecterCargo()
EjecterObjet::EjecterObjet() : frc::ConditionalCommand(new EjecterHatch(), new EjecterCargo())
{

}

// Fonction appelée pour savoir quelle command éxécuter
bool EjecterObjet::Condition()
{
  // Si la pince est ouverte alors il faut attraper un hatch
  // Si IsOuverte() return true alors on run la Command OnTrue = AttraperHatch()
  return Robot::m_pince.IsOuverte();
}