#pragma once

#include <unordered_map>
#include <ctime>
#include <string>
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class members{
private:
    class Member{
        public:
        string name, address;
        pair<tm, tm> subscription;
        vector<string> booksIssued;
        int mobileNo;
    };

    static unordered_map<int, Member *> allMembers;            //id - > {name , valid memebrship date ->>};
    time_t systemDay;
    tm validTill;
    string date;                                               //only to generate hash

public:
    members();
    ~members();

    void issuedBookOnUser(int id);
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
    cout<<"\nlibrary System $\n     - Id - "<<hashValue<<" \n";

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
    bool expire = false;

    pair<tm, tm> validity = locator->second->subscription;
    if(validity.second.tm_year < current->tm_year){
        expire = true;
    }  
    if(validity.second.tm_mon < current->tm_mon){
        expire = true;
    }
    if(validity.second.tm_mday < current->tm_mday){
        expire = true;
    }

    if(expire == true){
        cout<<"validity has be expire - ";
        if(locator->second->booksIssued.size() != 0){
            cout<<"\nplease return the under written book - \n";
            
            for(auto name : locator->second->booksIssued){
                cout<<"\n"<<name;
            }
        }
        return false;
    }

    cout<<"\n name -"<<locator->second->name;
    cout<<"\n valid till -"<<validity.second.tm_mday<<" / "
        <<validity.second.tm_mon<<" / "<<
        validity.second.tm_year;

    return true;
}

members::~members()
{
}

bool members::canIssueBook(int id, tm issuedBookTill){
    auto locator = allMembers.find(id);
    
}


void members::issuedBookOnUser(int id){
    auto locator = allMembers.find(id);
    if(locator == allMembers.end()){
        cout<<"User Not Found !";
        return;
    }

    Member *person = locator->second;

    if(person->booksIssued.size() == 0){
        cout<<"person have not issued any books -";
        return;
    }

    cout<<"\n\tall the issued books by - "<<person->name<<"\n\tare under - ";
    for(auto books : person->booksIssued){
        cout<<books<<"\n";
    }
    return;
}