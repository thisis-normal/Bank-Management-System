#include "Access.cpp"
#include "Access_db.cpp"
#include "User.cpp"
#include "Admin.cpp"
void delayDot(unsigned int seconds)
{
    for (int i = 0; i < seconds; i++)
    {
        cout << ".";
        this_thread::sleep_for(chrono::milliseconds(700));
    }
}
int main()
{
    cout << "Sign In To Our Project!" << endl;
    AccessControl a1;
    openFileAccess();
    a1.signIn();
    a1.validateSignIn();
    system("cls");
    if (a1.getRoleByaccessPhone(a1.getaccessPhone()) == "admin")
    {
        cout << "Welcome ADMIN" << a1.getaccessPhone() << "!" << endl;
        OpenFileAdmin();
        Admin admin;
        int choice;
        do
        {
            adminMenu();
            cin >> choice;
            switch (choice)
            {
            case 1:
                admin.searchPhoneAccess(a1);
                break;
            case 2:
                system("cls");
                admin.Display();
                cout << endl;
                break;
            case 3:
                system("cls");
                admin.Search();
                cout << endl;
                break;
            case 4:
                system("cls");
                admin.Update();
                break;
            case 5:
                system("cls");
                admin.Delete();
                break;
            case 6:
                admin.Deposit();
                break;
            // case 7:
            //     admin.deleteUser();
            //     break;
            // case 8:
            //     admin.updateUser();
            //     break;
            case 9:
                cout << "Saving data to file..." << endl;
                cout << "Thank you for using our project!" << endl;
                delayDot(3);
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
            }
        } while (choice != 9);
        SaveFileAdmin();
    }
    else if (a1.getRoleByaccessPhone(a1.getaccessPhone()) == "user")
    {
        cout << "Welcome USER" << a1.getaccessPhone() << "!" << endl;
        openFileUser();
        User user;
        int choice;
        do
        {
            userMenu();
            cin >> choice;
            switch (choice)
            {
            case 1:
                user.displayWtPhone(&a1);
                break;
            case 2:
                user.depositMoney(&a1);
                break;
            case 3:
                user.withdrawMoney(&a1);
                break;
            case 4:
                user.tranferMoney(&a1);
                break;
            case 5:
                cout << "Exit" << endl;
                break;
            default:
                system("cls");
                cout << "Invalid option, please try again" << endl;
                break;
            }
        } while (choice != 5);
        saveFileUser();
        cout << "Saving ";
        delayDot(5);
        cout << " Done!" << endl;
        cout << "Thank you for using our program!" << endl;
    }
    else
    {
        cout << "Invalid Phone or Password!" << endl;
    }
    saveFileAccess();
    return 0;
}
