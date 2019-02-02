#include "subsystems/BaseRoulante.h"

BaseRoulante::BaseRoulante() : Subsystem("BaseRoulante") {}

void BaseRoulante::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void BaseRoulante::Periodic()
{

} 

void BaseRoulante::Drive (double gauche, double droite)
{

}

void BaseRoulante::ChangerVitesse ()
{

}

void BaseRoulante::ActiverVitesse1 ()
{

}

void BaseRoulante::ActiverVitesse2 ()
{
  
}

void BaseRoulante::GetEncodeur ()
{
  
}

void BaseRoulante::ResetPID ()
{

}