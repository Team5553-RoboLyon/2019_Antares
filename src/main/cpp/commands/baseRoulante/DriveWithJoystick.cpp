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
  double y = -Robot::m_oi.GetJoystick1().GetY();
  double z = -Robot::m_oi.GetJoystick1().GetZ();

  // Si les valeurs lues sont trop petites, on les considères comme nulles
	if (abs(y) < 0.15)
		y = 0.0;
  
	if (abs(z) < 0.25)
		z = 0.0;

  // Exponentielle pour baisser les valeurs basses et laisser les valeurs hautes hautes
  if(y > 0)
    y = (exp(y)-1) * 0.58;
  else
    y = -(exp(abs(y))-1) * 0.58;

  // Fonction carrée pour baisser les valeurs basses et laisser les valeurs hautes hautes
  z = z * abs(z);

  //La "formule" pour calculer la vitesse de chaque moteur
	double vitesseGauche = y - 0.5 * z;
	double vitesseDroite = y + 0.5 * z;

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
