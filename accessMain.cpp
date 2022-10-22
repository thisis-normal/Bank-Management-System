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
    a1.validateSignIn();
    saveFile();
    Display();
    return 0;
};