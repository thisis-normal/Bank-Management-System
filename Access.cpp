#include <bits/stdc++.h>
#include <sstream>
const int maxrow = 50;
#pragma once
using namespace std;
string AccessPhone[maxrow] = {};
string AccessPass[maxrow] = {};
string AccessRole[maxrow] = {};
class AccessControl
{
private:
    string accessPhone;
    string password;
    string role;

public:
    AccessControl() {}
    AccessControl(string accessPhone, string password, string role)
    {
        this->accessPhone = accessPhone;
        this->password = password;
        this->role = role;
    }
    // getter
    string getaccessPhone()
    {
        return accessPhone;
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
    void setaccessPhone(string accessPhone)
    {
        this->accessPhone = accessPhone;
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
        cout << "accessPhone: ";
        cin.ignore();
        getline(cin, accessPhone);
        cout << "Password: ";
        getline(cin, password);
        cout << "Role: ";
        getline(cin, role);
    }
    void signIn()
    {
        cout << "accessPhone: ";
        getline(cin, accessPhone);
        cout << "Password: ";
        getline(cin, password);
        cout << accessPhone << " " << password << endl;
    }
    void signUp()
    {
        cout << "accessPhone: ";
        getline(cin, accessPhone);
        cout << "Password: ";
        getline(cin, password);
        cout << "Role (admin or user):  ";
        getline(cin, role);
    }
    void validateSignIn()
    {
        if (accessPhone.empty() || password.empty())
        {
            cout << "accessPhone or password cannot be empty" << endl;
            return;
        }
        // if (accessPhone.length() != 10)
        // {
        //     cout << "accessPhone number must be 10 digits" << endl;
        //     return;
        // }
        // validate accessPhone
        for (int i = 0; i < accessPhone.length(); i++)
        {
            if (accessPhone[i] < '0' || accessPhone[i] > '9')
            {
                cout << "accessPhone number must be a number" << endl;
                return;
            }
        }
        // check if sign in not successfully
        bool check = false;
        for (int i = 0; i < maxrow; i++)
        {
            if (accessPhone == AccessPhone[i] && password == AccessPass[i])
            {
                check = true;
                break;
            }
        }
        if (check)
        {
            cout << "Sign in successfully" << endl;
        }
        else
        {
            cout << "Sign in failed" << endl;
        }
    }
    void validateSignUp()
    {
        if (accessPhone.empty() || password.empty() || role.empty())
        {
            cout << "accessPhone, password or role cannot be empty" << endl;
            return;
        }
        if (accessPhone.length() != 10)
        {
            cout << "accessPhone number must be 10 digits" << endl;
            return;
        }
        for (int i = 0; i < accessPhone.length(); i++)
        {
            if (accessPhone[i] < '0' || accessPhone[i] > '9')
            {
                cout << "accessPhone number must be a number" << endl;
                return;
            }
        }
        if (role != "admin" && role != "user")
        {
            cout << "Role must be admin or user" << endl;
            return;
        }
        // insert private key when role is admin
        if (role == "admin")
        {
            string privateKey;
            cout << "Enter private key: ";
            cin >> privateKey;
            if (privateKey != "123456")
            {
                cout << "Wrong private key" << endl;
                return;
            }
        }
        // check if accessPhone number is already existed in text file
        for (int i = 0; i < maxrow; i++)
        {
            if (accessPhone == AccessPhone[i])
            {
                cout << "accessPhone number is already existed" << endl;
                return;
            }
        }
        for (int i = 0; i < maxrow; i++)
        {
            if (AccessPhone[i] == "\0")
            {
                AccessPhone[i] = accessPhone;
                AccessPass[i] = password;
                AccessRole[i] = role;
                break;
            }
        }
        cout << "Validated successfully" << endl;
    }
    string getRoleByaccessPhone(string accessPhone)
    {
        for (int i = 0; i < maxrow; i++)
        {
            if (accessPhone == AccessPhone[i])
            {
                return AccessRole[i];
            }
        }
        return "";
    }
    void display()
    {
        cout << "accessPhone: " << accessPhone << endl;
        cout << "Password: " << password << endl;
        cout << "Role: " << role << endl;
    }
};