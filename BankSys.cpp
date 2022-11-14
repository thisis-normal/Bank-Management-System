#include <bits/stdc++.h>
#include "Access.cpp"
using namespace std;
#pragma once
string bankName[maxrow] = {};
string bankBalance[maxrow] = {};
string bankPhone[maxrow] = {};
string bankCity[maxrow] = {};
string bankAccountNumber[maxrow] = {};
string giverPhone[maxrow] = {};
string receiverPhone[maxrow] = {};
string amount[maxrow] = {};
class BankSys : public AccessControl
{
private:
    string name;
    string balance;
    string phone;
    string city;
    string accountNumber;
    string giverPhone;
    string receiverPhone;
    string amount;

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
    string getGiverPhone()
    {
        return giverPhone;
    }
    string getReceiverPhone()
    {
        return receiverPhone;
    }
    string getAmount()
    {
        return amount;
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
    void setGiverPhone(string giverPhone)
    {
        this->giverPhone = giverPhone;
    }
    void setReceiverPhone(string receiverPhone)
    {
        this->receiverPhone = receiverPhone;
    }
    void setAmount(string amount)
    {
        this->amount = amount;
    }
    // other methods
    virtual void Transaction(){}; // virtual
    void transferAdmin(string giverPhone, string receiverPhone, string amount)
    {
        int indexGiver = -1;
        int indexReceiver = -1;
        for (int i = 0; i < maxrow; i++)
        {
            if (bankPhone[i] == giverPhone)
            {
                indexGiver = i;
            }
            if (bankPhone[i] == receiverPhone)
            {
                indexReceiver = i;
            }
        }
        if (indexGiver == -1 || indexReceiver == -1)
        {
            cout << "Phone number not found" << endl;
        }
        else if (giverPhone == receiverPhone)
        {
            cout << "You can't transfer to yourself" << endl;
        }
        else
        {
            int balanceGiver = stoi(bankBalance[indexGiver]);
            int balanceReceiver = stoi(bankBalance[indexReceiver]);
            int amountInt = stoi(amount);
            if (balanceGiver < amountInt)
            {
                cout << "You don't have enough money to transfer" << endl;
            }
            else
            {
                balanceGiver -= amountInt;
                balanceReceiver += amountInt;
                bankBalance[indexGiver] = to_string(balanceGiver);
                bankBalance[indexReceiver] = to_string(balanceReceiver);
                // save 2 phone number and amount to file
                ofstream myfile("transactions.txt", ios::app);
                myfile << giverPhone << "," << receiverPhone << "," << amount << endl;
                myfile.close();
                cout << "Transfer successfully" << endl;
            }
        }
    }
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