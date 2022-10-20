#include <bits/stdc++.h>
using namespace std;
class BankSys
{
private:
    string customerName;
    double balance;
    string accountNumber;

public:
    BankSys() {}
    BankSys(string customerName, double balance, string accountNumber)
    {
        this->customerName = customerName;
        this->balance = balance;
        this->accountNumber = accountNumber;
    }
    // all getter
    string getCustomerName()
    {
        return customerName;
    }
    double getBalance()
    {
        return balance;
    }
    string getAccountNumber()
    {
        return accountNumber;
    }
    // all setter
    void setCustomerName(string customerName)
    {
        this->customerName = customerName;
    }
    void setBalance(double balance)
    {
        this->balance = balance;
    }
    void setAccountNumber(string accountNumber)
    {
        this->accountNumber = accountNumber;
    }
    // all methods
    virtual void display()
    {
        cout << "Customer Name: " << customerName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Account Number: " << accountNumber << endl;
    }
};
