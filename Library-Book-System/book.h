#pragma once

#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <string>

using namespace std;

class book
{
private:
    int total_count, current_count;
    unordered_map<string, pair<string, string>> issures;
    

public:
    book();
    ~book();
};

book::book(/* args */)
{
}

book::~book()
{
}
