#pragma once
#include "GameObject.h"
class Room :
	public GameObject
{
public:
	Room(std::string name, std::string description);
	~Room();
	void interact(GameObject &gameObject);
	Room& getNorthExit();
	Room& getSouthExit();
	Room& getEastExit();
	Room& getWestExit();
	bool hasNorthExit();
	bool hasSouthExit();
	bool hasEastExit();
	bool hasWestExit();
	void setNorthExit(Room* exit);
	void setSouthExit(Room* exit);
	void setEastExit(Room* exit);
	void setWestExit(Room* exit);
	std::string eventTriggered(GameEvent &gameEvent);
	GameObject** getObjects();
private:
	Room* north;
	Room* south;
	Room* east;
	Room* west;
};

