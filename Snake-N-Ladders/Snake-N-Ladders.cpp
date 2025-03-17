#include <iostream>
#include <vector>
#include "board.h"

using namespace std;

int main(){
    board GameBoard(10, 10, 100);

    if(GameBoard.validityCheck()){
        int playerCount;
        cout<<"\n\tEnter number of players ->> ";
        cin>>playerCount;
        cin.ignore();

        vector<pair<string, player>> allPlayers(playerCount);

        for(int i = 0; i < playerCount; i++){
            pair<string, player> thePlayer;

            string name;
            cout<<"Enter player"<<i + 1<<"name -> ";
            getline(cin, name);
            player newPlayer;
            newPlayer.setName(name);

            thePlayer.first = name;
            thePlayer.second = newPlayer;

            allPlayers.push_back(thePlayer);
        }

        gameState newGame;
        newGame.startGame();
        while(newGame.isEnded()){
            for(auto players : allPlayers){

                //move player -> 🏃‍♂️💨
                GameBoard.movePlayer(players.second);

                //if the player has reached 100 then end game ->

                if(players.second.getPosition() >= 100){
                    newGame.setEnded();
                    break;
                }
            }
        }

    }
}