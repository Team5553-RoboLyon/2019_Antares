#pragma once

#include <frc/commands/InstantCommand.h>

/**
 * Change la position du ballshifter
 * Fin instantanée
 */
class ChangerVitesse : public frc::InstantCommand
{
 public:
  ChangerVitesse();
  void Initialize() override;
};
