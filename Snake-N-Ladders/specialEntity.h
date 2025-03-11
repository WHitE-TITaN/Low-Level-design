#include <iostream>
#include <vector>
#include <random>

using namespace std;

class specialEntity{
private:
    int numberOfSnake, numberOfLadders;
public:
    specialEntity(/* args */);
    ~specialEntity();
};

specialEntity::specialEntity(/* args */){
    random_device rd;
    mt19937 gen(rd);
}

specialEntity::~specialEntity()
{
}


class snake{
private:
    int start, end;
};

class labber{
public:
    int start, end;
};