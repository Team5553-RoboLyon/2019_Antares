#include "commands/EjecterHatch.h"

EjecterHatch::EjecterHatch() : TimedCommand(0.5)
{
  Requires(&Robot::m_pince);
}

void EjecterHatch::Initialize()
{
  Robot::m_pince.RelacherHatch();
  Robot::m_pince.SortirPistons();
}

void EjecterHatch::Execute() {}

void EjecterHatch::End()
{
  Robot::m_pince.RentrerPistons();
}

void EjecterHatch::Interrupted()
{
  End();
}
