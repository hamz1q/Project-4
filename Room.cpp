#include "Room.h"

  //Name: Room (Overloaded Constructor)
  //Precondition: Must have valid input for each part of a room
  //Postcondition: Creates a new room
Room::Room(int id, string name, string desc, int nID, int eID, int sID, int wID)
{
  m_ID = id;
  m_name = name;
  m_desc = desc;
  m_direction[0] = nID;
  m_direction[1] = eID;
  m_direction[2] = sID;
  m_direction[3] = wID;
}

  //Name: GetName
  //Precondition: Must have valid room
  //Postcondition: Returns room name as string
string Room::GetName()
{
  return m_name;
}

  //Name: GetID
  //Precondition: Must have valid room
  //Postcondition: Returns room id as int
int Room::GetID()
{
  return m_ID;
}

  //Name: GetDesc
  //Precondition: Must have valid room
  //Postcondition: Returns room desc as string
string Room::GetDesc()
{
  return m_desc;
}

  //Name: CheckDirection
  //Precondition: Must have valid room
  //You pass it a char (N/n, E/e, S/s, or W/w) and if that is a valid exit it
  //returns the ID of the room in that direction
  //Postcondition: Returns id of room in that direction if the exit exists
  //If there is no exit in that direction, returns -1
int Room::CheckDirection(char myDirection)
{
  int id = 0;
    
  if(myDirection == 'N' or myDirection == 'n')
    {
      if(m_direction[0] != -1)
	{
	  id = m_direction[0];
	}
      else
	{
	  id = -1;
	}
    }
  else if(myDirection == 'E' or myDirection == 'e')
    {
      if(m_direction[1] != -1)
	{
	  id = m_direction[1];
	}
      else
	{
	  id = -1;
	}
    }
  else if(myDirection == 'S' or myDirection == 's')
    {
      if(m_direction[2] != -1)
	{
	  id = m_direction[2];
	}
      else
	{
	  id = -1;
	}
    }
  else if(myDirection == 'W' or myDirection == 'w')
    {
      if(m_direction[3] != -1)
	{
	  id = m_direction[3];
	}
      else
	{
	  id = -1;
	}
    }
  return id;
}

  //Name: PrintRoom
  //Precondition: Room must be complete
  //Postcondition: Outputs the room name, room desc, then possible exits
void Room::PrintRoom()
{
  char exits[4] = {'\0'};

  if(m_direction[n] != -1)
    {
      exits[0] = 'N';
    }
  if(m_direction[e] != -1)
    {
      exits[1] = 'E';
    }
  if(m_direction[s] != -1)
    {
      exits[2] = 'S';
    }
  if(m_direction[w] != -1)
    {
      exits[3] = 'W';
    }
  
  cout << m_name << endl;
  cout << endl;
  cout << m_desc << endl;
  cout << endl;
  cout << "Possible Exits: ";
  
  for(int i = 0; i < 4; i++)
    {
      cout << exits[i];
      cout << " ";
    }

  cout << endl;
  
}
