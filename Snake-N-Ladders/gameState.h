#include <iostream>
using namespace std;

class gameState
{
private:
    bool start = false, 
    end = false, 
    running = false;
public:
    void startGame(), setEnded();
    bool isEnded(), isStarted();
    gameState();
    ~gameState();
};

void gameState::startGame(){
    this->start = true;
}

bool gameState::isStarted(){
    return this->start;
}

bool gameState::isEnded(){
    return this->end;
}

void gameState::setEnded(){
    this->end = true;
}

gameState::gameState(){
}

gameState::~gameState()
{
}
