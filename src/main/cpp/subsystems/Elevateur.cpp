#include "subsystems/Elevateur.h"
#include "commands/elevateur/DeplacerRobot.h"

Elevateur::Elevateur() : Subsystem("Elevateur") {}

void Elevateur::InitDefaultCommand()
{
  SetDefaultCommand(new DeplacerRobot());
}

void Elevateur::Log() {}

void Elevateur::SetMoteurAvant(double vitesse)
{
  m_moteurAvant.Set(vitesse);
}

void Elevateur::SetMoteurArriere(double vitesse)
{
  m_moteurArriere.Set(vitesse);
}

void Elevateur::SetRoues(double vitesse)
{
  m_roues.Set(vitesse);
}