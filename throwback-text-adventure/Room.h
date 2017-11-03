#pragma once
#include "GameObject.h"
class Room :
	public GameObject
{
public:
	Room(std::string name, std::string description);
	~Room();
	void interact(GameObject &gameObject);
	std::string getName();
	std::string getDescription();
	std::string eventTriggered(GameEvent &gameEvent);
	GameObject** getObjects();
	std::string name;
	std::string description;
};

