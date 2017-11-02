#pragma once
#include "GameObject.h"
class Player :
	public GameObject
{
public:
	Player(std::string name, std::string description);
	~Player(); 
	void interact(GameObject &gameObject);
	std::string getName();
	std::string getDescription();
	std::string eventTriggered(GameEvent &gameEvent);
protected:
	std::string name;
	std::string description;
};

