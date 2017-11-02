#include "stdafx.h"
#include "Player.h"

using namespace std;
Player::Player(string name, string description):
	name(name),
	description(description)
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
