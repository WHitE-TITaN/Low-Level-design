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
    bool isValidMember(int id);
};


//constructor ->>
members::members()
{
}


//🆕 add new user function ->>
bool members::registerUser(){
    string name;
    string rawInput;
    //cin.ignore();
  
    // get todays date;
    systemDay = time(0);
    validTill = *localtime(&systemDay);
    date = ctime(&systemDay);

    cout<<"\n\tName /- ";
    getline(cin, name);

    for(auto character : name){
        rawInput.push_back(character);
    }
    for(auto character : date){
        rawInput.push_back(character);
    }
    
    validTill.tm_year = 1900 + validTill.tm_year;
    validTill.tm_mon = (validTill.tm_mon + 2) % 12;        // 1 to index it to 1 - january + 1 subscription

    int hashValue = hash<string>{}(rawInput) % 1000000;
    cout<<hashValue;
    allMembers[hashValue].first = name;
    allMembers[hashValue].second = validTill;

    isValidMember(hashValue);
}


//✅ check validity for user !
bool members::isValidMember(int id){
    auto locator = allMembers.find(id);

    //✅ check if user exist in the list or not.
    if(locator == allMembers.end()){
        cout<<"user Not Fount !\n";
        return false;
    }

    // get todays date;
    systemDay = time(0);
    validTill = *localtime(&systemDay);
    date = ctime(&systemDay);

    pair<string, tm> nameNValidity = locator->second;
    //if user is having valid subscription

    if(nameNValidity.second.tm_mday > validTill.tm_mday && nameNValidity.second.tm_mon >= validTill.tm_mday){
        cout<<"subscription has been expired !";
        return false;
    }
    else{
        cout<<nameNValidity.first<<"\n";
        cout<<nameNValidity.second.tm_mday <<" / "
            <<nameNValidity.second.tm_mon <<" / " 
            <<nameNValidity.second.tm_year <<"\n";

    }
     
    return true;
}

members::~members()
{
}
