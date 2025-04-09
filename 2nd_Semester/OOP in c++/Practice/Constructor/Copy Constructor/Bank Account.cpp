#include <iostream>
#include <string>
using namespace std;

class Bank_Acount
{
private:
    int acount_no;
    double balance;

public:
    Bank_Acount() {}
    Bank_Acount(int, double);
    Bank_Acount(Bank_Acount &obj)
    {
        acount_no = obj.acount_no;
        balance = obj.balance;
        cout << "Copy Constructor is calling " << endl;
    }
    void display()
    {
        cout << "Acount Number is : " << acount_no << endl;
        cout << "Balance :$" << balance << endl;
    }
};
Bank_Acount ::Bank_Acount(int a, double b)
{
    acount_no = a;
    balance = b;
}
int main()
{
    Bank_Acount b1(1001, 300);
    b1.display();
    Bank_Acount b2 = b1;
    b2.display();
    return 0;
}