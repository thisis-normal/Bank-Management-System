#include <bits/stdc++.h>
#include <sstream>
#pragma once
using namespace std;
const int maxrow = 50;
string AccessPhone[maxrow] = {};
string AccessPass[maxrow] = {};
string AccessRole[maxrow] = {};
class AccessControl
{
private:
    string phone;
    string password;
    string role;

public:
    AccessControl() {}
    AccessControl(string phone, string password, string role)
    {
        this->phone = phone;
        this->password = password;
        this->role = role;
    }
    // getter
    string getPhone()
    {
        return phone;
    }
    string getPassword()
    {
        return password;
    }
    string getRole()
    {
        return role;
    }
    // setter
    void setPhone(string phone)
    {
        this->phone = phone;
    }
    void setPassword(string password)
    {
        this->password = password;
    }
    void setRole(string role)
    {
        this->role = role;
    }
    void setInfor()
    {
        cout << "Phone: ";
        cin.ignore();
        getline(cin, phone);
        cout << "Password: ";
        getline(cin, password);
        cout << "Role: ";
        getline(cin, role);
    }
    void signIn()
    {
        cout << "Phone: ";
        getline(cin, phone);
        cout << "Password: ";
        getline(cin, password);
    }
    void signUp()
    {
        cout << "Phone: ";
        getline(cin, phone);
        cout << "Password: ";
        getline(cin, password);
        cout << "Role: ";
        getline(cin, role);
        for (int i = 0; i < maxrow; i++)
        {
            if (AccessPhone[i] == "\0")
            {
                AccessPhone[i] = phone;
                AccessPass[i] = password;
                AccessRole[i] = role;
                break;
            }
        }
    }
    void validate()
    {
        // if (phone.empty() || password.empty())
        // {
        //     cout << "Phone, password or role cannot be empty" << endl;
        //     return;
        // }
        // if (phone.length() != 10)
        // {
        //     cout << "Phone number must be 10 digits" << endl;
        //     return;
        // }
        cout << "Validated successfully" << endl;
    }
    void display()
    {
        cout << "Phone: " << phone << endl;
        cout << "Password: " << password << endl;
        cout << "Role: " << role << endl;
    }
};
