#pragma once
#include <string>
#include "GameEvent.h"
class GameEvent;
class GameObject
{
private:
    std::string m_name;
    std::string m_description;
public:
    GameObject(std::string name, std::string description);
	virtual void interact(GameObject &gameObject) = 0;
	std::string getName();
	std::string getDescription();
	virtual std::string eventTriggered(GameEvent &gameEvent) = 0;
};

