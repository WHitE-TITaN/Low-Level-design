#include <iostream>
#include <vector>
#include <utility>
#include <random>

using namespace std;

class specialEntity{
private:
    mt19937 gen;

public:
    specialEntity();
    ~specialEntity();

    pair<int, int> generateEntity(){
        pair<int, int> outPut;
        
        //Generating head of snake -> 
        uniform_int_distribution<int> snakeHead(11, 99);
        outPut.first = snakeHead(gen);
        
        //Generating Tail of snake -> 
        uniform_int_distribution<int> snakeTail(1, outPut.first);
        outPut.second = snakeTail(gen);

        //return head and tail
        return outPut;
    }
};

specialEntity::specialEntity(){
}



specialEntity::~specialEntity(){

}