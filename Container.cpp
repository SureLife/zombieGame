#include "Container.h"

Container::Container()
{
    itemGen();
}

void Container::addItem(Item* itemToAdd)
{
    items.push_back(*itemToAdd);
}

void Container::removeItem()
{

}

void Container::itemGen()
{
    //srand(time(NULL));
    int chance = 100;
    bool done = false;
    while(!done)
    {
        int more = rand() % 100 + 1;
        if(more <= chance)
        {
            int n = rand() % 50 + 1;
            addItem(new Item(itemNames[n-1]));
            chance = chance/2;
        }
        else done = true;
    }
}

vector<Item> Container::getItems()
{
    return items;
}

void Container::clearItems()
{
    items.clear();
}
