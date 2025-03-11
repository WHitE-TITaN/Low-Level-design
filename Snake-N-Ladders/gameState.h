#include <iostream>
using namespace std;

class gameState
{
private:
    bool start = false, 
    end = false, 
    running = false;
public:
    gameState(/* args */);
    ~gameState();
};

gameState::gameState()
{
}

gameState::~gameState()
{
}
