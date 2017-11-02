#include "stdafx.h"
#include "Room.h"

GameObject *objects[10];
Room::Room(std::string name, std::string description)
	: name(name), description(description)
{

}

Room::~Room()
{
}

void Room::interact(GameObject & gameObject)
{
}

std::string Room::getName()
{
	return std::string();
}

std::string Room::getDescription()
{
	return std::string();
}

std::string Room::eventTriggered(GameEvent & gameEvent)
{
	return std::string();
}

GameObject** Room::getObjects()
{
	return objects;
}
