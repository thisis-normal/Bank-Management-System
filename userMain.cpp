#include <bits/stdc++.h>
#include "BankSys.cpp"
#include "User.cpp"
using namespace std;
int main()
{
    int option;
    User user;
    openFileUser();
    user.depositMoney();
    // saveFile();
    user.display();
    // do
    // {
    //     p.Menu();
    //     cin >> option;
    //     switch (option)
    //     {
    //     case 1:
    //         p.display();
    //         break;
    //     case 2:;
    //         break;
    //     case 3:;
    //         break;
    //     case 4:;
    //         break;
    //     case 5:
    //         break;
    //     default:
    //         cout << "SAI ROI`" << endl;
    //         break;
    //     }
    // } while (option != 5);
    saveFileUser();
    cout << "Saving ";
    // delay 1 second
    // delayDot(3);
    // cout << endl;
    // cout << "Done";
    return 0;
}
