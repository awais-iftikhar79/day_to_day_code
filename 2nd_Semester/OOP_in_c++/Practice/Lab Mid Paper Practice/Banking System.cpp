#include <iostream>
#include <string>
using namespace std;
#define MAX 10
void display_menu()
{
    cout << "1.Create Acounts" << endl
         << "Deposit Money " << endl
         << "Withdraw Money " << endl
         << "Transfer Money " << endl
         << "Display Acount Details and Transaction History" << endl;
}
struct Transaction
{
    string type;
    double amount;
    string date;

    Transaction() {}
    Transaction(string t, double a, string d) : type(t), amount(a), date(d) {}
};
class Acount
{
private:
    int acount_no;
    double balance;
    Transaction *transaction;
    int transaction_count;

public:
    Acount() {}
    Acount(int a, double b) : acount_no(a), balance(b), transaction_count(0)
    {
        transaction = new Transaction[MAX];
    }
    void deposit(double amount, string date)
    {
    }
    void with_draw(double amount, string date)
    {
    }
    void transfer(Acount &to_acount, double amount, string date)
    {
    }
    void display_acount_details()
    {
    }
};
class SavingAcount : public Acount{
    private:
    double interest_rate;
    public:

};
class Bank
{
private:
    Acount *acount;
    int acount_count;

public:
    Bank() : acount_count(0)
    {
        acount = new Acount[MAX];
    }
    void create_acount(int acount_no, double initila_balance)
    {
    }
    void find_acount(int acount_no)
    {
    }
    void display_acounts()
    {
    }
};
class Person
{
protected:
    string name;
    string address;

public:
    Person(string n, string a) : name(n), address(a) {}
    void display()
    {
        cout << "Name : " << name << endl;
        cout << "Address : " << address << endl;
    }
};
class Customer : public Person
{
private:
    int customer_id;

public:
    Customer(string n, string a, int id) : Person(n, a), customer_id(id) {}
    void display()
    {
        cout << "Name : " << name << endl;
        cout << "Address : " << address << endl;
        cout << "Customer ID : " << customer_id << endl;
    }
};
int main()
{

    return 0;
}