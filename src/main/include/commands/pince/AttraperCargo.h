#pragma once

#include <frc/commands/TimedCommand.h>
#include <frc/Timer.h>

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
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

 private:
  frc::Timer m_timer;
};
