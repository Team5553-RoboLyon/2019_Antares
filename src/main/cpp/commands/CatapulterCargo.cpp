#include "commands/CatapulterCargo.h"
#include "Robot.h"
#include <math.h>
#include <iostream>

CatapulterCargo::CatapulterCargo()
{
  Requires(&Robot::m_pince);
  Requires(&Robot::m_pivot);
}

void CatapulterCargo::Initialize()
{
  Robot::m_pivot.SetSetpoint(Robot::m_pivot.CARGO_AVANT);
}

void CatapulterCargo::Execute()
{
  double Vy = (sin(Robot::m_pivot.GetAngleRad()) * m_vitesseEjection) + (sin(Robot::m_pivot.GetAngleRad() - M_PI_2) * m_vitesseTangentielle);
  double Vx = (cos(Robot::m_pivot.GetAngleRad()) * m_vitesseEjection) + (cos(Robot::m_pivot.GetAngleRad() - M_PI_2) * m_vitesseTangentielle) + m_vitesseBase;

  double a = -9.81/2;
  double b = cos(atan(Vy/Vx)) * sqrt(pow(m_vitesseEjection, 2) + pow(m_vitesseTangentielle, 2) + pow(m_vitesseBase, 2));
  double c = sin(atan(Vy/Vx)) * sqrt(pow(m_vitesseEjection, 2) + pow(m_vitesseTangentielle, 2) + pow(m_vitesseBase, 2)) + cos(Robot::m_pivot.GetAngleRad()) * m_longueur + sin(Robot::m_pivot.GetAngleRad()) * m_longueur - m_distance - m_hauteur;

  double discriminant = pow(b, 2) -4 * a * c;

  if(discriminant < 0)
  {
    std::cout << "T'es niqué" << std::endl;
    m_trinomeResolu = false;
  }
  else
  {
    m_racines[0] = (-b - sqrt(discriminant))/(2*a);
    m_racines[1] = (-b + sqrt(discriminant))/(2*a);
    m_trinomeResolu = true;
  }

  if(m_trinomeResolu)
  {
    double yBalle1, yBalle2, vyBalle;

    double deltaT = 0.2;

    yBalle2 = (-9.81/2) * pow(m_racines[1], 2) + sin(atan(Vy/Vx)) * sqrt(pow(m_vitesseEjection, 2) + pow(m_vitesseTangentielle, 2) + pow(m_vitesseBase, 2));
    yBalle1 = (-9.81/2) * pow(m_racines[1] - deltaT, 2) + sin(atan(Vy/Vx)) * sqrt(pow(m_vitesseEjection, 2) + pow(m_vitesseTangentielle, 2) + pow(m_vitesseBase, 2));

    vyBalle = yBalle2 - yBalle1;

    if(abs(sin(vyBalle)) < 0.25)
    {
      Robot::m_pince.EjecterCargo();
    }
  }
}

bool CatapulterCargo::IsFinished() { return false; }

void CatapulterCargo::End() {}

void CatapulterCargo::Interrupted() {}
