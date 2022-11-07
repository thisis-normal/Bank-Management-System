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
void userMenu()
{
    cout << "+----------------------------------------------------------------------+" << endl;
    cout << "|                      USER MANANGEMENT PROGRAM                        |" << endl;
    cout << "+----------------------------------------------------------------------+" << endl;
    cout << "|1. Display |2. Deposit |3. Withdraw  |4. Transaction |5. Exit & Save  |" << endl;
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
    // void displayAll()
    // {
    //     int count = 0;
    //     cout << "Here is the list: " << endl;
    //     printf("+---------------------------------------------------------------------+\n");
    //     for (int i = 0; i < maxrow; i++)
    //     {
    //         if (bankName[i] != "\0")
    //         {
    //             cout << "Name: " << bankName[i] << "||"
    //                  << "Balance: " << bankBalance[i] << "||"
    //                  << "Phone: " << bankPhone[i] << "||"
    //                  << "City: " << bankCity[i] << "||"
    //                  << "AccountNumber: " << bankAccountNumber[i] << endl;
    //             // printf("| %-12s | %-5s | %-10s | %-10s | %-10s |", bankName[i].c_str(), bankBalance[i].c_str(),  bankPhone[i].c_str(), bankCity[i].c_str(), bankAccountNumber[i].c_str());
    //             cout << endl;
    //             count++;
    //         }
    //     }
    //     cout << "======================" << endl;
    //     cout << "Total records: " << count << endl;
    //     if (count == 0)
    //     {
    //         cout << "==> No records found" << endl;
    //     }
    // }
    //  deposit money to account with phone number
    void depositMoney(AccessControl *access)
    {
        string phone = access->getaccessPhone();
        int count = 0;
        for (int i = 0; i < maxrow; i++)
        {
            if (bankPhone[i] == phone)
            {
                int balance = stoi(bankBalance[i]);
                cout << "Your current balance: " << balance << endl;
                int deposit;
                cout << "Enter deposit money: ";
                cin >> deposit;
                balance += deposit;
                bankBalance[i] = to_string(balance);
                cout << "Deposit successfully" << endl;
                cout << "New balance: " << bankBalance[i] << endl;
                count++;
                break;
            }
        }
        if (count == 0)
        {
            cout << "==> No records found" << endl;
        }
    }
    void withdrawMoney(AccessControl *access)
    {
        string phone = access->getaccessPhone();
        for (int i = 0; i < maxrow; i++)
        {
            if (bankPhone[i] == phone)
            {
                int balance = stoi(bankBalance[i]);
                if (balance < 50)
                {
                    cout << "==> Your balance must be more than 50 to withdraw" << endl;
                    break;
                }
                cout << "Your current balance: " << balance << endl;
                int withdraw;
                cout << "Enter withdraw money: ";
                cin >> withdraw;
                balance -= withdraw;
                bankBalance[i] = to_string(balance);
                cout << "Withdraw successfully!" << endl;
                cout << "New balance: " << bankBalance[i] << endl;
                break;
            }
        }
    }
    //  using setInformation::BankSys; (maybe in admin)

    void tranferMoney(AccessControl *access)
    {
        // check if both phone number exist
        string phone = access->getaccessPhone();
        string destiPhone;
        cout << "Enter destination phone: ";
        cin.ignore();
        getline(cin, destiPhone);
        int count = 0;
        for (int i = 0; i < maxrow; i++)
        {
            if (bankPhone[i] == destiPhone)
            {
                count++;
            }
        }
        if (count == 0)
        {
            cout << "==> Destination phone number does not exist" << endl;
            return;
        }
        else
        {
            if (phone == destiPhone)
            {
                cout << "==> You cannot transfer money to yourself" << endl;
                return;
            }
            else
            {
                int money;
                cout << "Enter money: ";
                cin >> money;
                for (int i = 0; i < maxrow; i++)
                {
                    if (bankPhone[i] == phone)
                    {
                        int balance = stoi(bankBalance[i]);
                        if (balance <= 0)
                        {
                            cout << "==> Your balance must be more than 0 to tranfer" << endl;
                            return;
                        }
                        if (money > balance)
                        {
                            cout << "==> Your balance is not enough to transfer" << endl;
                            break;
                        }
                        balance -= money;
                        bankBalance[i] = to_string(balance);
                        cout << "Successfully decrease your balance" << endl;
                        break;
                    }
                }
                for (int i = 0; i < maxrow; i++)
                {
                    if (bankPhone[i] == destiPhone)
                    {
                        int balance = stoi(bankBalance[i]);
                        balance += money;
                        bankBalance[i] = to_string(balance);
                        cout << "Successfully increase destination balance" << endl;
                        break;
                    }
                }
            }
        }
    }
};
