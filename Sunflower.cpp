#include "Sunflower.h"

  // Name: Sunflower() - Default Constructor
  // Description: Creates a new sunflower
  // Preconditions: None
  // Postconditions: Can create a sunflower
Sunflower::Sunflower()
{

}

  // Name: Sunflower(string name, int hp)
  // Description: Creates a new sunflower
  // Preconditions: None
  // Postconditions: Can create a sunflower
Sunflower::Sunflower(string name, int health)
{
  SetName(name);
  SetHealth(health);
}

  // Name: ~Sunflower - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
Sunflower::~Sunflower()
{

}

  // Name: SpecialAttack
  // Description: Defines the Sunflower's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
int Sunflower::SpecialAttack()
{
  int upper = 8;
  int lower = 1;
  int damage = (rand() % (upper - lower + 1)) + lower;

  cout << "Uses a high beam turrent. SUNBEAM!" << endl;
  return damage;
}
