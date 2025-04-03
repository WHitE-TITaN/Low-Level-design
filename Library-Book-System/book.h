#pragma once

#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <ctime>
#include "members.h"
#include <string>

using namespace std;

class book
{
private:
    string bookName;
    int total_count, current_count;
    unordered_map<string, pair<tm, tm>> issures;

    time_t systemDate;      //featch the system time
    tm date;               //formatize to featch date, mounth, year, min, hrs, sec 24 hr clock;

public:
    book();
    ~book();

    bool issuedTo(string name);
    bool addNewBook(string name, int total_count);
};

book::book(){
    systemDate = time(0);
    date = *localtime(&systemDate);
}

bool book::addNewBook(string name, int count){
    this->bookName = name;
    this->total_count = count;
    this->current_count = count;
}

bool book::issuedTo(string name){

} 

book::~book()
{
}
