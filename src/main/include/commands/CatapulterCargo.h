#pragma once

#include <frc/commands/Command.h>

class CatapulterCargo : public frc::Command
{
 private:
  double m_distance, m_vitesseEjection, m_vitesseBase, m_vitesseTangentielle, m_hauteur;
  double m_longueur = 0.8;
  double m_racines[2];
  bool m_trinomeResolu;

 public:
  CatapulterCargo();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;
};
