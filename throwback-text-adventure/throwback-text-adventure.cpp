// throwback-text-adventure.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

#include "stdafx.h"
#include "Game.h"
using namespace std;

void sleep(int seconds) {
#if defined(_WIN32) || defined(_WIN64)
	Sleep(seconds * 1000);
#endif
}

vector<string> split(const string& str, const string& delim)
{
	vector<string> tokens;
	size_t prev = 0, pos = 0;
	do
	{
		pos = str.find(delim, prev);
		if (pos == string::npos) pos = str.length();
		string token = str.substr(prev, pos - prev);
		if (!token.empty()) tokens.push_back(token);
		prev = pos + delim.length();
	} while (pos < str.length() && prev < str.length());
	return tokens;
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
	Room r("Main hall", "It is a really big room with white walls and large windows!");
	Player p(name, description, &r);
	char command[64];
	while (true) {
		cout << "What do you want to do ?" << endl;
		cin.getline(command, 64);
		char *commandP = &command[0];
		//make command lowercase
		for (; *commandP; ++commandP) *commandP = tolower(*commandP);
		if (strcmp(command, "quit") == 0) {
			return 0;
		}
		else if (strcmp(command, "look") == 0) {
			GameEvent lookEvent(&p, GameEvent::ACTION::LOOK_AT);
			cout << p.getRoom().eventTriggered(lookEvent) << endl;
		}
		else if (strstr(command, "look at") != nullptr) {
			char cArgs[64];
			for (int i = 0; i < 64 - 8; i++) {
				cArgs[i] = command[i + 8];
			}
			vector<string> args = split(cArgs, " ");
			GameObject** roomObjects = p.getRoom().getObjects();
			for each (string look_at in args)
			{
				boolean found = false;
				for (int i = 0; roomObjects[i] != nullptr && roomObjects[i] != NULL; i++){
					string look_obj = string(roomObjects[i]->getName());
					transform(look_obj.begin(), look_obj.end(), look_obj.begin(), ::tolower);
					if (look_obj == look_at) {
						found = true;
						GameEvent lookAtEvent(&p, GameEvent::ACTION::LOOK_AT);
						cout << roomObjects[i]->eventTriggered(lookAtEvent) << endl;
					}
				}
				if (!found) {
					cout << "You look around you, but there is no " << look_at << " anywhere" << endl;
				}
			}
		}
		else if (strstr(command, "pick up") != nullptr) {
			char cArgs[64];
			for (int i = 0; i < 64 - 8; i++) {
				cArgs[i] = command[i + 8];
			}
			vector<string> args = split(cArgs, " ");
			GameObject** roomObjects = p.getRoom().getObjects();
			for each(string pick_up in args) {
				boolean found = false;
				for (int i = 0; roomObjects[i] != nullptr && roomObjects[i] != NULL; i++) {
					string look_obj = string(roomObjects[i]->getName());
					transform(look_obj.begin(), look_obj.end(), look_obj.begin(), ::tolower);
					if (look_obj == pick_up) {
						found = true;
						GameEvent lookAtEvent(&p, GameEvent::ACTION::PICK_UP);
						cout << roomObjects[i]->eventTriggered(lookAtEvent) << endl;
					}
				}
				if (!found) {
					cout << "You look around you, but there is no " << pick_up << " anywhere" << endl;
				}
			}
		}
		else if (strstr(command, "interact") != nullptr) {
			char cArgs[64];
			for (int i = 0; i < 64 - 8; i++) {
				cArgs[i] = command[i + 8];
			}
			vector<string> args = split(cArgs, " ");
			GameObject** roomObjects = p.getRoom().getObjects();
			for each(string pick_up in args) {
				if (pick_up == "with") continue;
				boolean found = false;
				for (int i = 0; roomObjects[i] != nullptr && roomObjects[i] != NULL; i++) {
					string look_obj = string(roomObjects[i]->getName());
					transform(look_obj.begin(), look_obj.end(), look_obj.begin(), ::tolower);
					if (look_obj == pick_up) {
						found = true;
						GameEvent lookAtEvent(&p, GameEvent::ACTION::INTERACT);
						cout << roomObjects[i]->eventTriggered(lookAtEvent) << endl;
					}
				}
				if (!found) {
					cout << "You look around you, but there is no " << pick_up << " anywhere" << endl;
				}
			}
		}
		else if (strstr(command, "up") != nullptr || strstr(command, "north") != nullptr) {

		}
	}
    return 1337;
}

