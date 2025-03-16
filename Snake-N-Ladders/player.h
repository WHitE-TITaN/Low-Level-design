#include <iostream>

using namespace std;

class player
{
private:
    int position = 0;
public:
    player();
    ~player();

    int getPosition();
    void setPosition(int move);
};


int player::getPosition(){
    return this->position;
}

void player::setPosition(int move){
    this->position = move;
}

player::player(){
}

player::~player()
{
}
