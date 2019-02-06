#pragma once

#include <frc/commands/TimedCommand.h>

/**
 * Attrape le cargo en faisant tourner les roues de la pince
 * Fin au bout de x secondes
 */
class AttraperCargo : public frc::TimedCommand
{
 public:
  explicit AttraperCargo();
  void Initialize() override;
  void Execute() override;
  void End() override;
  void Interrupted() override;
};
