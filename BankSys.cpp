#include <bits/stdc++.h>
#include "Access.cpp"
using namespace std;
#pragma once
string bankName[maxrow] = {};
string bankBalance[maxrow] = {};
string bankPhone[maxrow] = {};
string bankCity[maxrow] = {};
string bankAccountNumber[maxrow] = {};
class BankSys : public AccessControl
{
private:
    string name;
    string balance;
    string phone;
    string city;
    string accountNumber;

public:
    // initialization
    BankSys() {}
    BankSys(string name, string balance, string phone, string city, string accountNumber)
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
    string getBalance()
    {
        return balance;
    }
    int getBalanceInterger()
    {
        return stoi(balance);
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
    void setBalance(string balance)
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
    // other methods
    virtual void setInformation()
    {
        cout << "Name: ";
        getline(cin, name);
        cout << "Balance: ";
        getline(cin, balance);
        cout << "Phone: ";
        getline(cin, phone);
        cout << "City: ";
        getline(cin, city);
        cout << "Account Number: ";
        getline(cin, accountNumber);
    }
    virtual void display() {}
};