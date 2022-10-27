#include "Access.cpp"
#include "Access_db.cpp"
#include "User.cpp"
int main()
{
    cout << "Sign Up To Our Project!" << endl;
    AccessControl a1;
    openFile();
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
        cout << "Welcome User!" << endl;
        openFileUser();
        User user;
        user.depositMoney(&a1);
        user.display();
        saveFileUser();
    }
    else
    {
        cout << "Invalid Phone or Password!" << endl;
    }
    saveFile();
    Display();
    return 0;
};