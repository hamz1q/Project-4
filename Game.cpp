/*
- Hamza Qureshi
-11/12/2020
-CMSC 202 Proj4

 */
#include "Game.h"

  // Name: Game() - Default Constructor
  // Description: Creates a new Game
  // Preconditions: None
  // Postconditions: After asking for a file name, loads map, creates char and starts.
Game::Game()
{

}

  // Name: Game(string filename) - Overloaded Constructor
  // Description: Creates a new Game
  // Preconditions: None
  // Postconditions: Uses filesname to LoadMap, calls createplant,
  //                 and sets both numRests and m_numSpecial using constants.
Game::Game(string file)
{
  LoadMap(file);
  PlantCreation();
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;
}

  // Name: ~Game
  // Description: Destructor
  // Preconditions: None
  // Postconditions: Deallocates anything dynamically allocated in Game
Game::~Game()
{
  if(m_curZombie != nullptr)
    {
      delete m_curZombie;
    }
  delete m_myPlant;
  for(unsigned int i = 0; i < m_myMap.size(); i++)
    {
      delete m_myMap.at(i);
    }
}

  // Name: LoadMap(string fileName)
  // Description: Dynamically creates rooms and inserts them into the m_myMap vector
  // Precondition: File contains map information
  // Postcondition: Map is populated with Room objects.
void Game::LoadMap(string file)
{
  string line;
  int count = 0;
  ifstream myFile;

  myFile.open(file);
  if(myFile.is_open())
    {
      while(getline(myFile, line))
	{
	  count += 1;
	}
    }
  myFile.close();

  if(count > 2)
    {
      count = count - 2;
    }
  
  vector <int> ID(count);
  vector <string> id(count);
  vector <string> name(count);
  vector <string> desc(count);
  vector <int> nID(count);
  vector <string> nid(count);
  vector <int> eID(count);
  vector <string> eid(count);
  vector <int> sID(count);
  vector <string> sid(count);
  vector <int> wID(count);
  vector <string> wid(count);
  
  myFile.open(file);
  if(myFile.is_open())
    {
      for(int i = 0; i <count; i++)
	{
	  getline(myFile, id.at(i), '|');
	  ID[i] = stoi(id.at(i));
	  getline(myFile, name.at(i), '|');
	  getline(myFile, desc.at(i), '|');
	  getline(myFile, nid.at(i), '|');
	  nID[i] = stoi(nid.at(i));
	  getline(myFile, eid.at(i), '|');
	  eID[i] = stoi(eid.at(i));
	  getline(myFile, sid.at(i), '|');
	  sID[i] = stoi(sid.at(i));
	  getline(myFile, wid.at(i));
	  wID[i] = stoi(wid.at(i));
	}
    }
  myFile.close();

  for(int i = 0; i < count; i++)
    {
      Room* newRm=new Room(ID.at(i),name.at(i),desc.at(i),nID.at(i),eID.at(i),sID.at(i),wID.at(i));
      m_myMap.push_back(newRm);
    }
  
}

  // Name: PlantCreation()
  // Description: Allows user to create a new plant (or child) to play with. May
  //              be either plant, sunflower, chomper, or peashooter.
  // Preconditions: None
  // Postconditions: m_myCharacter is populated
void Game::PlantCreation()
{
  string name;
  int selection = 0;

  cout << "Welcome to UMBC Adventure!" << endl;
  cout << "Plant Name: ";
  cin >> name;
  cout << endl;
  do{
    cout << "Select a class:" << endl;
    cout << "1. Peashooter" << endl;
    cout << "2. Chomper" << endl;
    cout << "3. Sunflower" << endl;
    cout << "4. No Class" << endl;
    cin >> selection;
    if(selection < 1 or selection > 4)
      {
	selection = 0;
      }
  }while(selection == 0);

  if(selection == 1)
    {
      m_myPlant = new Peashooter(name, PEASHOOTER_HEALTH);
    }
  else if(selection == 2)
    {
      m_myPlant = new Chomper(name, CHOMPER_HEALTH);
    }
  else if(selection == 3)
    {
      m_myPlant = new Sunflower(name, SUNFLOWER_HEALTH);
    }
  else
    {
      m_myPlant = new Plant(name, PLANT_HEALTH); //??
    }

  StartGame();
}

  // Name: StartGame()
  // Description: After LoadMap and CharacterCreation, current room
  //              is set (0 by default) and Action is called
  // Preconditions: LoadMap and CharacterCreation must have been completed
  // Postconditions: m_numRests, m_numSpecial and curRoom populated and action called
