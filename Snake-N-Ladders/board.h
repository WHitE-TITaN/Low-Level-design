#include <iostream>
#include <vector>
#include <unordered_map>
#include "specialEntity.h"

using namespace std;

class board
{
private:
    int length;
    int width;
    int totalSize;
    unordered_map<int, int> Snakes;
    unordered_map<int, int> Ladderes;

public:
    int BoardSize = 100;
    board(int width, int length, int totalSize);
    ~board();
    bool validityCheck();

    void generateLadders();
    void generateSnake();
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

board::~board(){
}

