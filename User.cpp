#include <iostream>
#include "BankSys.cpp"
class User : public BankSys
{
public:
    void openFile()
    {
        ifstream file("data.txt");
        if (file.is_open())
        {
            string line;
            int i = 0;
            while (getline(file, line))
            {
                // insert data into array, split by comma
                EmpName[i] = line.substr(0, line.find(","));
                EmpID[i] = line.substr(line.find(",") + 1);
                i++;
            }
        }
        file.close();
    }
    void saveFile()
    {
        ofstream myfile("data.txt");
        for (int i = 0; i < maxrow; i++)
        {
            if (EmpID[i] == "\0")
            {
                break;
            }
            else
            {
                myfile << EmpID[i] << "," << EmpName[i] << endl;
            }
        }
    }
    void display()
    {
        cout << "Your name: " << getName << endl;
        cout << "Your Account Number: " << getAccountNumber << endl;
        cout << "Your City: " << getCity << endl;
        cout << "Your phone: " << getPhone << endl;
        cout << "Your Balance: " << getBalance << endl;
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
int main()
{
    int option;
    User p;
    do
    {
        p.Menu();
        cin >> option;
        switch (option)
        {
        case 1:
            p.display;
            break;
        case 2:;
            break;
        case 3:;
            break;
        case 4:;
            break;
        case 5:
            break;
        default:
            cout << "SAI ROI`" << endl;
            break;
        }
    } while (option != 5);
    saveFile();
    cout << "Saving ";
    // delay 1 second
    for (int i = 1; i <= 4; i++)
    {
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(700));
    }
    cout << endl;
    cout << "Done";
    return 0;
}
