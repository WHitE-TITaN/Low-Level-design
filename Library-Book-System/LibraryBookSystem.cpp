#include "members.h"
#include "informationWareHouse.h"

using namespace std;

void allCommands(){
    cout<<"no. function command\n";
    cout<<"1.  add user  /- /au\n"<<
    "2. add book /- /ab\n"<<
    "3. issue Book /- /ib\n"<<
    "4. exit /- /exit\n"<<
    "5. show all commands /- /help\n";
    return;
}

int main(){
    bool SystemOnline = true;

    allCommands();
    while(SystemOnline){
        string Operation;
        cout<<"\n\nlibrary System $ - ";

        getline(cin, Operation);

        if(Operation == "exit"){
            cout<<" -- Have a nice day -- ";
            SystemOnline = false;

            return 0;
        }

        else if(Operation == "au"){
            members *newUser = new members();
            newUser->registerUser();
        }

        else if(Operation == "ab"){
            informationWareHouse *newBook = new informationWareHouse();
            newBook->addBook();
        }

        else if(Operation == "ib"){
            int id;
            string bookName; 
            cout<<"\n Enter id - ";
            cin>>id;
            cin.ignore();

            members *validityCheck = new members();
            if(validityCheck->isValidMember(id)){
                cout<<"\n Enter Book name - ";
                
                getline(cin, bookName);

                informationWareHouse *issueBook = new informationWareHouse();
                issueBook->issueBook(bookName, id);
            }
        }
        else if(Operation == "help"){
            allCommands();
        }
        else{
            allCommands();
        }
    }
}