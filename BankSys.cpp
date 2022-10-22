#include <iostream>
using namespace std;
class BankSys
{
private:
    string name;
    double balance;
    string phone;
    string city;
    string accountNumber;

public:
    // initialization
    BankSys() {}
    BankSys(string name, double balance, string phone, string city, string accountNumber)
    {
        this->name = name;
        this->balance = balance;
        this->phone = phone;
        this->city = city;
        this->accountNumber = accountNumber;
    }
    // getter
    string getName()
    {
        return name;
    }
    double getBalance()
    {
        return balance;
    }
    string getPhone()
    {
        return phone;
    }
    string getCity()
    {
        return city;
    }
    string getAccountNumber()
    {
        return accountNumber;
    }
    // setter
    void setName(string name)
    {
        this->name = name;
    }
    void setBalance(double balance)
    {
        this->balance = balance;
    }
    void setPhone(string phone)
    {
        this->phone = phone;
    }
    void setCity(string city)
    {
        this->city = city;
    }
    void setAccountNumber(string accountNumber)
    {
        this->accountNumber = accountNumber;
    }
    virtual void setInformation()
    {
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Balance: ";
        cin >> balance;
        cout << "Phone: ";
        cin.ignore();
        getline(cin, phone);
        cout << "City: ";
        cin.ignore();
        getline(cin, city);
        cout << "Account Number: ";
        cin.ignore();
        getline(cin, accountNumber);
    }
    virtual void display()
    {
        cout << "Your name: " << name << endl;
        cout << "Balance: " << balance << endl;
        cout << "Your phone: " << phone << endl;
        cout << "City: " << city << endl;
        cout << "Account Number: " << accountNumber << endl;
    }
};