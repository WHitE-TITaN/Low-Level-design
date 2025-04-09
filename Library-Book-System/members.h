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

    rawInput = name + date;
    
    validTill.tm_mon += 1;
    mktime(&validTill);

    int hashValue = hash<string>{}(rawInput) % 1000000;
    cout<<"\nlibrary System $\n     /-Id - "<<hashValue<<" \n";

    allMembers[hashValue] = {rawInput, validTill};

    return isValidMember(hashValue); 
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
        cout<<"Name - "<<nameNValidity.first<<"\nValid till - ";
        cout<<nameNValidity.second.tm_mday <<" / "
            <<nameNValidity.second.tm_mon  + 1<<" / " 
            <<nameNValidity.second.tm_year <<"\n";

    }
     
    return true;
}

members::~members()
{
}