void Game::StartGame()
{
  m_curRoom = m_myMap.at(0)->GetID();
  Action();
}

  // Name: Action()
   // Description: Menu for game
  // Preconditions: Everything in start has been completed
  // Postconditions: Game continues until quit or player dies
void Game::Action()
{
  int choice = 0;
  
  m_myMap.at(m_curRoom)->PrintRoom();
  cout << endl;
  m_curZombie = RandomZombie();
  
  if(m_curZombie != nullptr)
    {
      if(m_curZombie->GetName() == "Engineer")
	{
	  cout << "A large zombie stands wearing khakis with a sign that says ENGINEER." << endl;
	}
      else if(m_curZombie->GetName() == "Buckethead")
	{
	  cout << "A buckethead zombie teaters here with a bucket on his head" << endl;
	}
      else if(m_curZombie->GetName() == "Imp")
	{
	  cout << "A dirty imp licks his lips and glares at you" << endl;
	}
    }
  else
    {
      cout << "It is peaceful here" << endl;
    }
  
  while(m_myPlant->GetHealth() > 0)
    {
      while(choice != 6)
	{
	  do
	    {
	      cout << "What would you like to do?" << endl;
	      cout << "1. Look" << endl;
	      cout << "2. Move" << endl;
	      cout << "3. Attack Zombie" << endl;
	      cout << "4. Rest" << endl;
	      cout << "5. Check Stats" << endl;
	      cout << "6. Quit" << endl;
	      cin >> choice;
	      cout << endl;
	    }while(choice < 1 and choice > 6);
	  
	  
	  switch(choice)
	    {
	    case 1:
	      m_myMap.at(m_curRoom)->PrintRoom();
	      break;
	    case 2:
	      Move();
	      break;
	    case 3:
	      Attack();
	      break;
	    case 4:
	      Rest();
	      break;
	    case 5:
	      Stats();
	      break;
	    case 6:
	      cout << "GoodBye!" << endl;
	    default:
	      break;
	    }
	}
    }
}

  // Name: RandomZombie()
  // Description: Used to randomly create a dynamically allocated zombie
  //              of Buckethead, Imp, or Engineer.
  // Preconditions: Has an entity pointer to hold zombie child
  // Postconditions: Returns object of type Buckethead, Imp, or Engineer
Entity* Game::RandomZombie()
{
  Entity* newZom;
  string curr[4] = {"Engineer", "Buckethead", "Imp", "Peaceful"};
  int ranIndex = rand() % 4;

  if(curr[ranIndex] == "Engineer")
    {
      newZom = new Engineer("Engineer", ENGINEER_HEALTH);
    }
  else if(curr[ranIndex] == "Buckethead")
    {
      newZom = new Buckethead("Buckethead", BUCKETHEAD_HEALTH);
    }
  else if(curr[ranIndex] == "Imp")
    {
      newZom = new Imp("Imp", IMP_HEALTH);
    }
  else if(curr[ranIndex] == "Peaceful")
    {
      newZom = nullptr;
    }

    return newZom;
}

  // Name: Rest
  // Description: If no zombies in current room, allows player to rest
  // Preconditions: Must be valid room with no zombies (room must exist) and have rests
  // Postconditions: Reduces available rests by one and increases hp by 10 REST_HEAL
void Game::Rest()
{
  if(m_curZombie == nullptr)
    {
      cout << "You rest and wake up refreshed" << endl;
      m_myPlant->SetHealth( m_myPlant->GetHealth() + 10);
      m_numRests = m_numRests - 1;
    }
  else if(m_numRests < 1)
    {
      cout << "Cannot rest! No more rests remaining" << endl;
    }
  else
    {
      cout << "Cannot Rest! " << m_curZombie->GetName() << " in room!" << endl;
    }
}

  // Name: Move
  // Description: Moves a player from one room to another (updates m_curRoom)
  // Preconditions: Must be valid move (room must exist)
  // Postconditions: Displays room information, checks for new zombie (deletes old)
