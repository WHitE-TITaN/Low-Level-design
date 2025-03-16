#include <iostream>
#include <vector>
#include <utility>
#include <random>

using namespace std;

random_device rd;
mt19937 gen(rd());

class specialEntity{
private:
    unsigned long long seedMaker(string input);

public:
    specialEntity();
    ~specialEntity();

    pair<int, int> generateEntity();
    int rollDice(string key);
};

specialEntity::specialEntity(){
}


//makeing random numbebr from string ->> 
unsigned long long specialEntity::seedMaker(string input){
    hash<string> hasher;
    return hasher(input);
}



//dice Roller
int specialEntity::rollDice(string key){
    unsigned long long seed = seedMaker(key);       //set string as key
    mt19937 generate(seed);                         
    uniform_int_distribution<int> dice(1, 6);       //set Limits

    return dice(generate);                          //generate and return !.
}



//random number generator.
pair<int, int> specialEntity::generateEntity(){
    pair<int, int> outPut;
    
    //Generating head of snake -> 
    uniform_int_distribution<int> snakeHead(11, 99);
    outPut.first = snakeHead(gen);
    
    //Generating Tail of snake -> 
    uniform_int_distribution<int> snakeTail(1, outPut.first - 1);
    outPut.second = snakeTail(gen);

    //return head and tail
    return outPut;
}

specialEntity::~specialEntity(){

}