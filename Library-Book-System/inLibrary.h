#pragma once
#include "members.h"

class readingHall{
    static unordered_set<int> membersIn;
    public:
    bool checkIN(const int& id){
        members checkingIN;
        if(!checkingIN.isValidMember(id)){
            return false;
        }
        cout<<"\n*Welocome Sir*";
        membersIn.insert(id);
        return true;
    }

    bool checkOut(int id){
        auto locator = membersIn.find(id);
        if(locator == membersIn.end()){
            cout<<"* Not checkedIn for Reading hall! *";
            return false;
        }
        membersIn.erase(id);
        cout<<"* checked Out *";
        return true;
    }
};

unordered_set<int> readingHall::membersIn;