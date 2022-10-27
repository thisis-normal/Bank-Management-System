#include <iostream>
#include "BankSys.cpp"
#include "Access.cpp"
using namespace std;
class Admin : public BankSys, public AccessControl
{
private:
    string accountType;

public:
    // initialization
    Admin() {}
    Admin(string accountType) { this->accountType = accountType; }
    // getter
    string getAccountType()
    {
        return accountType;
    }
    // setter
    void setAccoutType(string accountType)
    {
        this->accountType = accountType;
    }
    void Create(){};
    void Display(){};
    void Search(){};
    void Update(){};
    void Delete(){};
    void Deposit(){};
    void Withdraw(){};
    void Transaction(){};
    void OpenFile(){};
    void SaveFile(){};
    void menu()
    {
        printf("+---------------------------------------------------------------------+\n");
        printf("|		             ADMIN MANANGEMENT PROGRAM                        |\n");
        printf("+---------------------------------------------------------------------+\n");
        printf("|1.  Create  |2.  Display  |3.  Search   |4.  Update   |5.  Delete    |\n");
        printf("+---------------------------------------------------------------------+\n");
        printf("|6.  Deposit  |7.  Withdraw   |8.  Transaction   |9.  Exit and Save   |\n");
        printf("+---------------------------------------------------------------------+\n");
        cout << "Enter your option: ";
    };
};
