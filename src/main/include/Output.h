#pragma once

#include <frc/WPILib.h>
#include "Robot.h"

class Output
{
 public:
  Output();

 private:
  frc::ShuffleboardTab& m_baseRoulanteTab = frc::Shuffleboard::GetTab("BaseRoulante");
  frc::ShuffleboardTab& m_brasTab = frc::Shuffleboard::GetTab("Bras");
  frc::ShuffleboardTab& m_elevateurTab = frc::Shuffleboard::GetTab("Elevateur");
  frc::ShuffleboardTab& m_pinceTab = frc::Shuffleboard::GetTab("Pince");
  frc::ShuffleboardTab& m_pivotTab = frc::Shuffleboard::GetTab("Pivot");
};
