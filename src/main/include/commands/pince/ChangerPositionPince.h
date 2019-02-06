#pragma once

#include <frc/commands/InstantCommand.h>

/**
 * Change la position de la pince : ouverte / fermée
 * Rentre les pistons
 * Change la position de l'attrape-hatch
 * Fin instantanée
 */
class ChangerPositionPince : public frc::InstantCommand
{
 public:
  ChangerPositionPince();
  void Initialize() override;
};
