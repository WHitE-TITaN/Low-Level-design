#pragma once

#include "book.h"
#include <functional>

class members{
private:
    unordered_map<int, pair<string, tm>> allMembers;            //id - > {name , valid memebrship date ->>};
    time_t systemDay;
    tm validTill;
    string date;                                               //only to generate hash

public:
    members();
    ~members();

    bool registerUser();
    bool isValidMember(string name);
};


//constructor ->>
members::members()
{
    systemDay = time(0);
    validTill = *localtime(&systemDay);
    date = ctime(&systemDay);
}


// add new user function ->>
bool members::registerUser(){
    string name;
    string rawInput;
    cin.ignore();

    cout<<"\n\tName /- ";
    getline(cin, name);

    for(auto character : name){
        rawInput.push_back(character);
    }
    for(auto character : date){
        rawInput.push_back(character);
    }
    
    validTill.tm_year = 1900 + validTill.tm_year;
    validTill.tm_mon = validTill.tm_mon + 2;        // 1 to index it to 1 - january + 1 subscription

    int hashValue = hash<string>{}(rawInput) % 1000000;
    allMembers[hashValue].first = name;
    allMembers[hashValue].second = validTill;
}

members::~members()
{
}
