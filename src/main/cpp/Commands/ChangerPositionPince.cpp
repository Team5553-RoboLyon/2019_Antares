#include "commands/ChangerPositionPince.h"

ChangerPositionPince::ChangerPositionPince()
{
  Requires(&Robot::m_pince);
}

void ChangerPositionPince::Initialize()
{
  Robot::m_pince.ChangerPosition();
}
