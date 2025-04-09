#include <iostream>
#include <string>
using namespace std;

class Bank
{
private:
    string name;
    int acount_no;
    double balance;

public:
    Bank();
    Bank(string n, int a, double b) : name(n), acount_no(a), balance(b) {}
    void deposit(double);
    void withdraw(double);
    int get_acount()
    {
        return acount_no;
    }

    void input()
    {
        cout << "Enter your acount name " << endl;
        getline(cin, name);
        cout << "Enter your acount number " << endl;
        cin >> acount_no;
        cout << "Enter your balance " << endl;
        cin >> balance;
        cin.ignore();
    }

    void display()
    {
        cout << "Acount name : " << name << endl;
        cout << "Acount number : " << acount_no << endl;
        cout << "Balance : " << balance << endl;
    }
};
Bank ::Bank()
{
    name = "Unknown";
    acount_no = 0;
    balance = 0.0;
}
void Bank ::withdraw(double amount)
{
    if (amount > 0 && amount <= balance)
    {
        balance -= amount;
        cout << "$" << amount << " Withdraw sucessfully" << endl;
    }
    else
    {
        cout << "You don't have sufficient amount !" << endl;
    }
}
void Bank ::deposit(double amount)
{
    if (amount > 0)
    {
        balance += amount;
        cout << "$" << amount << " deposited sucessfully" << endl;
    }
    else
    {
        cout << "Invalid amount for deposit" << endl;
    }
}
int main()
{
    Bank acount[3];
    double deposit, withdraw;
    char choice1;
    int choice2, acount_no;
    bool acount_found = false;
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter details of " << i + 1 << " acount" << endl;
        acount[i].input();
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "\nDetails of " << i + 1 << " acount :" << endl;
        acount[i].display();
    }
    cout << "Do you want ( deposit/withdraw ) amount ? (Y/N)" << endl;
    cin >> choice1;
    if (choice1 == 'y' || choice1 == 'Y')
    {
        cout << "Enter 1 for deposit and 2 for withdraw " << endl;
        cin >> choice2;
        switch (choice2)
        {
        case 1:
            cout << "Enter acount number " << endl;
            cin >> acount_no;
            for (int i = 0; i < 3; i++)
            {
                if (acount[i].get_acount() == acount_no)
                {
                    acount_found = true;
                    cout << "Enter amount you want to deposit" << endl;
                    cin >> deposit;
                    acount[i].deposit(deposit);
                    acount[i].display();
                }
            }
            if (!acount_found)
            {
                cout << "Account not found!" << endl;
            }

            break;
        case 2:
            cout << "Enter acount number " << endl;
            cin >> acount_no;
            for (int i = 0; i < 3; i++)
            {
                if (acount[i].get_acount() == acount_no)
                {
                    acount_found = true;
                    cout << "Enter amount you want to withdraw" << endl;
                    cin >> withdraw;
                    acount[i].withdraw(withdraw);
                    acount[i].display();
                }
            }
            if (!acount_found)
            {
                cout << "Account not found!" << endl;
            }
        default:
            cout << "Invalid input !" << endl;
            break;
        }
    }
    else
    {
        cout << "Your acount are created sucessfully" << endl;
    }

    return 0;
}