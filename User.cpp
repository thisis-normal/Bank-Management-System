#include <bits/stdc++.h>
#include "BankSys.cpp"
#pragma once
void openFileUser()
{
    ifstream file("Data.txt");
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
        // read all data from file
        // for (int i = 0; i < countLine; i++)
        // {
        //     cout << bankName[i] << " " << bankBalance[i] << " " << bankPhone[i] << " " << bankCity[i] << " " << bankAccountNumber[i] << endl;
        // }
    }
    file.close();
}
void saveFileUser()
{
    ofstream myfile("Data.txt");
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
void userMenu()
{
    cout << "+----------------------------------------------------------------------+" << endl;
    cout << "|                      USER MANANGEMENT PROGRAM                        |" << endl;
    cout << "+----------------------------------------------------------------------+" << endl;
    cout << "|    1.  Display       |     2. Deposit             |  3. Withdraw     |" << endl;
    cout << "|    4. Transaction    |     5. Trans's history     |  6. Exit & Save  |" << endl;
    cout << "+----------------------------------------------------------------------+" << endl;
    cout << "Enter your option: ";
}

class User : public BankSys
{
public:
    User(){};
    //  display information of account with phone number
    void displayWtPhone(AccessControl *access)
    {
        string phone = access->getaccessPhone();
        cout << "Here is the information of USER" << phone << endl;
        for (int i = 0; i < maxrow; i++)
        {
            if (bankPhone[i] == phone)
            {
                cout << "Name: " << bankName[i] << endl;
                cout << "Balance: " << bankBalance[i] << endl;
                cout << "Phone: " << bankPhone[i] << endl;
                cout << "City: " << bankCity[i] << endl;
                cout << "Account Number: " << bankAccountNumber[i] << endl;
            }
        }
    }

    void deposit(AccessControl *access)
    {
        string phone = access->getaccessPhone();
        for (int i = 0; i < maxrow; i++)
        {
            if (bankPhone[i] == phone)
            {
                int balance = stoi(bankBalance[i]);
                cout << "Your current balance: " << balance << endl;
                int deposit;
                cout << "Enter deposit money: ";
                cin >> deposit;
                if (deposit < 0)
                {
                    cout << "==> Invalid deposit money" << endl;
                }
                else
                {
                    balance += deposit;
                    bankBalance[i] = to_string(balance);
                    cout << "==> Deposit successfully" << endl;
                    cout << "Your new balance: " << balance << endl;
                    break;
                }
            }
        }
    }
    void withdraw(AccessControl *access)
    {
        string phone = access->getaccessPhone();
        for (int i = 0; i < maxrow; i++)
        {
            if (bankPhone[i] == phone)
            {
                int balance = stoi(bankBalance[i]);
                cout << "Your current balance: " << balance << endl;
                int withdraw;
                cout << "Enter withdraw money: ";
                cin >> withdraw;
                if (withdraw < 0)
                {
                    cout << "==> Invalid withdraw money" << endl;
                }
                else if (withdraw > balance)
                {
                    cout << "==> Your balance is not enough" << endl;
                }
                else
                {
                    balance -= withdraw;
                    bankBalance[i] = to_string(balance);
                    cout << "==> Withdraw successfully" << endl;
                    cout << "Your new balance: " << balance << endl;
                    break;
                }
            }
        }
    }

    void tranferHistory(AccessControl *access)
    {
        string phone = access->getaccessPhone();
        for (int i = 0; i < maxrow; i++)
        {
            if (bankPhone[i] == phone)
            {
                cout << "Name: " << bankName[i] << endl;
                cout << "Balance: " << bankBalance[i] << endl;
                cout << "Phone: " << bankPhone[i] << endl;
                cout << "City: " << bankCity[i] << endl;
                cout << "Account Number: " << bankAccountNumber[i] << endl;
                break;
            }
        }
    }
    void tranfer(AccessControl *access, BankSys &bs)
    {
        // check if both phone number exist
        string giverPhone = access->getaccessPhone();
        string receiverPhone;
        cout << "Enter receiver phone number: ";
        cin.ignore();
        getline(cin, receiverPhone);
        string amount;
        cout << "Enter amount to transfer: ";
        getline(cin, amount);
        int amountInt = stoi(amount);
        if (amountInt < 0)
        {
            cout << "==> Invalid amount" << endl;
        }
        else
        {
            bs.transfer(giverPhone, receiverPhone, amount);
        }
    }
};
