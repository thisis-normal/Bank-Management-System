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
        cout << phone << " " << password << endl;
    }
    void signUp()
    {
        cout << "Phone: ";
        getline(cin, phone);
        cout << "Password: ";
        getline(cin, password);
        cout << "Role: (admin or user) ";
        getline(cin, role);
    }
    void validateSignIn()
    {
        if (phone.empty() || password.empty())
        {
            cout << "Phone or password cannot be empty" << endl;
            return;
        }
        // if (phone.length() != 10)
        // {
        //     cout << "Phone number must be 10 digits" << endl;
        //     return;
        // }
        // validate phone
        for (int i = 0; i < phone.length(); i++)
        {
            if (phone[i] < '0' || phone[i] > '9')
            {
                cout << "Phone number must be a number" << endl;
                return;
            }
        }
        // check if sign in not successfully
        bool check = false;
        for (int i = 0; i < maxrow; i++)
        {
            if (phone == AccessPhone[i] && password == AccessPass[i])
            {
                check = true;
                break;
            }
        }
        if (check)
        {
            cout << "Sign in successfully" << endl;
            cout << "Hello " << role << endl;
        }
        else
        {
            cout << "Sign in failed" << endl;
        }
    }
    void validateSignUp()
    {
        if (phone.empty() || password.empty() || role.empty())
        {
            cout << "Phone, password or role cannot be empty" << endl;
            return;
        }
        if (phone.length() != 10)
        {
            cout << "Phone number must be 10 digits" << endl;
            return;
        }
        for (int i = 0; i < phone.length(); i++)
        {
            if (phone[i] < '0' || phone[i] > '9')
            {
                cout << "Phone number must be a number" << endl;
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
        // check if phone number is already existed in text file
        for (int i = 0; i < maxrow; i++)
        {
            if (phone == AccessPhone[i])
            {
                cout << "Phone number is already existed" << endl;
                return;
            }
        }
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
        cout << "Validated successfully" << endl;
    }
    void display()
    {
        cout << "Phone: " << phone << endl;
        cout << "Password: " << password << endl;
        cout << "Role: " << role << endl;
    }
};