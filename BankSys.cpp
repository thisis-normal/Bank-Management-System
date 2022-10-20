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
    void setname(string name)
    {
        this->name = name;
    }
    void setbalance(double balance)
    {
        this->balance = balance;
    }
    void setphone(int phone)
    {
        this->phone = phone;
    }
    void setcity(string city)
    {
        this->city = city;
    }
    void setaccountNumber(string accountNumber)
    {
        this->accountNumber = accountNumber;
    }

    void display()
    {
        cout << "ten tai khoan: " << name << endl;
        cout << "so tai khoan: " << accountNumber << endl;
        cout << "thanh pho: " << city << endl;
        cout << "so dien thoai: " << phone << endl;
        cout << "so du tai khoan: " << accountNumber << endl;
    }
};
int main()
{
    BankSys p;
    p.display();
}