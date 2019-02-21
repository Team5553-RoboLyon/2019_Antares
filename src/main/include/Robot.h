#pragma once

#include <frc/WPILib.h>

#include "OI.h"

#include "subsystems/BaseRoulante.h"
#include "subsystems/Elevateur.h"
#include "subsystems/Pince.h"
#include "subsystems/Pivot.h"

#include "commands/baseRoulante/FaireUneSplineStylee.h"

class Robot : public frc::TimedRobot
{
 public:
  static OI m_oi;

  static BaseRoulante m_baseRoulante;
  static Elevateur m_elevateur;
  static Pince m_pince;
  static Pivot m_pivot;

  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  frc::PowerDistributionPanel m_pdp{0};
  FaireUneSplineStylee m_autoCommand;
  static void RetourVideo();
};
