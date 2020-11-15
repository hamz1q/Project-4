#include "Engineer.h"

  // Name: Engineer() - Default Constructor
  // Description: Creates a new engineer
  // Preconditions: None
  // Postconditions: Can create a engineer
Engineer::Engineer()
{

}

  // Name: Engineer(string name, int hp)
  // Description: Creates a new engineer
  // Preconditions: None
  // Postconditions: Can create a engineer
Engineer::Engineer(string name, int health)
{
  SetName(name);
  SetHealth(health);
}

  // Name: SpecialAttack
  // Description: Defines the Engineer's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
int Engineer::SpecialAttack()
{
  int damage = 2;

  cout << "Blasts you with SteamBlaster!" << endl;
  return damage;
}
