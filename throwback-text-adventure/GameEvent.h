#pragma once
#include "GameObject.h"
class GameEvent {
public:
	enum class ACTION
	{
		INTERACT,
		LOOK_AT,
		PICK_UP,
	};
	GameEvent(GameObject &who, ACTION what);
	GameObject& getCause() {
		return who;
	}
	ACTION getAction() {
		return what;
	}
private:
	GameObject &who;
	ACTION what;
};