#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <item.h>


class Container
{
public:
    Container();
    string itemNames[50] = {"Zombie Repellent Pill", "Strong Rifle", "Strong Rifle", "Strong Rifle", "Old Pistol", "Old Pistol","Old Pistol","Old Pistol", "Dilapidated Knife", "Dilapidated Knife", "Dilapidated Knife", "Dilapidated Knife", "Dilapidated Knife", "Dilapidated Knife", "Dilapidated Knife", "Dilapidated Knife", "Dilapidated Knife", "Dilapidated Knife", "Dilapidated Knife", "Dilapidated Knife", "Water","Water","Water","Water","Water","Water","Water","Water","Water","Water","Water","Water","Water","Water","Water","Baked Beans","Baked Beans","Baked Beans","Baked Beans","Baked Beans","Baked Beans","Baked Beans","Baked Beans","Baked Beans","Baked Beans","Baked Beans","Baked Beans","Baked Beans","Baked Beans","Baked Beans"};
    void addItem(Item *);
    void removeItem();
    void itemGen();
    void clearItems();
    vector<Item> getItems();

private:
    vector<Item> items;
};

#endif // CONTAINER_H
