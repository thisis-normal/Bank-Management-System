#include "Access.cpp"
#include "Access_db.cpp"
int main()
{
    cout << "Sign In To Our Project!" << endl;
    AccessControl a1;
    openFile();
    a1.signUp();
    a1.validate();
    saveFile();
    Display();
    return 0;
};