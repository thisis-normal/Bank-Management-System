#include "Access.cpp"
#include "Access_db.cpp"
#include "User.cpp"
int main()
{
    cout << "Sign In To Our Project!" << endl;
    AccessControl a1;
    openFileAccess();
    // cout << "Set phone: " << endl;
    // a1.setPhone("3");
    a1.signIn();
    a1.validateSignIn();
    // if sign in as admin then go to admin page, if sign in as user then go to user page
    if (a1.getRoleByaccessPhone(a1.getaccessPhone()) == "admin")
    {
        cout << "Welcome Admin!" << endl;
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
                cout << "Invalid choice" << endl;
                break;
            }
        } while (choice != 5);
        saveFileUser();
        cout << "Saving ";
        delayDot(5);
        cout << "Done!" << endl;
        cout << "Thank you for using our program!" << endl;
    }
    else
    {
        cout << "Invalid Phone or Password!" << endl;
    }
    saveFileAccess();
    return 0;
}
