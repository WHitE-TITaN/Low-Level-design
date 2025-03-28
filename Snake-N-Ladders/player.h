#include <iostream>
#include <string>
#include "gameState.h"

using namespace std;

class player
{
private:
    int position = 0;
    string name;
public:

    int getPosition();
    string getName();
    void setPosition(int move);
    void setName(string name);
};


int player::getPosition(){
    return this->position;
}

string player::getName(){
    return this->name;
}

void player::setPosition(int move){
    if((this->position + move) == 100){
        gameState playerWon;
        playerWon.setEnded();
    }
    this->position = move;
}

void player::setName(string name){
    this->name = name;
}