#include <bits/stdc++.h>
#include "BankSys.cpp"
#pragma once
void openFileUser()
{
    ifstream file("humanDB.txt");
    if (file.is_open())
    {
        string line;
        int i = 0;
        int countLine = 0;
        while (getline(file, line))
        {
            // insert data into array, split by comma
            istringstream iss(line);
            getline(iss, bankName[i], ',');
            getline(iss, bankBalance[i], ',');
            getline(iss, bankPhone[i], ',');
            getline(iss, bankCity[i], ',');
            getline(iss, bankAccountNumber[i]);
            i++;
            countLine++;
        }
        // while (getline(file, line))
        // {
        //     // insert data into array, split by comma
        //     istringstream iss(line);
        //     getline(iss, bankName[i], ',');
        //     getline(iss, bankName[i], ',');
        //     getline(iss,  bankPhone[i]), ',';
        //     getline(iss, bankCity[i]), ',';
        //     getline(iss, bankAccountNumber[i]);
        //     i++;
        //     countLine++;
        // }
        // read all data from file
        for (int i = 0; i < countLine; i++)
        {
            cout << bankName[i] << " " << bankBalance[i] << " " << bankPhone[i] << " " << bankCity[i] << " " << bankAccountNumber[i] << endl;
        }
    }
    file.close();
}
void saveFileUser()
{
    ofstream myfile("humanDB.txt");
    for (int i = 0; i < maxrow; i++)
    {
        if (bankName[i] == "\0")
        {
            break;
        }
        else
        {
            myfile << bankName[i] << "," << bankBalance[i] << "," << bankPhone[i] << "," << bankCity[i] << "," << bankAccountNumber[i] << endl;
        }
    }
}
class User : public BankSys
{
public:
    void display()
    {
        int count = 0;
        cout << "Here is the list: " << endl;
        printf("+---------------------------------------------------------------------+\n");
        for (int i = 0; i < maxrow; i++)
        {
            if (bankName[i] != "\0")
            {
                cout << "Name: " << bankName[i] << "||"
                     << "Balance: " << bankBalance[i] << "||"
                     << "Phone: " << bankPhone[i] << "||"
                     << "City: " << bankCity[i] << "||"
                     << "AccountNumber: " << bankAccountNumber[i] << endl;
                // printf("| %-12s | %-5s | %-10s | %-10s | %-10s |", bankName[i].c_str(), bankBalance[i].c_str(),  bankPhone[i].c_str(), bankCity[i].c_str(), bankAccountNumber[i].c_str());
                cout << endl;
                count++;
            }
        }
        cout << "======================" << endl;
        cout << "Total records: " << count << endl;
        if (count == 0)
        {
            cout << "==> No records found" << endl;
        }
    }
    //  deposit money to account with phone number
    void depositMoney(AccessControl *access)
    {
        string phone = access->getaccessPhone();
        cout << "DEMO: " << phone << endl;
        bool check = false;
        for (int i = 0; i < maxrow; i++)
        {
            if (bankPhone[i] == phone)
            {
                double balance = stod(bankBalance[i]);
                cout << "Demo balance: " << balance << endl;
                double deposit;
                cout << "Enter deposit money: ";
                cin >> deposit;
                balance += deposit;
                bankBalance[i] = to_string(balance);
                cout << "Deposit successfully" << endl;
                cout << "New balance: " << bankBalance[i] << endl;
                check == true;
                break;
            }
        }
        if (check == false)
        {
            cout << "==> Phone number not found" << endl;
        }
    }
    //  using setInformation::BankSys;
    void setInformation()
    {
        BankSys::setInformation();
        for (int i = 0; i < maxrow; i++)
        {
            if (bankName[i] == "\0")
            {
                bankName[i] = getName();
                bankBalance[i] = getBalance();
                bankPhone[i] = getPhone();
                bankCity[i] = getCity();
                bankAccountNumber[i] = getAccountNumber();
                break;
            }
        }
    }
    void Menu()
    {
        printf("+---------------------------------------------------------------------+\n");
        printf("|		             USER MANANGEMENT PROGRAM                         |\n");
        printf("+---------------------------------------------------------------------+\n");
        printf("|1. Display  |2. Deposit  |3. Withdraw  |4. Transaction  |5.  Exit    |\n");
        printf("+---------------------------------------------------------------------+\n");
        cout << "Enter your option: ";
    }
};
void delayDot(unsigned int seconds)
{
    for (int i = 0; i < seconds; i++)
    {
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(700));
    }
}