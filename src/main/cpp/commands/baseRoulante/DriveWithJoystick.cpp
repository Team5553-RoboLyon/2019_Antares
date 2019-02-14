#include "commands/baseRoulante/DriveWithJoystick.h"
#include "Robot.h"
#include <math.h>

DriveWithJoystick::DriveWithJoystick()
{
  Requires(&Robot::m_baseRoulante);
}

void DriveWithJoystick::Initialize() {}

void DriveWithJoystick::Execute()
{
  // On récupère les valeurs du joystick
  double y = Robot::m_oi.GetJoystick().GetY();
  double z = Robot::m_oi.GetJoystick().GetZ();

  // Si les valeurs lues sont trop petites, on les considères comme nulles
	if (abs(y) < 0.2)
		y = 0.0;
  
	if (abs(z) < 0.2)
		z = 0.0;

  //La "formule" pour calculer la vitesse de chaque moteur
	double vitesseGauche = 0.7 * (y - 0.5 * z);
	double vitesseDroite = 0.7 * (y + 0.5 * z);

	//On utilise la fonction membre du subsystem BaseRoulante
	Robot::m_baseRoulante.Drive(vitesseGauche, vitesseDroite);
}

bool DriveWithJoystick::IsFinished()
{
  return false;
}

void DriveWithJoystick::End()
{
  Robot::m_baseRoulante.Stop();
}

void DriveWithJoystick::Interrupted()
{
  End();
}
