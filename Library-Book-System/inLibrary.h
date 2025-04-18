#include<members.h>

class readingHall{
    unordered_set<int> membersIn;
    public:
    bool checkIN(int id){
        members *checkingIN;
        if(!checkingIN->isValidMember(id)){
            return false;
        }
        cout<<"\n*Welocme Sir*";
        membersIn.insert(id);
        return true;
    }
};