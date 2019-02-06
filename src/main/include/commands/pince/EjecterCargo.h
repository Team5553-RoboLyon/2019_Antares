#pragma once

#include <frc/commands/TimedCommand.h>
#include "Robot.h"

/**
 * Ejecte le cargo en faisant tourner les roues de la pince
 * Fin au bout de x secondes
 */
class EjecterCargo : public frc::TimedCommand
{
 public:
  explicit EjecterCargo();
  void Initialize() override;
  void Execute() override;
  void End() override;
  void Interrupted() override;
};
