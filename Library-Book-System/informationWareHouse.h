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
    book *requiredBook = ptrToBook->second;
    requiredBook->issuedTo(id);
    return true;
}

informationWareHouse::~informationWareHouse()
{
}
