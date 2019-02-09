#include "commands/pince/EjecterHatch.h"
#include "Robot.h"

EjecterHatch::EjecterHatch() : TimedCommand(0.5)
{
  Requires(&Robot::m_pince);
}

void EjecterHatch::Initialize()
{
  Robot::m_pince.RelacherHatch();
}

void EjecterHatch::Execute()
{
  //Aprés 0.1 seconde on sort les pistons
  if(TimeSinceInitialized() > 0.1)
    Robot::m_pince.SortirPistons();
}

void EjecterHatch::End()
{
  Robot::m_pince.RentrerPistons();
}

void EjecterHatch::Interrupted()
{
  End();
}
