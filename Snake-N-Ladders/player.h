#include <iostream>
#include <string>

using namespace std;

class player
{
private:
    int position = 0;
    string name;
public:
    player();
    ~player();

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
    this->position = move;
}

void player::setName(string name){
    this->name = name;
}

player::player(){
}

player::~player()
{
}
