#include "commands/baseRoulante/FaireUneSplineStylee.h"
#include "Robot.h"

#include <iostream>
#include <string>

FaireUneSplineStylee::FaireUneSplineStylee()
{
  Requires(&Robot::m_baseRoulante);
}

void FaireUneSplineStylee::Initialize()
{
  // Inversion des trajectoires car bug de PathWeaver
  FILE *fileDroite = fopen( "/home/lvuser/deploy/output/path.left.pf1.csv", "r");
  int length = pathfinder_deserialize_csv(fileDroite, m_trajectoireDroite);
  fclose(fileDroite);

  FILE *fileGauche = fopen( "/home/lvuser/deploy/output/path.right.pf1.csv", "r");
  m_trajectory_length = pathfinder_deserialize_csv(fileGauche, m_trajectoireGauche);
  fclose(fileGauche);

  *m_encoderConfigDroite = { Robot::m_baseRoulante.GetTicksDroite(), 20*12, 0.155 * M_PI, 0.5, 0.0, 0.0, 1.0 / 3.5, 0.0};
  *m_encoderConfigGauche = { Robot::m_baseRoulante.GetTicksGauche(), 20*12, 0.155 * M_PI, 0.5, 0.0, 0.0, 1.0 / 3.5, 0.0};

  m_followerDroite->last_error = 0; m_followerDroite->segment = 0; m_followerDroite->finished = 0;
  m_followerGauche->last_error = 0; m_followerGauche->segment = 0; m_followerGauche->finished = 0;
}

void FaireUneSplineStylee::Execute()
{
  double puissanceDroite = pathfinder_follow_encoder(*m_encoderConfigDroite, m_followerDroite, m_trajectoireDroite, m_trajectory_length, Robot::m_baseRoulante.GetTicksDroite());
  double puissanceGauche = pathfinder_follow_encoder(*m_encoderConfigGauche, m_followerGauche, m_trajectoireGauche, m_trajectory_length, Robot::m_baseRoulante.GetTicksGauche());

  // Prendre en compte l'angle aussi
  double heading = Robot::m_baseRoulante.GetAngle();
  double desired_heading = r2d(m_followerDroite->heading);
  double heading_difference = desired_heading - heading;
  double turn =  0.8 * (-1.0/80.0) * heading_difference;

  puissanceDroite += turn;
  puissanceGauche -= turn;
  
  std::cout << "Droite : " << puissanceDroite << "    Gauche : " << puissanceGauche << std::endl;
  Robot::m_baseRoulante.Drive(puissanceGauche, puissanceDroite);
}

bool FaireUneSplineStylee::IsFinished() { return false; }

void FaireUneSplineStylee::End() {}

void FaireUneSplineStylee::Interrupted() {}