void Game::Move()
{
  if(m_curZombie != nullptr)
    {
      delete m_curZombie;
    }
  m_curZombie = RandomZombie();
    
  char direction;
  bool move = true;
  while(move == true)
    {
      do
	{
	  cout << "Which Direction? (N E S W)" << endl;
	  cin >> direction;
	  if(cin.fail())
	    {
	      cout << "Invalid Choice! Must Choose N E S W" << endl;
	      cin.clear();
	      cin.ignore(256, '\n');
	    }
	  
	  if(m_myMap.at(m_curRoom)->CheckDirection(direction) != -1)
	    {
	      m_curRoom = m_myMap.at(m_curRoom)->CheckDirection(direction);
	      m_myMap.at(m_curRoom)->PrintRoom();
	      move = false;
	    }
	  else
	    {
	      cout << "Not an exit! Pick another direction." << endl;
	    }
	  
	}while(direction != 'n' and direction != 'N' and direction != 'e' and direction != 'E'
	       and direction != 's' and direction != 'S' and direction != 'w' and direction !='W');
    }

  if(m_curZombie != nullptr)
    {
      if(m_curZombie->GetName() == "Engineer")
	{
	  cout << "A large zombie stands wearing khakis with a sign that says ENGINEER." << endl;
	}
      else if(m_curZombie->GetName() == "Buckethead")
	{
	  cout << "A buckethead zombie teaters here with a bucket on his head" << endl;
	}
      else if(m_curZombie->GetName() == "Imp")
	{
	  cout << "A dirty imp licks his lips and glares at you" << endl;
	}
    }
  else
    {
      cout << "It is peaceful here" << endl;
    }
}
  
  // Name: Attack
  // Description: Allows player to attack an enemy entity.
  // Preconditions: Must have enemy zombie in room
  // Postconditions: Indicates who wins and updates health(hp) as battle continues.
  //                 May need to deallocate enemy zombie to prevent memory leaks.
void Game::Attack()
{
  int attack = 0;
  
  if(m_curZombie != nullptr)
    {
      while(m_myPlant->GetHealth()>0 and m_curZombie->GetHealth()>0)
	{
	  do
	    {
	      cout << "1. Normal Attack" << endl;
	      cout << "2. Special Attack" << endl;
	      cin >> attack;

	      if(attack == 1)
		{
		  int damage = m_myPlant->Attack();
		  cout << m_myPlant->GetName() << " deals " << damage << " damage" << endl;
		  m_curZombie->SetHealth(m_curZombie->GetHealth() - damage);

		  int dam = m_curZombie->Attack();
		  cout << m_curZombie->GetName() << " deals " << dam << " damage" << endl;
		  m_myPlant->SetHealth(m_myPlant->GetHealth() - dam);
		}
	      else if(attack == 2 and m_numSpecial > 0)
		{
		  m_numSpecial = m_numSpecial - 1;
		  int damage2 = m_myPlant->SpecialAttack();
		  cout << m_myPlant->GetName() << " deals " << damage2 << " damage" << endl;
		  m_curZombie->SetHealth(m_curZombie->GetHealth() - damage2);

		  int dam2 = m_curZombie->SpecialAttack();
		  cout << m_curZombie->GetName() << " deals " << dam2 << " damage" << endl;
		  m_myPlant->SetHealth(m_myPlant->GetHealth() - dam2);
		}
	      else
		{
		  cout << "All out of special attacks!" << endl;
		}

	      cout << "Plant Health: " << m_myPlant->GetHealth() << endl;
	      cout << "Zombie Health: " << m_curZombie->GetHealth() << endl;
	      
	      if(m_myPlant->GetHealth() <= 0)
		{
		  m_myPlant->SetHealth(0);
		  cout << "You have been defeated" << endl;
		}
	      else if(m_curZombie->GetHealth() <= 0)
		{
		  m_curZombie->SetHealth(0);
		  cout << "You have defeated the zombie" << endl;
		}
	    }while(attack < 1 and attack > 2);
	}
    }
  else
    {
      cout << "No zombie in room to attack!" << endl;
    }
  if(m_curZombie->GetHealth() <= 0)
    {
      delete m_curZombie;
      m_curZombie = nullptr;
    }
}
  // Name: Stats()
  // Description: Displays the information about the player (name, hp, rests, specials)
  // Preconditions: None
  // Postconditions: None
void Game::Stats()
{
  cout << "Name: " << m_myPlant->GetName() << endl;
  cout << "Health " <<  m_myPlant->GetHealth() << endl;
  cout << "Rests: " <<  m_numRests << endl;
  cout << "Specials: " << m_numSpecial << endl;
}
