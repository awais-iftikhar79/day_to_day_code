#include <iostream>
#include <string>
using namespace std;

class Acount
{
private:
    int acount_no;
    float balance;

public:
    void set_details(int, float);
    void display()
    {
        cout << "Acount # " << acount_no << endl;
        cout << "Balance :$" << balance << endl;
    }
    float getBalance()
    {
        return balance;
    }
};
void Acount ::set_details(int a, float b)
{
    acount_no = a;
    balance = b;
}
class Saving_Acount : public Acount
{
private:
    double interest;

public:
    void set_interest(double);
    void display_interest()
    {
        double interest_amount = (getBalance() * interest) / 100;
        display();
        cout << "Interest Amount :$" << interest_amount << endl;
    }
};
void Saving_Acount ::set_interest(double i)
{
    interest = i;
}
int main()
{
    Saving_Acount s1;
    s1.set_details(1001, 500);
    s1.set_interest(2.5);
    s1.display_interest();
    
    return 0;
}