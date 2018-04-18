#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "Room.h"
#include <ctime>
#include <string>
using namespace std;

class gameMap{

private:
    int currentI, currentJ = 0, mapWidth, mapHeight;
    int roomArray[11][20] = {{0}};
    vector<Room*> rooms;
    Room* currentRoom;

public:
    gameMap();
    void fillMap();
    Room* getCurrentRoom();
    void changeRoom(int);
    string getDoorStates();
};

#endif // GAMEMAP_H
