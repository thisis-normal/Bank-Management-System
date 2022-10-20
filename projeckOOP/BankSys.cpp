#include <iostream>
using namespace std;
class BankSys
{
private:
    string name;
    double balance;
    int phone;
    string city;
    string accountNumber;

public:
    // initialization
    BankSys() {}
    BankSys(string Hname, double Hbalance, int Hphone, string Hcity, string HaccountNumber)
    {
        this->name = Hname;
        this->balance = Hbalance;
        this->phone = Hphone;
        this->city = Hcity;
        this->accountNumber = HaccountNumber;
    }
    // getter
    string getName()
    {
        return name;
    }
    double getBalance()
    {
        return balance;
    }
    int getPhone()
    {
        return phone;
    }
    string getCity()
    {
        return city;
    }
    string getAccountNumber()
    {
        return accountNumber;
    }
    // setter
    void setName(string name)
    {
        this->name = name;
    }
    void setBalance(double balance)
    {
        this->balance = balance;
    }
    void setPhone(int phone)
    {
        this->phone = phone;
    }
    void setCity(string city)
    {
        this->city = city;
    }
    void setAccountNumber(string accountNumber)
    {
        this->accountNumber = accountNumber;
    }
    void input()
    {
        string name;
        cin >> name;
        cout << "Name: " << name << endl;
        double balance;
        cin >> balance;
        cout << "Balance: " << balance << endl;
        int phone;
        cin >> phone;
        cout << "Phone: " << phone << endl;
        string city;
        cin >> city;
        cout << "City: " << city << endl;
        string accountNumber;
        cin >> accountNumber;
        cout << "Accoint Number: " << accountNumber << endl;
    }
    void display()
    {
        cout << "Your name: " << name << endl;
        cout << "Your Account Number: " << accountNumber << endl;
        cout << "Your City: " << city << endl;
        cout << "Your phone: " << phone << endl;
        cout << "Your Balance: " << balance << endl;
    }
};
int main()
{
    BankSys p;
    p.input();
    p.display();
}
