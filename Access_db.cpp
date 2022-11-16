#include "Access.cpp"
void openFileAccess()
{
    ifstream file("Account.txt");
    if (file.is_open())
    {
        string line;
        int i = 0;
        int countLine = 0;
        while (getline(file, line))
        {
            // insert data into array, split by comma
            istringstream iss(line);
            getline(iss, AccessPhone[i], ',');
            getline(iss, AccessPass[i], ',');
            getline(iss, AccessRole[i]);
            i++;
            countLine++;
        }
        // // read all data from file
        // for (int i = 0; i < countLine; i++)
        // {
        //     cout << AccessPhone[i] << " " << AccessPass[i] << " " << AccessRole[i] << endl;
        // }
    }
    file.close();
}
void saveFileAccess()
{
    // save file
    ofstream myfile("Account.txt");
    for (int i = 0; i < maxrow; i++)
    {
        if (AccessPhone[i] == "\0")
        {
            break;
        }
        else
        {
            myfile << AccessPhone[i] << "," << AccessPass[i] << "," << AccessRole[i] << endl;
        }
    }
}
void Display()
{
    int count = 0;
    cout << "Here is the list: " << endl;
    printf("+---------------------------------------------------------------------+\n");
    printf("| %-12s | %-15s | %-10s |\n", "Phone", "Password", "Role");
    for (int i = 0; i < maxrow; i++)
    {
        if (AccessPhone[i] != "\0")
        {
            printf("| %-12s | %-15s | %-10s |", AccessPhone[i].c_str(), AccessPass[i].c_str(), AccessRole[i].c_str());
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
