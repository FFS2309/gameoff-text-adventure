#include "stdafx.h"
#include "GameObject.h"

using namespace std;

GameObject::GameObject(string name, string description)
{
	m_name = name;
	m_description = description;
}

string GameObject::getName() {
	return m_name;
}

string GameObject::getDescription() {
	return m_description;
}