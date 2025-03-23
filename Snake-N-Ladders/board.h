#include <unordered_map>
#include <string>
#include "specialEntity.h"
#include "player.h"
#include "gameState.h"

using namespace std;

class board
{
private:
    int length;
    int width;
    int totalSize;
    bool boardStatus = false;
    unordered_map<int, int> Snakes;
    unordered_map<int, int> Ladderes;

public:
    int BoardSize = 100;
    board(int width, int length, int totalSize,  int snake, int ladder);
    ~board();
    bool validityCheck(int snakeNumber, int LadderNumber);

    void generateLadders(int number);
    void generateSnake(int number);
    
    void movePlayer(player &Player);
};


//constructing Board 🔁🔁
board::board(int width, int length, int totalSize, int snakes, int ladders){
    this->length = length;
    this->width = width;
    this->totalSize = totalSize;


    cin.ignore();

    if(totalSize != (width * length)){
        cout<<"Error ! incorrect Width and Length ! Not Symmetrical";
        return ;
    }
    cout<<"Generating Snakes -> ";

    generateSnake(snakes);
    cout<<"Boad is generated With Snakes -> \n\n";

    cout<<"Generating Ladders -> ";
    generateLadders(ladders);

    cout<<"Board is generated successfully checkMark <True>"; 

    this->boardStatus = true;
}




//Generating Snakes 🐉🐲
void board::generateSnake(int number){
    specialEntity snake;
    for(int i = 0; i < number; i++){
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
void board::generateLadders(int number){
    specialEntity ladder;

    for(int i = 0; i < number; i++){
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
bool board::validityCheck(int snakeNumber, int Ladder){
    if(Snakes.size() != snakeNumber || Ladderes.size() != Ladder || this->boardStatus != true){
        cout<<"Invalid BoadGeneration !";
        return false;
    }
    return true;
} 



//player Movement 🏃‍♂️💨
void board::movePlayer(player &Player){
    specialEntity myDice;
    string name = Player.getName();

    cout<<"\n\n\t";
    for(auto character : name)cout<<character;

    cout<<"    Enter your luckey string -> ";
    string luckeyString;
    getline(cin, luckeyString);
    
    int myRoll = myDice.rollDice(luckeyString),
    move = Player.getPosition();

    cout<<"\n\tinitial position ->> "<<move;
    cout<<"\n\tyour Roll ->> "<<myRoll;

    if(move == 0 && myRoll != 6){
        myRoll = 0;
        cout<<"\n\t Need 6 to start !";
    } 

    if(move + myRoll > 100){
        myRoll = 0;
        cout<<"\n\tneed "<<100 - move<<" or less to move !";
    }

    move += myRoll;
    if(Ladderes.find(move) != Ladderes.end()){
        move = Ladderes[move];
    }

    if(Snakes.find(move) != Snakes.end()){
        move = Snakes[move];
    }
    cout<<"\n\n\t";
    for(auto character : name)cout<<character;
    cout<<"  Position ->> "<<move;
    Player.setPosition(move);
}
board::~board(){
}

