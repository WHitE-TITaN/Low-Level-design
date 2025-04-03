#include "book.h"

class informationWareHouse
{
private:
    unordered_map<string, book *> allBooks;
public:
    informationWareHouse();
    ~informationWareHouse();

    bool addBook();
    bool issueBook(string bookname, string userName); // to develop
};

informationWareHouse::informationWareHouse()
{
}

bool informationWareHouse::addBook(){
    string bookName;
    cin.ignore();
    cout<<"Name of the new Book /- ";
    getline(cin, bookName);

    int totalCount;
    cout<<"number of books avilable /- ";
    cin>>totalCount;
    cin.ignore();

    book *obj;
    obj->addNewBook(bookName, totalCount);

    allBooks[bookName] = obj;
    return true;
}

informationWareHouse::~informationWareHouse()
{
}
