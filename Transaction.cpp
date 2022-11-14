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
        if (bankName[i] == "\0")
        {
            break;
        }
        else
        {
            myfile << giverPhone[i] << "," << receiverPhone[i] << "," << amount[i] << endl;
        }
    }
}
class Transaction : public Admin, public User
{
};
int main()
{
    OpenFileTransac();
    SaveFileTransac();
    return 0;
}