#ifndef ZOMBIEGAME_H_
#define ZOMBIEGAME_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
#include <vector>
#include <QString>
using namespace std;

class ZombieGame {
private:
	Parser parser;
	Room *currentRoom;
    vector<Room*> rooms;

public:
    ZombieGame();
    string go(string direction);
    QString teleport();
    QString getRoomInfo(Room*);
    Room* getCurrentRoom();
};

#endif /*ZOMBIEGAME_H_*/
