#include "stdafx.h"
#include "GameObject.h"

using namespace std;

string name = "";
string description = "";

GameObject::GameObject(string pName, string pDescription)
{
	name = pName;
	description = pDescription;
}

GameObject::~GameObject()
{
}

string getName() {
	return name;
}

string getDescription() {
	return description;
}