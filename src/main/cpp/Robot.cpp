#include "Robot.h"


OI Robot::m_oi;

BaseRoulante Robot::m_baseRoulante;
Elevateur Robot::m_elevateur; 
Pince Robot::m_pince;
Pivot Robot::m_pivot;


void Robot::RobotInit()
{
  // Affiche les commandes en cours d'éxécution de chaque subsystem
  frc::SmartDashboard::PutData(&m_baseRoulante);
  frc::SmartDashboard::PutData(&m_elevateur);
  frc::SmartDashboard::PutData(&m_pince);
  frc::SmartDashboard::PutData(&m_pivot);

  // Affiche le courant de chaque moteur branché sur le PDP
  frc::SmartDashboard::PutData(&m_pdp);

  // Initialisation de la pneumatique
  m_baseRoulante.ActiverVitesse1();
  m_pince.Ouvrir();
  m_pince.RentrerPistons();
  m_pince.AttraperHatch();
}

void Robot::RobotPeriodic()
{
  // Affichage de toutes les infos des subsystems
  m_baseRoulante.Log();
  m_elevateur.Log();
  m_pince.Log();
  m_pivot.Log();
}

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
