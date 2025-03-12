#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class board
{
private:
    int length = 10;
    int width = 10;
    int totalSize = 100;
    vector<int> playersPosition;
    unordered_map<int, int> Snakes;
    unordered_map<int, int> Ladderes;

public:
    int BoardSize = 100;
    board(int width, int length, int totalSize);
    ~board();
};

board::board(int width, int length, int totalSize){
    if(totalSize != (width * length)){
        cout<<"Error ! incorrect Width and Length ! Not Symmetrical";
        return ;
    }
    int currentSize = 1;
    for(int i = 0; i < width; i++){
        for(int j = 0; j < length; j++){
            cout<<" | "<<currentSize++<<" | ";
        }
        cout<<"\n";
    }
    return;
}

board::~board(){
}
