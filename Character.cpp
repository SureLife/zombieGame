#include "Character.h"

Character::Character(){
    health = 100;
    waterCount = 0;
}

Character::Character(string description) {
    health = 100;
    waterCount = 0;
	this->description = description;
}
void Character::addItem(Item item) {
    itemsInCharacter.push_back(item);
    if (item.getShortDescription() == "Zombie Repellent Pill") pillCount++;
    else if (item.getShortDescription() == "Strong Rifle") rifleCount++;
    else if (item.getShortDescription() == "Old Pistol") pistolCount++;
    else if (item.getShortDescription() == "Dilapidated Knife") knifeCount++;
    else if (item.getShortDescription() == "Water") waterCount++;
    else if (item.getShortDescription() == "Baked Beans") beanCount++;

}

bool Character::hasBeans()
{
    if(beanCount > 0) return true;
    else return false;
}

bool Character::hasWater()
{
    if(waterCount > 0) return true;
    else return false;
}

bool Character::hasKnife()
{
    if(knifeCount > 0) return true;
    else return false;
}

bool Character::hasPistol()
{
    if(pistolCount > 0) return true;
    else return false;
}

bool Character::hasRifle()
{
    if(rifleCount > 0) return true;
    else return false;
}

bool Character::hasPill()
{
    if(pillCount > 0) return true;
    else return false;
}

void Character::useBeans()
{
    beanCount--;
}

void Character::useWater()
{
    waterCount--;
}

void Character::useKnife()
{
    knifeCount--;
}

void Character::usePistol()
{
    pistolCount--;
}

void Character::useRifle()
{
    rifleCount--;
}

void Character::usePill()
{
    pillCount--;
}

int Character::getHealth()
{
    return health;
}

void Character::changeHealth(int amt)
{
    health += amt;
}
