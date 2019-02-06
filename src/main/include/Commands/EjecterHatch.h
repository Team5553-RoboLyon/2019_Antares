#pragma once

#include <frc/commands/TimedCommand.h>
#include "Robot.h"

/**
 * Ejecte un hatch en le relachant et en sortant les pistons
 * Fin au bout de x secondes
 * A la fin, les pistons sont rentrés
 */
class EjecterHatch : public frc::TimedCommand
{
 public:
  explicit EjecterHatch();
  void Initialize() override;
  void Execute() override;
  void End() override;
  void Interrupted() override;
};
