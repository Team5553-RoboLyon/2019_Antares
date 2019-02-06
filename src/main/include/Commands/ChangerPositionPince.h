#pragma once

#include <frc/commands/InstantCommand.h>
#include "Robot.h"

/**
 * Change la position de la pince : ouverte / fermée
 * Fin instantanée
 */
class ChangerPositionPince : public frc::InstantCommand
{
 public:
  ChangerPositionPince();
  void Initialize() override;
};
