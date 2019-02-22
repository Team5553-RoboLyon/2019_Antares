#include "Robot.h"

#include <thread>
#include <opencv2/opencv.hpp>
#include <cscore.h>


OI Robot::m_oi;

BaseRoulante Robot::m_baseRoulante;
Elevateur Robot::m_elevateur; 
Pince Robot::m_pince;
Pivot Robot::m_pivot;

void Robot::RetourVideo()
{
  // Création de la caméra usb + propriétés
  cv::VideoCapture camera(0);
	camera.set(cv::CAP_PROP_BRIGHTNESS, 0);
  camera.set(cv::CAP_PROP_FRAME_WIDTH, 320);
	camera.set(cv::CAP_PROP_FRAME_HEIGHT, 240);
	camera.set(cv::CAP_PROP_FPS, 30);

  // Objet pour pouvoir streamer l'image de la caméra
  cs::CvSource outputStream = frc::CameraServer::GetInstance()->PutVideo("Pince Arriere", 320, 240);

  // La Mat pour stocker l'image
  cv::Mat source;

  // On attend que la caméra soit detectée
  while(camera.read(source) == 0) {}

  while(true)
  {
    // On récupère l'image de la caméra
    camera.read(source);
    
    // Si le pivot est à l'envers on retourne l'image
    if(m_pivot.GetSetpoint() < 0)
    {
      cv::flip(source, source, -1);
    }

    // On stream l'image modifiée
    outputStream.PutFrame(source);
  }
}

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

  // Thread pour le retour video du pilote
  std::thread RetourVideoThread(RetourVideo);
  RetourVideoThread.detach();
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

void Robot::AutonomousInit()
{
  //m_autoCommand.Start();
}

void Robot::AutonomousPeriodic() {frc::Scheduler::GetInstance()->Run();}

void Robot::TeleopInit()
{
  //m_autoCommand.Cancel();
}

void Robot::TeleopPeriodic() {frc::Scheduler::GetInstance()->Run();}

void Robot::TestPeriodic() {}


#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
