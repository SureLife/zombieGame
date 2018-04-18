#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>
#include "item.h"
#include <vector>
using namespace std;

class Character {
private:
	string description;
    vector <Item> itemsInCharacter;
    int health, beanCount = 0, waterCount, knifeCount = 0, pistolCount = 0, rifleCount = 0, pillCount = 0;
public:
    void addItem(Item);
    Character();
	Character(string description);
    string shortDescription();
    bool hasWater();
    bool hasBeans();
    bool hasKnife();
    bool hasPistol();
    bool hasRifle();
    bool hasPill();
    void useWater();
    void useBeans();
    void useKnife();
    void usePistol();
    void useRifle();
    void usePill();
    int getHealth();
    void changeHealth(int amt);
};

#endif /*CHARACTER_H_*/
