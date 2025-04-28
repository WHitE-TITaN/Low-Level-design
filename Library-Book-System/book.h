#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
#include <ctime>
#include "members.h"
#include <string>
#include <bitset>

using namespace std;


class book
{
private:
    string bookName;
    int total_count, current_count;
    unordered_map<int, pair<tm, tm>> issures;

    int dateCalculator(tm date);
    int calculateFine(tm expiryDate, tm currentDate);
    
public:
    book();
    ~book();

    bool issuedTo(int id);
    bool addNewBook(string name, int total_count);
    void allIssuers();
    int returnBook(int id);
};

book::book(){
}





//add new book 
bool book::addNewBook(string name, int count){
    bookName = name;
    total_count = count;
    current_count = count;
    return true;
}



//📚🧑 issue book...
bool book::issuedTo(int id){
    if(current_count <= 1){
        cout<<"Book not avilable for issue !";
        return false;
    }

    time_t systemDate = time(0);;     
    tm date = *localtime(&systemDate);

    auto locator = issures.find(id);
    members *issueBook;

    if(locator == issures.end()){
        tm issueExpireDate = date;
        int issuedate = dateCalculator(date);

        if(issuedate != 0){
            issueExpireDate.tm_mon += 1;
            issueExpireDate.tm_mday += issuedate;
        }
        else{
            issueExpireDate.tm_mday += 15;
        }
        mktime(&issueExpireDate);
        //✨ mktime adjusts the tm struct so that if days/months go over their limit,
        // it carries over to the next month/year automatically.


        issures[id] = {date, issueExpireDate};
        current_count--;

        cout<<"\n Issued till - "<<
        issueExpireDate.tm_mday<<" / "<<
        issueExpireDate.tm_mon<<" / "<<
        issueExpireDate.tm_year;
        
        return true;
    }
    cout<<"\n* User already have this book *\n";
    cout<<"* Till - "<<locator->second.second.tm_mday<<" / "
    <<locator->second.second.tm_mon<<" / "
    <<1900 + locator->second.second.tm_year;

    return false;
} 

book::~book()
{
}




//calculate date
int book::dateCalculator(tm date){
    bitset<32> byte(date.tm_mon);

    if(date.tm_mday + 15 <= 28){
        return 0;
    }
    
    //if leap year;
    if(date.tm_year % 4 == 0 && date.tm_year % 100 != 0 || date.tm_year % 400 == 0){
        if(date.tm_mon == 1 && (date.tm_mday + 15) > 29){
            return 29-date.tm_mday; 
        }
    }

    //if not leapYear
    if(date.tm_mon == 1 && (date.tm_mday + 15) > 28){
        return 28-date.tm_mday;         
    }

    if(date.tm_mon < 7 && byte[0] != 1 && (date.tm_mday + 15) > 31){
        return 31 - date.tm_mday;
    }
    if(date.tm_mon >= 7 && byte[0] == 1 && (date.tm_mday + 15) > 30){
        return 30 - date.tm_mday;
    }

    return 0;
}

void book::allIssuers(){
    members personalDetail;

    for(auto person : issures){

        cout<<"book - "<<bookName<<"\n"
        <<"id - "<<person.first<<"\n";

       
        personalDetail.isValidMember(person.first);

        cout<<"From - "<<person.second.first.tm_mday<<" / "
            <<person.second.first.tm_mon<<" / "
            <<person.second.first.tm_year<<"\n";

        cout<<"To - "<<person.second.second.tm_mday<<" / "
            <<person.second.first.tm_mon<<" / "
            <<person.second.second.tm_year<<"\n";
    }
}

int book::returnBook(int id) {
    auto it = issures.find(id);
    if (it == issures.end()) {
        cout << "No such issuer found!\n";
        return -1; // or some error code
    }

    tm expiryDate = it->second.second;

    time_t systemDate = time(0);
    tm currentDate = *localtime(&systemDate);

    int fine = calculateFine(expiryDate, currentDate);

    issures.erase(it); // Remove the user from issuers
    current_count++;   // Increase available count back

    if (fine > 0) {
        cout << "Book returned late! Fine: ₹" << fine << "\n";
    } else {
        cout << "Book returned successfully. No fine.\n";
    }

    
    return fine;
}


int calculateFine(tm expiryDate, tm currentDate) {
    time_t expiry = mktime(&expiryDate);
    time_t current = mktime(&currentDate);

    double secondsDiff = difftime(current, expiry);
    int daysLate = static_cast<int>(secondsDiff / (60 * 60 * 24)); // convert seconds to days

    if (daysLate <= 0) {
        return 0; // No fine if returned on or before due date
    }

    int finePerDay = 10; // 💸 Example: ₹10 fine per day late
    return daysLate * finePerDay;
}