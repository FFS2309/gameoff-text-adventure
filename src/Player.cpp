#include "stdafx.h"
#include "Player.h"

using namespace std;
Player::Player(string name, string description, Room* room) :
	GameObject(name, description),
	room(room)
{

}

Player::~Player()
{

}

void Player::interact(GameObject & gameObject)
{

}

std::string Player::getName()
{
	return name;
}

std::string Player::getDescription()
{
	return description;
}

std::string Player::eventTriggered(GameEvent & gameEvent)
{
	
	switch (gameEvent.getAction()) {
	default:
	case GameEvent::ACTION::LOOK_AT:
		return "Hi, I'm " + name;
	case GameEvent::ACTION::PICK_UP:
		return "You can't pick me up! I'm the player !!!";
	}
}

Room& Player::getRoom()
{
	return *room;
}

void Player::setRoom(Room* room)
{
	this->room = room;
}

void Player::pickUp(GameObject & gameObject)
{
}
