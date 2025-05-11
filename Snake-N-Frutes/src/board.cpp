#include "../header/board.h"

void board::printBoard(){
    for(int i = 0; i < hight; i++){
        for(int j = 0; j < width; j++){
            if(i == 0 || i == hight - 1){
                std::cout<<"_";
                continue;
            }
            if(j == 0 || j == width - 1){
                std::cout<<"|";
                continue;
            }
            std::cout<<" ";
        }
        std::cout<<"\n";
    }
}