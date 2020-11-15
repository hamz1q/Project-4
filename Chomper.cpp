#include "Chomper.h"

  // Name: Chomper() - Default Constructor
  // Description: Creates a new chomper
  // Preconditions: None
  // Postconditions: Can create a chomper
Chomper::Chomper()
{

}

  // Name: Chomper(string name, int hp)
  // Description: Creates a new chomper
  // Preconditions: None
  // Postconditions: Can create a chomper
Chomper::Chomper(string name, int health)
{
  SetName(name);
  SetHealth(health);
}

  // Name: ~Chomper - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
Chomper::~Chomper()
{
  
}

  // Name: SpecialAttack
  // Description: Defines the Chomper's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
int Chomper::SpecialAttack()
{
  int upper = 12;
  int lower = 2;
  int damage = (rand() % (upper - lower + 1)) + lower;

  cout << "Performs a sneak attack. CHOMP!" << endl;
  return damage;
}
