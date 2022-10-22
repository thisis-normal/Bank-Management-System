#include <bits/stdc++.h>
#include <chrono>
using namespace std;
const int maxrow = 20;
string EmpName[maxrow] = {};
string EmpID[maxrow] = {};
void Add()
{
    string name;
    string empID;
    cout << "Name: ";
    getline(cin >> ws, name);
    cout << "Empno: ";
    getline(cin, empID);
    if (name.empty() || empID.empty())
    {
        cout << "Name or EmpID cannot be empty" << endl;
        return;
    }
    for (int i = 0; i < maxrow; i++)
    {
        if (EmpName[i].empty())
        {
            EmpName[i] = name;
            EmpID[i] = empID;
            cout << "Added successfully" << endl;
            return;
        }
    }
}
void Display()
{
    int count = 0;
    cout << "Here is the list: " << endl;
    printf("+---------------------------------------------------------------------+\n");
    printf("| %-10s | %-13s | %-15s |\n", "Order Num", "Employee's ID", "Employee's Name");
    for (int i = 0; i < maxrow; i++)
    {
        if (EmpID[i] != "\0")
        {
            printf("| %-10d | %-13s | %-15s |", (i + 1), EmpID[i].c_str(), EmpName[i].c_str());
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
void Search()
{
    string ID;
    cout << "ID: ";
    getline(cin >> ws, ID);
    int count = 0;
    cout << "Here is the results" << endl;
    cout << " No. |  Name      |   EmpID    " << endl;
    for (int i = 0; i < maxrow; i++)
    {
        if (EmpID[i] == ID)
        {
            cout << "   " << i + 1 << " | " << EmpName[i] << "          |      " << EmpID[i] << endl;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "==> No records found" << endl;
    }
}
void Update()
{
    string ID;
    cout << "ID: ";
    getline(cin >> ws, ID);
    int count = 0;
    cout << "Here is the results" << endl;
    cout << " No. |  Name      |   EmpID    " << endl;
    for (int i = 0; i < maxrow; i++)
    {
        if (EmpID[i] == ID)
        {
            cout << "   " << i + 1 << " | " << EmpName[i] << "          |      " << EmpID[i] << endl;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "==> No records found" << endl;
    }
    else
    {
        string name;
        cout << "Name: ";
        getline(cin >> ws, name);
        for (int i = 0; i < maxrow; i++)
        {
            if (EmpID[i] == ID)
            {
                EmpName[i] = name;
            }
        }
        cout << "Updated successfully" << endl;
    }
}
void Delete()
{
    string ID;
    cout << "ID: ";
    getline(cin >> ws, ID);
    int count = 0;
    cout << "Here is the results" << endl;
    cout << " No. |  Name      |   EmpID    " << endl;
    for (int i = 0; i < maxrow; i++)
    {
        if (EmpID[i] == ID)
        {
            cout << "   " << i + 1 << " | " << EmpName[i] << "          |      " << EmpID[i] << endl;
            count++;
        }
    }
    if (count == 0)
    {
        cout << "==> No records found" << endl;
    }
    else
    {
        for (int i = 0; i < maxrow; i++)
        {
            if (EmpID[i] == ID)
            {
                EmpName[i] = "";
                EmpID[i] = "";
                cout << "Deleted successfully" << endl;
                break; // only delete the first record
            }
        }
    }
}
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
void Menu()
{
    printf("+---------------------------------------------------------------------+\n");
    printf("|		            BANK MANAGEMENT PROGRAM                           |\n");
    printf("+---------------------------------------------------------------------+\n");
    printf("|1.Create |2. Update |3.Delete |4.Search |5.Display |6. Exit and save |\n");
    printf("+---------------------------------------------------------------------+\n");
    cout << "Enter your option: ";
}

int main()
{
    cout << "MENU: " << endl;
    int option;
    fstream myfile;
    openFile();
    do
    {
        Menu();
        cin >> option;
        switch (option)
        {
        case 1:
            Add();
            break;
        case 2:
            Update();
            break;
        case 3:
            Delete();
            break;
        case 4:
            Search();
            break;
        case 5:
            Display();
            break;
        case 6:
            break;
        default:
            cout << "SAI ROI`" << endl;
            break;
        }
    } while (option != 6);
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