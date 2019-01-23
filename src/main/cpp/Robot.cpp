#include "Robot.h"


Input Robot::m_input;
Output Robot::m_output;

BaseRoulante Robot::m_baseRoulante;
Bras Robot::m_bras;
Elevateur Robot::m_elevateur;
Pince Robot::m_pince;
Pivot Robot::m_pivot;


void Robot::RobotInit() {}

void Robot::RobotPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {frc::Scheduler::GetInstance()->Run();}

void Robot::AutonomousInit() {}

void Robot::AutonomousPeriodic() {frc::Scheduler::GetInstance()->Run();}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {frc::Scheduler::GetInstance()->Run();}

void Robot::TestPeriodic() {}


#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
