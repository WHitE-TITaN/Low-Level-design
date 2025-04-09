#include "members.h"
#include "informationWareHouse.h"

using namespace std;

int main(){
    bool SystemOnline = true;

    while(SystemOnline){
        string Operation;
        cout<<"no. function command\n";
        cout<<"1.  add user  /- /au\n"<<
        "2. add book /- /ab\n"<<
        "3. issue Book /- /ib\n"<<
        "4. exit /- /exit";

        cin.ignore();
        getline(cin, Operation);

        if(Operation == "/exit"){
            cout<<" -- Have a nice day -- ";
            SystemOnline = false;

            return 0;
        }

        if(Operation == "/au"){
            members *newUser = new members();
            newUser->registerUser();
        }

        if(Operation == "/ab"){
        
        }
    }
}