#pragma once

#include <frc/commands/InstantCommand.h>
#include "Robot.h"

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
