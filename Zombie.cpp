#include "Zombie.h"

  // Name: Zombie() - Default Constructor
  // Description: Would be used to create a zombie but abstracted
  // Preconditions: None
  // Postconditions: Used to populate child class data
Zombie::Zombie()
{

}

  // Name: Zombie(string name, int hp) - Overloaded Constructor
  // Description: Would be used to create a zombie but abstracted
  // Preconditions: None
  // Postconditions: Used to populate child class data
Zombie::Zombie(string name, int health)
{
  SetName(name);
  SetHealth(health);
}

  // Name: Attack()
  // Description: Describes attack statements for zombie
  // Preconditions: None
  // Postconditions: Returns damage
int Zombie::Attack()
{
  int damage = 1;
  
  return damage;
}

  // Name: SpecialAttack()
  // Description: Purely virtual SpecialAttack
  // Preconditions: None
  // Postconditions: May be used to call child class SpecialAttack
//int Zombie::SpecialAttack()=0;
