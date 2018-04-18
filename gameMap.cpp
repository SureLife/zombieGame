#include "gameMap.h"


gameMap::gameMap()
{
    mapWidth = 20;
    mapHeight = 11;
    currentI = mapHeight/2;
}

void gameMap::fillMap()
{
    srand(time(NULL));
    int i = mapHeight/2;
    int j = 0;
    bool end = false;
    while(!end)
    {
        if(j >= mapWidth-1)  end = true;
        string roomDesc = to_string(i) + "-" + to_string(j);
        rooms.push_back(new Room(roomDesc, rooms.size()));
        roomArray[i][j] = 1;
        bool valid = false;
        while(!valid)
        {
            int option = rand() % 3 + 1;
            if(option == 1)
            {
                if(i - 1 >= 0)
                {
                    if(roomArray[i-1][j] == 0)
                    {
                        i--;
                        valid = true;
                    }
                }
            }
            else if(option == 2)
            {
                if(i + 1 <= mapHeight-1)
                {
                    if(roomArray[i+1][j] == 0)
                    {
                        i++;
                        valid = true;
                    }
                }
            }
            else if(option == 3)
            {
                if(j + 1 <= mapWidth-1)
                {
                    if(roomArray[i][j+1] == 0)
                    {
                        j++;
                        valid = true;
                    }
                }
            }
        }
    }
    rooms.back()->setFinalRoom();
    currentRoom = rooms[0];
}

Room* gameMap::getCurrentRoom()
{
    return currentRoom;
}

void gameMap::changeRoom(int dir)
{
    if(dir == 1)
    {
        currentI--;
    }
    else if(dir == 2)
    {
        currentJ++;
    }
    else if(dir == 3)
    {
        currentI++;
    }
    else if(dir == 4)
    {
        currentJ--;
    }

    string nextRoom = to_string(currentI) + "-" + to_string(currentJ);

    for(int i = 0; i < rooms.size(); i++)
    {
        if(rooms[i]->shortDescription() == nextRoom)
        {
            currentRoom = rooms[i];
            break;
        }
    }
}

string gameMap::getDoorStates()
{
    string result = "";

    if(currentI - 1 >= 0)
    {
        if(roomArray[currentI - 1][currentJ] == 1) result += "1 ";
        else result += "0 ";
    }

    else result += "0 ";

    if(currentJ + 1 <= mapWidth-1)
    {
        if(roomArray[currentI][currentJ + 1] == 1) result += "1 ";
        else result += "0 ";
    }

    else result += "0 ";

    if(currentI + 1 <= mapHeight-1)
    {
        if(roomArray[currentI + 1][currentJ] == 1) result += "1 ";
        else result += "0 ";
    }

    else result += "0 ";

    if(currentJ - 1 >= 0)
    {
        if(roomArray[currentI][currentJ - 1] == 1) result += "1 ";
        else result += "0 ";
    }

    else result += "0 ";


    //cout << "\n" << currentI << "-" << currentJ;
    return result;
}
