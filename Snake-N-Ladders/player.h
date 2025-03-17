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
    void setPosition(int move);
    void setName(string name);
};


int player::getPosition(){
    return this->position;
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
