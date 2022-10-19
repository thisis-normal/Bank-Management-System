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
    // getinfor
    void setInformation()
    {
        cout << "Enter customer name: ";
        cin >> customerName;
        cout << "Enter balance: ";
        cin >> balance;
        cout << "Enter account number: ";
        cin.ignore();
        getline(cin, accountNumber);
    }
    void display()
    {
        cout << "Customer Name: " << customerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};
int main()
{
    return 0;
}