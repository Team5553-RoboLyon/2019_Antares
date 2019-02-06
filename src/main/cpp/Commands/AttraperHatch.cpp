#include "commands/AttraperHatch.h"

AttraperHatch::AttraperHatch()
{
  Requires(&Robot::m_pince);
}

void AttraperHatch::Initialize()
{
  Robot::m_pince.AttraperHatch();
}
