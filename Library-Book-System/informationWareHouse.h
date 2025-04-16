#include "book.h"


class informationWareHouse
{
private:
    static unordered_map<string, book *> allBooks;
public:
    informationWareHouse();
    ~informationWareHouse();

    bool addBook();
    bool issueBook(string bookname, int id); // to develop
    void allIssuers(string bookName);
};

unordered_map<string, book *> informationWareHouse::allBooks; //global static variable!

informationWareHouse::informationWareHouse()
{
}

bool informationWareHouse::addBook(){
    string bookName;
    cout<<"Name of the new Book /- ";
    getline(cin, bookName);

    int totalCount;
    cout<<"number of books avilable /- "; 
    cin>>totalCount; cin.ignore();

    book *obj = new book();
    obj->addNewBook(bookName, totalCount);

    allBooks[bookName] = obj;
    return true;
}



//issue main driver Function 
bool informationWareHouse::issueBook(string bookName, int id){
    auto ptrToBook = allBooks.find(bookName);
    
    if(ptrToBook == allBooks.end()){
        cout<<"$ Book not avialble";
        return false;
    }

    members *issueBook;
    if(!issueBook->canIssueBook(id, bookName)){
        return false;
    }

    book *requiredBook = ptrToBook->second;
    if(!requiredBook->issuedTo(id)){
        return false;
    }
    issueBook->haveIssued(id, bookName);

    delete issueBook, requiredBook;
    return true;
}

informationWareHouse::~informationWareHouse()
{
}


void informationWareHouse::allIssuers(string bookName){
    auto locator = allBooks.find(bookName);

    if(locator == allBooks.end()){
        cout<<"no book of the name - "<<bookName;
        return;
    }
    locator->second->allIssuers();
}