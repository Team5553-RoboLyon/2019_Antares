#pragma once

#include <frc/commands/Command.h>


/*
 * Augmente ou diminue la position du pivot
 * - Ajoute 1.5° si le POV est vers le haut
 * - Enlève 1.5° si le POV est vers le bas
 * Pas de fin
 */
class AjusterPivot: public frc::Command
{
public:
  AjusterPivot();

  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

private:
  int m_pov;
};
