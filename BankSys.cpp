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

    void display()
    {
        cout << "Your name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "City: " << city << endl;
        cout << "Your phone: " << phone << endl;
        cout << "Balance: " << balance << endl;
    }
};
int main()
{
    BankSys p;
    p.display();
}