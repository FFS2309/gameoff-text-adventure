#include "stdafx.h"
#include "GameEvent.h"

GameEvent::GameEvent(GameObject & who, ACTION what):
	who(who),
	what(what)
{}
