#include "Buckethead.h"

    // Name: Buckethead() - Default Constructor
    // Description: Creates a new buckethead type of zombie
    // Preconditions: None
    // Postconditions: Can create a buckethead
Buckethead:: Buckethead()
{

}
    // Name: Buckethead(string name, int hp)
    // Description: Creates a new buckethead
    // Preconditions: None
    // Postconditions: Can create a buckethead
Buckethead:: Buckethead(string name, int health)
{
  SetName(name);
  SetHealth(health);
}
    // Name: SpecialAttack
    // Description: Defines the Buckethead's special attack
    // Preconditions: None
    // Postconditions: Returns damage from special attack
int Buckethead::SpecialAttack()
  {
    int damage = 1;

    cout << "Throws its bucket at you!" << endl;
    return damage;
  }

