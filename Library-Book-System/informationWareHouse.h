#include "book.h"

class informationWareHouse
{
private:
    unordered_map<string, book *> allBooks;
public:
    informationWareHouse();
    ~informationWareHouse();

    bool addBook();
    bool issueBook(string bookname, int id); // to develop
};

informationWareHouse::informationWareHouse()
{
}

bool informationWareHouse::addBook(){
    string bookName;
    cout<<"Name of the new Book /- ";
    getline(cin, bookName);

    int totalCount;
    cout<<"number of books avilable /- ";
    cin>>totalCount;

    book *obj;
    obj->addNewBook(bookName, totalCount);

    allBooks[bookName] = obj;
    return true;
}



//issue main driver Function 
bool informationWareHouse::issueBook(string bookName, int id){
    auto ptrToBook = allBooks.find(bookName);
    
    if(ptrToBook == allBooks.end()){
        return false;
    }
    book *requiredBook = ptrToBook->second;
    requiredBook->issuedTo(id);
    cout<<"Not a valid member!";
    return true;
}

informationWareHouse::~informationWareHouse()
{
}
