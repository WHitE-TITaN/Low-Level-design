#include <iostream>
using namespace std;

class gameState
{
private:
    bool start = false, 
    end = false, 
    running = false;
public:
    gameState(string state, bool startus);
    ~gameState();
};

gameState::gameState(string state, bool status){
}

gameState::~gameState()
{
}
