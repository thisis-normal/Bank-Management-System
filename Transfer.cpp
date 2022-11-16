#include "Admin.cpp"
#include "User.cpp"
using namespace std;

void OpenFileTransac()
{
    ifstream file("transactions.txt");
    if (file.is_open())
    {
        string line;
        int i = 0;
        int countLine = 0;
        while (getline(file, line))
        {
            // insert data into array, split by comma
            istringstream iss(line);
            getline(iss, giverPhone[i], ',');
            getline(iss, receiverPhone[i], ',');
            getline(iss, amount[i]);
            i++;
            countLine++;
        }
    }
    file.close();
}
void SaveFileTransac()
{
    ofstream myfile("transactions.txt");
    for (int i = 0; i < maxrow; i++)
    {
        if (giverPhone[i] == "\0")
        {
            break;
        }
        else
        {
            myfile << giverPhone[i] << "," << receiverPhone[i] << "," << amount[i] << endl;
        }
    }
}
class Transfer : public Admin, public User
{
public:
    Transfer(){};
    void transactHistory(string giverPhone[], string receiverPhone[], string amount[], string phone)
    {
        int count = 0;
        for (int i = 0; i < maxrow; i++)
        {
            if (giverPhone[i] == phone)
            {
                cout << giverPhone[i] << " " << receiverPhone[i] << " " << amount[i] << endl;
                count++;
            }
        }
        if (count == 0)
        {
            cout << "===> No transaction history" << endl;
        }
    }
    void display(string giverPhone[], string receiverPhone[], string amount[])
    {
        for (int i = 0; i < maxrow; i++)
        {
            if (giverPhone[i] == "\0")
            {
                break;
            }
            else
            {
                cout << giverPhone[i] << " " << receiverPhone[i] << " " << amount[i] << endl;
            }
        }
    }
};