#pragma once

#include <frc/commands/ConditionalCommand.h>


/**
 * Ejecte un Hatch si la pince est ouverte et un Cargo si elle est fermée
 * Cette command hérite de la classe Conditional Command :
 * - Dans le constructeur on donne les deux commands : OnTrue et OnFalse
 * - Selon ce qu'on return dans Condition(), l'une des deux est choisie
 */
class EjecterObjet : public frc::ConditionalCommand
{
 public:
  EjecterObjet();
  bool Condition() override;
};
