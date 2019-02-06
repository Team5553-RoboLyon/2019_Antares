#include "commands/ChangerPositionPince.h"

ChangerPositionPince::ChangerPositionPince()
{
  Requires(&Robot::m_pince);
}

void ChangerPositionPince::Initialize()
{
  Robot::m_pince.RentrerPistons();
  Robot::m_pince.ChangerPosition();

  if(Robot::m_pince.IsOuverte())
  {
    // On se prépare à attraper un hatch en fermant la petite pince
    Robot::m_pince.RelacherHatch();
  }
  else
  {
    // On se prépare à attraper un cargo en ouvrant la petite pince
    Robot::m_pince.AttraperHatch();
  }
}
