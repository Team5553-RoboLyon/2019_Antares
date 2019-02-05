#include "subsystems/Pivot.h"

Pivot::Pivot() : PIDSubsystem("Pivot", 1.0, 0.0, 0.0)
{
   GetPIDController()->SetName("Pivot", "PIDSubsystem Controller");

  // Ratio pour convertir les ticks de l'encodeur en degrés
  m_encodeur.SetDistancePerPulse(m_angleParTick);

  // Interdit les setpoints en dehors de [-90°; 90°]
  SetInputRange(-90.0, 90.0);

  // En dessous de 5° de la cible, celle-ci sera considérée comme OnTarget par le bras
  SetAbsoluteTolerance(5.0);

  // Set where the PID controller should move the system to and enable the PID controller
  SetSetpoint(0);
  Enable();

  // Permet d'afficher des infos sur le pivot dans le shuffleboard
  AddChild("Moteur", m_moteur);
  AddChild("Encodeur", m_encodeur);
}

double Pivot::ReturnPIDInput()
{
  // Return your input value for the PID loop
  return m_encodeur.GetDistance();
}

void Pivot::UsePIDOutput(double output)
{
  // Conversion de l'angle du pivot en radians
  double angleEnRadians = Deg2rad(m_encodeur.GetDistance());

  /**
  * Calcul de la force de gravité sur le bras du pivot
  * Elle est proportionelle à "l'abscisse" du bras
  * 
  * %%% -> sin (pi/2) = 1
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
  * %%% -> sin (-pi/2) = -1
  * 
  * Quand on renverse le cercle trigonométrique,
  * on retrouve bien la configuration du pivot
  */
  double gravite = m_coefGravite * sin(angleEnRadians);

  // On ajoute le terme au PID pour contrer la gravité
  m_moteur.Set(output + gravite);
}

void Pivot::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}
