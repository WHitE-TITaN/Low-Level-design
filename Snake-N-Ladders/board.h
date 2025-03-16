#include <unordered_map>
#include <string>
#include "specialEntity.h"
#include "player.h"

using namespace std;

class board
{
private:
    int length;
    int width;
    int totalSize;
    unordered_map<int, int> Snakes;
    unordered_map<int, int> Ladderes;
    vector<player> Player;

public:
    int BoardSize = 100;
    board(int width, int length, int totalSize);
    ~board();
    bool validityCheck();

    void generateLadders();
    void generateSnake();
    
    void movePlayer(player Player);
};


//constructing Board 🔁🔁
board::board(int width, int length, int totalSize){
    this->length = length;
    this->width = width;
    this->totalSize = totalSize;

    if(totalSize != (width * length)){
        cout<<"Error ! incorrect Width and Length ! Not Symmetrical";
        return ;
    }
    cout<<"Generating Snakes -> ";

    generateSnake();
    cout<<"Boad is generated With Snakes -> \n\n";

    cout<<"Generating Ladders -> ";
    generateLadders();

    cout<<"Board is generated successfully checkMark <True>";
}




//Generating Snakes 🐉🐲
void board::generateSnake(){
    specialEntity snake;
    for(int i = 0; i < 6; i++){
        pair<int, int> generatedSnake = snake.generateEntity();

        while(Snakes.find(generatedSnake.first) != Snakes.end()){
            cout<<"regenerating -> \n";
            generatedSnake = snake.generateEntity();
        }
        Snakes[generatedSnake.first] = generatedSnake.second;
    }

    for(auto entiry : Snakes){
        cout<<"Head -> "<<entiry.first<<", tail -> "<<entiry.second<<"\n";
    }
}





//Generating ladders 🪜🪜
void board::generateLadders(){
    specialEntity ladder;

    for(int i = 0; i < 5; i++){
        pair<int, int> ladders = ladder.generateEntity();

        while(Ladderes.find(ladders.second) != Ladderes.end()){
            ladders = ladder.generateEntity();
        }
        Ladderes[ladders.second] = ladders.first;
    }

    for(auto entiry : Ladderes){
        cout<<"Head -> "<<entiry.first<<", tail -> "<<entiry.second<<"\n";
    }
}



//check validity ✅
bool board::validityCheck(){
    if(Snakes.size() != 6 && Ladderes.size() != 5){
        cout<<"Invalid BoadGeneration !";
        return false;
    }
    return true;
} 



//player Movement 🏃‍♂️💨
void board::movePlayer(player Player){
    specialEntity myDice;

    cout<<"Enter your luckey string -> ";
    string luckeyString;
    getline(cin, luckeyString);
    
    int myRoll = myDice.rollDice(luckeyString),
    move = Player.getPosition();

    if(Ladderes.find(move + myRoll) != Ladderes.end()){
        move += Ladderes[move + myRoll];
    }

    if(Snakes.find(move + myRoll) != Snakes.end()){
        move -= Snakes[move + myRoll];
    }

    Player.setPosition(move + myRoll);
}
board::~board(){
}

