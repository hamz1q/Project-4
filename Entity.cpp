#include "Entity.h"

  // Name: Entity() - Default Constructor
  // Description: Abstract class - cannot directly instantiate this class
  // Preconditions: None
  // Postconditions: Populates variables used in child classes (not specifically used)
Entity:: Entity()
{

}

  // Name: Entity(string, int) - Overloaded Constructor
  // Description: Abstract class - cannot directly instantiate this class
  // Preconditions: None
  // Postconditions: Populates variables used in child classes
Entity:: Entity(string name, int health)
{
  SetName(name);
  SetHealth(health);
}

  // Name: virtual ~Entity - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
Entity::~Entity()
{

}

  // Name: GetName()
  // Description: Returns name of entity
  // Preconditions: Entity has name
  // Postconditions: None
string Entity::GetName()
{
  return m_name;
}

  // Name: GetHealth()
  // Description: Returns health of entity
  // Preconditions: Entity has health
  // Postconditions: None
int Entity::GetHealth()
{
  return m_health;
}

  // Name: SetName()
  // Description: Sets name of entity
  // Preconditions: None
  // Postconditions: Name is set
void Entity::SetName(string name)
{
  m_name = name;
}

  // Name: SetHealth()
  // Description: Sets health of entity
  // Preconditions: None
  // Postconditions: Health is set
void Entity::SetHealth(int health)
{
  m_health = health;
}

  // Name: Attack()
  // Description: Defines attack for an entity
  // Preconditions: None
  // Postconditions: None (Purely virtual - must be in child classes)
//int Entity::Attack() = 0;

  // Name: SpecialAttack()
  // Description: Defines special attack for an entity
  // Preconditions: None
  // Postconditions: None (Purely virtual - must be in child classes)
//int Entity::SpecialAttack() = 0;

   // Name: Overloaded <<
  // Description: Prints the details of an entity
  // Preconditions: all variables are set valid
  // Postconditions: returns an ostream with output of entity
//friend ostream& operator<<(ostream&, Entity&);

//GO OVER LATER ^
