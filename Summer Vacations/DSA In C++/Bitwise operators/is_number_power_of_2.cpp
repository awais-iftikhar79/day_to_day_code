#include <iostream>
using namespace std;

bool is_power_of_2(int n)
{

    if (n <= 0)
    {
        return false;
    }
    else
    {
        return (n & (n - 1)) == 0;
    }
}
int main()
{
    int num;
    cout << "Enter number you want to check power of two " << endl;
    cin >> num;
    if (is_power_of_2(num))
    {
        cout << num << " is power of two " << endl;
    }
    else
    {
        cout << num << " is not power of two" << endl;
    }
    return 0;
}