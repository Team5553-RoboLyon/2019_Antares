#include "Commands/SetSetpointPivot.h"

SetSetpointPivot::SetSetpointPivot(double setpoint)
{
  Requires(&Robot::m_pivot);
  m_setpoint = setpoint;
}

void SetSetpointPivot::Initialize()
{
  Robot::m_pivot.SetSetpoint(m_setpoint);
}

// Rien à faire le pivot fait tout tout seul
void SetSetpointPivot::Execute() {}

bool SetSetpointPivot::IsFinished()
{
  return Robot::m_pivot.OnTarget();
}

void SetSetpointPivot::End() {}

void SetSetpointPivot::Interrupted() {}
