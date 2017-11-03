#include "stdafx.h"
#include "Room.h"

using namespace std;

GameObject *objects[10];
int objectCount = sizeof(objects) / sizeof(GameObject*);
class Table : public GameObject {
	void interact(GameObject &gameObject) {

	}
	std::string Table::getName() {
		return "Table";
	}
	std::string Table::getDescription() {
		return "Just a sturdy, old, wooden table!";
	}
	std::string Table::eventTriggered(GameEvent &gameEvent) {

		switch (gameEvent.getAction()) {
		default:
		case GameEvent::ACTION::LOOK_AT:
			return getDescription();
			break;
		case GameEvent::ACTION::INTERACT:
			return "You opened a hidden drawer, but it was empty! Strange!";
		case GameEvent::ACTION::PICK_UP:
			return "You try to pick the table up, but it is too heavy and you decide that you don't want to haul it with you.";
		}
	}
};
Room::Room(std::string name, std::string description)
	: name(name), description(description)
{
	//m_Name = name;
	//m_Description = description;
	objects[0] = new Table();
	objects[1] = new Table();
	objects[2] = new Table();
	objects[3] = new Table();
	objects[4] = new Table();
	objects[5] = new Table();
	objects[6] = new Table();
	objects[7] = new Table();
	objects[8] = new Table();
	objects[9] = new Table();
}

Room::~Room()
{
}

void Room::interact(GameObject & gameObject)
{
}

std::string Room::getName()
{
	return this->name;
}

std::string Room::getDescription()
{
	return this->description;
}

std::string Room::eventTriggered(GameEvent & gameEvent)
{
	string seeString = "";
	string lookString = "";
	switch (gameEvent.getAction()) {
	default:
	case GameEvent::ACTION::LOOK_AT:

		seeString = objectCount > 0 ? "a few things: " : "nothing";
		for (int i = 0; i < objectCount; i++) {
			seeString += objects[i]->getName() + (i < objectCount - 1 ? ", " : "");
		}
		lookString = "You're in " + this->getName() + "! " + this->getDescription() + " You see " + seeString + "";
		return lookString;
		break;
	case GameEvent::ACTION::INTERACT:
		return "Nothing happens!";
	case GameEvent::ACTION::PICK_UP:
		return "NO! JUST NO! YOU DON'T EVEN ... NO! STOP RIGHT NOW!";
	}
}

GameObject** Room::getObjects()
{
	return objects;
}
