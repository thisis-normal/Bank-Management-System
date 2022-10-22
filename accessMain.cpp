#include "Access.cpp"
#include "Access_db.cpp"
int main()
{
    cout << "Sign Up To Our Project!" << endl;
    AccessControl a1;
    openFile();
    // cout << "Set phone: " << endl;
    // a1.setPhone("3");
    a1.signIn();
    // if sign in as admin then go to admin page, if sign in as user then go to user page
    if (a1.getRole() == "admin")
    {
        cout << "Welcome to admin page!" << endl;
        // create a object of admin class
        // Admin admin;
        // admin.adminPage();
    }
    else if (a1.getRole() == "user")
    {
        cout << "Welcome to user page!" << endl;
        // create a object of user class
        // User u1;
        // call deposit method in user class
        // u1.deposit();
    }

    saveFile();
    Display();
    return 0;
};