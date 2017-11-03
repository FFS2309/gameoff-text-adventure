// throwback-text-adventure.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Game.h"
using namespace std;

void sleep(int seconds) {
#if defined(_WIN32) || defined(_WIN64)
	Sleep(seconds * 1000);
#endif
}

boolean stringCompareWithoutNL(char a[], char b[]) {
	int aLen = 0;
	while (a[aLen] != NULL && a[aLen] == '\n')
		aLen++;
	int bLen = 0;
	while (b[bLen] != NULL && b[aLen] == '\n')
		bLen++;
	if (aLen == bLen) {
		boolean same = true;
		for (int i = 0; i < aLen; i++) {
			if (a[i] != b[i]) same = false;
		}
		return same;
	}
	else {
		return false;
	}
}

int main()
{
	cout << "Hi, what's your name ?" << endl;
	char name[256];
	cin.getline(name, 256);
	cout << "Okay, " << name << ", next is to describe yourself, but keep it short please." << endl;
	char description[1024];
	cin.getline(description, 1024);
	cout << "That's all for now, let us begin to play now!" << endl;
	sleep(2);
	//UGLY, PLEASE KILL ME!
#ifdef _WIN32
	system("cls");
#endif
	int random = 0;
	Room r = *(new Room("Main hall", "It is a really big room with white walls and large windows"));
	Player p = *(new Player(*(new string(name, 256)), *(new string(description, 1024)), r));
	char command[64];
	while (true) {
		cout << "What do you want to do ?" << endl;
		cin.getline(command, 64);
		if (strcmp(command, "quit") == 0) {
			return 0;
		}
		else if (strcmp(command, "look") == 0) {
			GameEvent lookEvent = *(new GameEvent(&p, GameEvent::ACTION::LOOK_AT));
			cout << p.getRoom().eventTriggered(lookEvent) << endl;
		}
	}
    return 1337;
}

