#include "BankSys.cpp"
#include "Access.cpp"
#pragma once
using namespace std;

void OpenFileAdmin()
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
    }
    file.close();
}
void SaveFileAdmin()
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
void adminMenu()
{
    printf("+---------------------------------------------------------------------+\n");
    printf("|                       ADMIN MANAGEMENT PROGRAM                      |\n");
    printf("+---------------------------------------------------------------------+\n");
    printf("|1. Create | 2. Display |3. Search |4. Update |5. Delete | 6. Deposit |\n");
    printf("+---------------------------------------------------------------------+\n");
    printf("|7. Withdraw | 8. Transaction | 9. Trans's history |10. Exit and Save |\n");
    printf("+---------------------------------------------------------------------+\n");
    cout << "Enter your option: ";
}
class Admin : public BankSys
{
public:
    // initialization
    Admin(){};
    void Create(string accessPhone)
    {
        cin.ignore();
        BankSys::setInformation();
        for (int i = 0; i < maxrow; i++)
        {
            if (bankName[i] == "\0")
            {
                bankName[i] = getName();
                bankBalance[i] = getBalance();
                bankPhone[i] = accessPhone;
                bankCity[i] = getCity();
                bankAccountNumber[i] = getAccountNumber();
                break;
            }
        }
    }
    void searchPhoneAccess(AccessControl &ac)
    {
        string accessPhone;
        cout << "Enter phone number: ";
        cin >> accessPhone;
        for (int i = 0; i < maxrow; i++)
        {
            if (accessPhone == AccessPhone[i])
            {
                cout << "accessPhone number is existed" << endl;
                cout << "You can create new information for this accessPhone number" << endl;
                Create(accessPhone);
                return;
            }
        }
        cout << "accessPhone number is not existed" << endl;
        cout << "Do you want to create new accessPhone number? (y/n): ";
        string choice;
        cin >> choice;
        if (choice == "y" || choice == "Y")
        {
            cin.ignore();
            ac.signUp();
            ac.validateSignUp();
        }
    }
    void Search()
    {
        string phone;
        cout << "Enter phone number: ";
        getline(cin, phone);
        int count = 0;
        for (int i = 0; i < maxrow; i++)
        {
            if (bankPhone[i] == phone)
            {
                cout << "Name: " << bankName[i] << endl;
                cout << "Balance: " << bankBalance[i] << endl;
                cout << "Phone: " << bankPhone[i] << endl;
                cout << "City: " << bankCity[i] << endl;
                cout << "Account Number: " << bankAccountNumber[i] << endl;
                count++;
                break;
            }
        }
        if (count == 0)
        {
            cout << "Cannot find phone number" << endl;
        }
    };
    void Update()
    {
        string phone;
        cout << "Enter phone number: ";
        cin.ignore();
        getline(cin, phone);
        int count = 0;
        for (int i = 0; i < maxrow; i++)
        {
            if (bankPhone[i] == phone)
            {
                cout << "Name: " << bankName[i] << endl;
                cout << "Phone: " << bankPhone[i] << endl;
                cout << "City: " << bankCity[i] << endl;
                cout << "Account Number: " << bankAccountNumber[i] << endl;
                cout << endl;
                cout << "Enter new name: ";
                getline(cin, bankName[i]);
                cout << "Enter new phone: ";
                getline(cin, bankPhone[i]);
                cout << "Enter new city: ";
                getline(cin, bankCity[i]);
                cout << "Enter new account number: ";
                getline(cin, bankAccountNumber[i]);
                count++;
                break;
            }
        }
        if (count == 0)
        {
            cout << "Cannot find phone number" << endl;
        }
    }
    void Delete()
    {
        string phone;
        cout << "Enter phone number: ";
        cin.ignore();
        getline(cin, phone);
        int count = 0;
        for (int i = 0; i < maxrow; i++)
        {
            if (bankPhone[i] == phone)
            {
                cout << "Are you sure you want to delete this account? (Y/N): ";
                char choice;
                cin >> choice;
                if (choice == 'Y' || choice == 'y')
                {
                    bankName[i] = "\0";
                    bankBalance[i] = "\0";
                    bankPhone[i] = "\0";
                    bankCity[i] = "\0";
                    bankAccountNumber[i] = "\0";
                    count++;
                    break;
                }
                else
                {
                    break;
                }
            }
        }
        if (count != 0)
        {
            cout << "Delete successfully" << endl;
        }
        else
        {
            cout << "Cannot find phone number" << endl;
        }
    }
    void Deposit()
    {
        string phone;
        cout << "Enter phone number: ";
        cin.ignore();
        getline(cin, phone);
        int count = 0;
        for (int i = 0; i < maxrow; i++)
        {
            if (bankPhone[i] == phone)
            {
                cout << "Name: " << bankName[i] << endl;
                cout << "Your current balance: " << bankBalance[i] << endl;
                cout << "Enter amount to deposit: ";
                int amount;
                cin >> amount;
                if (amount < 0)
                {
                    cout << "Invalid amount" << endl;
                    break;
                }
                else
                {
                    bankBalance[i] = to_string(stoi(bankBalance[i]) + amount);
                    cout << "Deposit successfully" << endl;
                    cout << "Your new balance: " << bankBalance[i] << endl;
                    count++;
                    break;
                }
            }
        }
        if (count == 0)
        {
            cout << "Cannot find phone number" << endl;
        }
    };
    void Withdraw()
    {
        string phone;
        cout << "Enter phone number: ";
        cin.ignore();
        getline(cin, phone);
        int count = 0;
        for (int i = 0; i < maxrow; i++)
        {
            if (bankPhone[i] == phone)
            {
                cout << "Name: " << bankName[i] << endl;
                cout << "Your current balance: " << bankBalance[i] << endl;
                cout << "Enter amount to withdraw: ";
                int amount;
                cin >> amount;
                if (amount < 0)
                {
                    cout << "Invalid amount" << endl;
                    break;
                }
                else if (amount > stoi(bankBalance[i]))
                {
                    cout << "Not enough money" << endl;
                    break;
                }
                else
                {
                    bankBalance[i] = to_string(stoi(bankBalance[i]) - amount);
                    cout << "Withdraw successfully" << endl;
                    cout << "Your new balance: " << bankBalance[i] << endl;
                    count++;
                    break;
                }
            }
        }
        if (count == 0)
        {
            cout << "Cannot find phone number" << endl;
        }
    }
    void Transaction(BankSys &bs)
    {
        // check if both phone number is existed
        string phone1, phone2;
        cout << "Enter giver phone number: ";
        cin.ignore();
        getline(cin, phone1);
        cout << "Enter receiver phone number: ";
        getline(cin, phone2);
        string amount;
        cout << "Enter amount to transfer: ";
        getline(cin, amount);
        int amountInt = stoi(amount);
        if (amountInt < 0)
        {
            cout << "==> Invalid amount" << endl;
        }
        bs.transfer(phone1, phone2, amount);
    }
    void Display()
    {
        int count = 0;
        cout << "Here is the list: " << endl;
        printf("+---------------------------------------------------------------------+\n");
        printf("| %-13s | %-6s | %-10s | %-10s | %-15s |\n", "Name", "Balance", "Phone", "City", "Account Number");
        printf("|---------------------------------------------------------------------|\n");
        for (int i = 0; i < maxrow; i++)
        {
            if (bankName[i] != "\0")
            {
                printf("| %-13s | %-7s | %-10s | %-10s | %-15s |", bankName[i].c_str(), bankBalance[i].c_str(), bankPhone[i].c_str(), bankCity[i].c_str(), bankAccountNumber[i].c_str());
                cout << endl;
                count++;
            }
        }
        cout << "=======================================================================" << endl;
        cout << "Total records: " << count << endl;
        if (count == 0)
        {
            cout << "==> No records found" << endl;
        }
    }
};