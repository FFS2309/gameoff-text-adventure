#pragma once
#include "GameObject.h"
#include "Room.h"
class Player :
	public GameObject
{
public:
	Player(std::string name, std::string description, Room &room);
	~Player(); 
	void interact(GameObject &gameObject);
	std::string getName();
	std::string getDescription();
	std::string eventTriggered(GameEvent &gameEvent);
	Room getRoom();
	void setRoom(Room room);
	void pickUp(GameObject &gameObject);
protected:
	std::string name;
	std::string description;
	Room room;
};

