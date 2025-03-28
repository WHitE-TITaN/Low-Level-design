#include <iostream>
#include <vector>
#include "board.h"

using namespace std;

int main(){
    int snakes, ladders;
    cout<<"\nEnter numebr of snakes -> ";
    cin>>snakes;
    cout<<"\nEnter number of ladders -> ";
    cin>>ladders;

    board GameBoard(10, 10, 100, snakes, ladders);

    if(GameBoard.validityCheck(snakes, ladders)){
        int playerCount;
        cout<<"\n\tEnter number of players ->> ";
        cin>>playerCount;
        cin.ignore();

        vector<pair<string, player>> allPlayers(playerCount);

        for(int i = 0; i < playerCount; i++){
            string name;
            cout<<"Enter player"<<i + 1<<"name -> ";
            getline(cin, name);
            player newPlayer;
            newPlayer.setName(name);

            allPlayers[i] = {name, newPlayer};
        }

        gameState newGame;
        newGame.startGame();

        while(!newGame.isEnded()){
            for(auto& players : allPlayers){
                if(newGame.isEnded()) return 0;
                
                //move player -> 🏃‍♂️💨
                GameBoard.movePlayer(players.second);

                //if the player has reached 100 then end game ->

                if(players.second.getPosition() == 100){
                    cout<<"\n\n\t\t\t";
                    string Name = players.second.getName();
                    for(auto Character : Name) cout<<Character;
                    cout<<"\n\t*********          WON THE GAME              **********\n\n\n\n\n\n\n";
                    newGame.setEnded();
                    break;
                }
            }
        }

    }
}


//dedeawefaw seed for 6;