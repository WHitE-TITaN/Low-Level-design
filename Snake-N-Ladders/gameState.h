#include <iostream>
using namespace std;

class gameState
{
private:
    bool start = false, 
    end = false, 
    running = false;
public:
    void startGame(int PlayerCount), setEnded();
    bool isEnded(), isStarted();
    gameState(string state, bool startus);
    ~gameState();
};

void gameState::startGame(int playerCount){
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

gameState::gameState(string state, bool status){
}

gameState::~gameState()
{
}
