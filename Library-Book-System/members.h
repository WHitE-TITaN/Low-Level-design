#pragma once

#include "book.h"

class members{
private:
    unordered_map<int, pair<string, tm>> allMembers;            //id - > {name , valid memebrship date ->>};
    time_t systemDay;
    string date;

public:
    members();
    ~members();

    bool registerUser();
    bool isValidMember(string name);
};

members::members()
{
    systemDay = time(0);
    date = ctime(&systemDay);
}

bool members::registerUser(){
    string name;
    string rawInput;
    cin.ignore();

    cout<<"\n\tName /-";
    getline(cin, name);

    for(auto character : name){
        rawInput.push_back(character);
    }
    for(auto chacarter : date){
        
    }
}

members::~members()
{
}
