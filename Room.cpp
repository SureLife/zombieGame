#include "Room.h"
#include "Command.h"

Room::Room(){
}
Room::Room(string description, int id) {
	this->description = description;
    this->id = id;
    containerGen();
    if(id >= 10) spawnZombies();
}

string Room::shortDescription() {
	return description;
}

void Room::containerGen()
{
    //srand(time(NULL));
    int n = rand() % 100 + 1;
    if(n <= 50)
    {
        this->hasContainer = true;
        this->container = *(new Container());
    }
}

bool Room::checkForContainer()
{
    return hasContainer;
}

vector<Item> Room::getContainerContent()
{
    return container.getItems();
}

void Room::clearChest()
{
    container.clearItems();
}

void Room::spawnZombies()
{
    int chance = 20;
    int n = rand() % 100 + 1;
    if(n <= chance)
    {
        hasZombie = true;
    }
}

bool Room::zombieCheck()
{
    return hasZombie;
}

void Room::clearZombie()
{
    hasZombie = false;
}

bool Room::deadZombieCheck()
{
    return deadZombie;
}

void Room::setDeadZombie(bool temp)
{
    deadZombie = temp;
}

void Room::setFinalRoom()
{
    finalRoom = true;
}

bool Room::checkFinalRoom()
{
    return finalRoom;
}



