#include "subsystems/Pivot.h"
#include <frc/smartdashboard/SmartDashboard.h>

Pivot::Pivot() : PIDSubsystem("Pivot", 0.015, 0.0, 0.0)
{
  m_vitessePrecedente = 0.0;

  GetPIDController()->SetName("Pivot", "PIDSubsystem Controller");

  // Interdit les setpoints en dehors de [-90°; 90°]
  SetInputRange(-90.0, 90.0);

  // En dessous de 5° de la cible, celle-ci sera considérée comme OnTarget par le bras
  SetAbsoluteTolerance(5.0);

  // Set where the PID controller should move the system to and enable the PID controller
  SetSetpoint(0.0);
  Enable();
}

void Pivot::Periodic()
{
  frc::SmartDashboard::PutNumber("Angle Pivot", GetAngle());
  frc::SmartDashboard::PutNumber("Moteur Pivot", m_moteur.Get());
}

double Pivot::GetAngle()
{
  // Ratio pour convertir les ticks de l'encodeur en degrés
  return m_encodeur.GetPosition() * m_angleParTick;
}

double Pivot::Rampe(double vitesse)
{
  if(vitesse > 0 && vitesse > m_vitessePrecedente + m_maxAcceleration)
  {
    vitesse = m_vitessePrecedente + m_maxAcceleration;
  }
  else if(vitesse < 0 && vitesse < m_vitessePrecedente - m_maxAcceleration)
  {
    vitesse = m_vitessePrecedente - m_maxAcceleration;
  }

  m_vitessePrecedente = vitesse;

  return vitesse;  
}

double Pivot::ReturnPIDInput()
{
  return GetAngle();
}

void Pivot::UsePIDOutput(double output)
{
  // Conversion de l'angle du pivot en radians
  double angleEnRadians = Deg2rad(GetAngle());

  /**
  * Calcul de la force de gravité sur le bras du pivot
  * Elle est proportionelle à "l'abscisse" du bras
  * 
  * %%% -> sin (90°) = 1
  * |    %%%
  * |       %%
  * |         %%
  * |           %%
  * |           %%%
  * |------------%% -> sin (0) = 0
  * |           %%%
  * |          %%
  * |         %%
  * |       %%
  * |    %%%
  * %%% -> sin (-90°) = -1
  * 
  * Quand on renverse le cercle trigonométrique,
  * on retrouve bien la configuration du pivot
  */
  double gravite = m_coefGravite * -sin(angleEnRadians);

  // On additionne les deux termes et on réduit l'accéleration
  double vitesse = Rampe(output + gravite);

  // On ajoute le terme au PID pour contrer la gravité
  m_moteur.Set(vitesse);
}

void Pivot::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}
