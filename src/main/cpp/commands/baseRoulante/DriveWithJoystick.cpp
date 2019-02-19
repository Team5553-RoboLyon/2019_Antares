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
  double y = -Robot::m_oi.GetJoystick().GetY();
  double z = -Robot::m_oi.GetJoystick().GetZ();

  // Si les valeurs lues sont trop petites, on les considères comme nulles
	if (abs(y) < 0.15)
		y = 0.0;
  
	if (abs(z) < 0.25)
		z = 0.0;

  //La "formule" pour calculer la vitesse de chaque moteur
	double vitesseGauche = y - 0.5 * z;
	double vitesseDroite = y + 0.5 * z;

  // Exponentielle pour baisser les valeurs basses et laisser les valeurs hautes hautes
  if(vitesseGauche > 0)
    vitesseGauche = (exp(vitesseGauche)-1) * 0.58;
  else
    vitesseGauche = -(exp(abs(vitesseGauche))-1) * 0.58;
    
  if(vitesseDroite > 0)
    vitesseDroite = (exp(vitesseDroite)-1) * 0.58;
  else
    vitesseDroite = -(exp(abs(vitesseDroite))-1) * 0.58;

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
