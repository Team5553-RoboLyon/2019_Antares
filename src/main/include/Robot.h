#pragma once

#include <frc/WPILib.h>
#include <ctre/Phoenix.h>

#include "Input.h"
#include "Output.h"

#include "subsystems/BaseRoulante.h"
#include "subsystems/Bras.h"
#include "subsystems/Elevateur.h"
#include "subsystems/Pince.h"
#include "subsystems/Pivot.h"

class Robot : public frc::TimedRobot
{
 public:
  static Input m_input;
  static Output m_output;

  static BaseRoulante m_baseRoulante;
  static Bras m_bras;
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
  
};
