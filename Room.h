#ifndef ROOM_H_
#define ROOM_H_

#include <map>
#include <string>
#include <vector>
#include "Container.h"
using namespace std;
using std::vector;

class Room {

private:
    string description;
    int id;
    Container container;
    bool hasContainer = false;
    bool hasZombie = false;
    bool finalRoom = false;
    bool winGame = false;
    bool lostGame = false;

public:
    Room();
    Room(string description,int id);
    string shortDescription();
    void containerGen();
    bool checkForContainer();
    vector<Item> getContainerContent();
    void clearChest();
    void spawnZombies();
    bool zombieCheck();
    void clearZombie();
    bool deadZombie = false;
    bool deadZombieCheck();
    void setDeadZombie(bool);
    void setFinalRoom();
    bool checkFinalRoom();
};

#endif
