#include "commands/baseRoulante/ChangerVitesse.h"
#include "Robot.h"

ChangerVitesse::ChangerVitesse()
{
  Requires(&Robot::m_baseRoulante);
}

void ChangerVitesse::Initialize()
{
  Robot::m_baseRoulante.ChangerVitesse();
}
