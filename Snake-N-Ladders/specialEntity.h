#include <iostream>
#include <vector>
#include <random>
#include "board.h"

using namespace std;

class specialEntity{
    int start, end;
private:

public:
    specialEntity();
    int generateEntity(){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dist(2, 99);
        return dist(gen);
    }
    ~specialEntity();
};

specialEntity::specialEntity(){
}



specialEntity::~specialEntity(){

}