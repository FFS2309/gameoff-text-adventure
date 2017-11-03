#pragma once
#include <string>
#include "GameEvent.h"
class GameEvent;
class GameObject
{
public:
	virtual void interact(GameObject &gameObject) = 0;
	virtual std::string getName() = 0;
	virtual std::string getDescription() = 0;
	virtual std::string eventTriggered(GameEvent &gameEvent) = 0;
};

