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
    unordered_map<int, pair<tm, tm>> issures;

    time_t systemDate;      //featch the system time
    tm date;               //formatize to featch date, mounth, year, min, hrs, sec 24 hr clock;

    int dateCalculator(tm date);
public:
    book();
    ~book();

    bool issuedTo(int id);
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



//📚🧑 issue book...
bool book::issuedTo(int id){
    auto locator = issures.find(id);

    if(locator == issures.end()){
        tm expiry = date;
        expiry.tm_mday = (expiry.tm_mday + 15) % 30;



        pair<tm, tm> validTill;
    }
} 

book::~book()
{
}


int book::dateCalculator(tm date){
    if(date.tm_year % 4 == 0 && date.tm_year % 100 != 0 || date.tm_year % 400 == 0){
    }
    return 0;
}