#pragma once

#include <unordered_map>
#include <ctime>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

class members{
private:
    class Member{
        public:
        string name, address;
        pair<tm, tm> subscription;
        vector<pair<string, tm>> booksIddued;
        int mobileNo;
    };

    static unordered_map<int, Member *> allMembers;            //id - > {name , valid memebrship date ->>};
    time_t systemDay;
    tm validTill;
    string date;                                               //only to generate hash

public:
    members();
    ~members();

    bool registerUser();
    bool isValidMember(int id);
    bool canIssueBook(int id, tm issueBookTill);
};

//defining the static variable
unordered_map<int, members::Member*> members::allMembers;

//constructor ->>
members::members()
{
}



//🆕 add new user function ->>
bool members::registerUser(){
    string userName, userAddress;
    int userMobileNo;
    string rawInput;
    //cin.ignore();
  
    // get todays date;
    systemDay = time(0);
    validTill = *localtime(&systemDay);
    date = ctime(&systemDay);

    cout<<"\n\tName - ";
    getline(cin, userName);
    cout<<"\n\tAddress -";
    getline(cin, userAddress);
    cout<<"\n\tMobile Number - ";
    cin>>userMobileNo;
    cin.ignore();

    rawInput = userName + date;
    
    int hashValue = hash<string>{}(rawInput) % 1000000;
    cout<<"\nlibrary System $\n     /-Id - "<<hashValue<<" \n";

    Member *newMember = new Member();
    newMember->name = userName;
    newMember->address = userAddress;
    newMember->mobileNo = userMobileNo;
    newMember->subscription.first = validTill;

    validTill.tm_mon += 1;
    mktime(&validTill);
    //✨ mktime adjusts the tm struct so that if days/months go over their 
    //limit, it carries over to the next month/year automatically.

    newMember->subscription.second = validTill;

    allMembers[hashValue] = newMember;

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
        cout <<nameNValidity.first<<"'s - Subscription has expired!\n";
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

bool members::canIssueBook(int id, tm issuedBookTill){
    auto locator = allMembers.find(id);
}