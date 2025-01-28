#include <iostream>
#include <string>
using namespace std;
class bank_acount
{
private:
    int acount_number;
    float balance;

public:
    void set_balance(float amount)
    {
        balance = amount;
    };
    float get_balance()
    {
        return balance;
    };
    void set_acount(int number)
    {
        acount_number = number;
    }
    int get_acount()
    {
        return acount_number;
    }
};

int main()
{
    bank_acount b1;
    int acount_no;
    float balance;
    cout << "Enter your bank acount number" << endl;
    cin >> acount_no;
    b1.set_acount(acount_no);
    cout << "Enter your bank balance " << endl;
    cin >> balance;
    b1.set_balance(balance);
    cout << "Acount number : " << b1.get_acount() << endl;
    cout << "Current Balance : $" << b1.get_balance() << endl;
    ;

    return 0;
}