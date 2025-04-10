#pragma once

#include "book.h"
#include <functional>

class members{
private:
    static unordered_map<int, pair<string, tm>> allMembers;            //id - > {name , valid memebrship date ->>};
    time_t systemDay;
    tm validTill;
    string date;                                               //only to generate hash

public:
    members();
    ~members();

    bool registerUser();
    bool isValidMember(int id);
};

//defining the static variable
unordered_map<int, pair<string, tm>> members::allMembers;

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
    //✨ mktime adjusts the tm struct so that if days/months go over their 
    //limit, it carries over to the next month/year automatically.
    
    int hashValue = hash<string>{}(rawInput) % 1000000;
    cout<<"\nlibrary System $\n     /-Id - "<<hashValue<<" \n";

    allMembers[hashValue] = {name , validTill};

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
    tm *current = localtime(&systemDay);

    pair<string, tm> nameNValidity = locator->second;
    //if user is having valid subscription

    tm &expiry = nameNValidity.second;
    bool expired = false;

    if (current->tm_year > expiry.tm_year) {
        expired = true;
    } else if (current->tm_year == expiry.tm_year && current->tm_mon > expiry.tm_mon) {
        expired = true;
    } else if (current->tm_year == expiry.tm_year && current->tm_mon == expiry.tm_mon && current->tm_mday > expiry.tm_mday) {
        expired = true;
    }

    if (expired) {
        cout << "Subscription has expired!\n";
        return false;
    } else {
        cout << "Name - " << nameNValidity.first << "\nValid till - ";
        cout << expiry.tm_mday << " / "
             << expiry.tm_mon + 1 << " / "
             << expiry.tm_year << "\n";
        return true;
    }
    return false;
}

members::~members()
{
}
