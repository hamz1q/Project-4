#include "Imp.h"

  // Name: Imp() - Default Constructor
  // Description: Creates a new imp
  // Preconditions: None
  // Postconditions: Can create an imp
Imp::Imp()
{

}

  // Name:  Imp(string name, int hp)
  // Description: Creates a new  imp
  // Preconditions: None
  // Postconditions: Can create an imp
Imp::Imp(string name, int health)
{
  SetName(name);
  SetHealth(health);
}

  // Name: SpecialAttack
  // Description: Defines the Imp's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
int Imp::SpecialAttack()
{
  int damage = 4;

  cout << "Blasts you wth Impkata attack" << endl;
  return damage;
}
