#include <iostream>
using namespace std;

bool getbit(int n, int pos)
{
    return (n & (1 << pos)) != 0;
}

int main()
{
    int num = 13;
    int k = 2;
    if (getbit(num, k))
    {
        cout << "The " << k << "-th bit is one (1)" << endl;
    }
    else
    {
        cout << "The " << k << "-th bit is zero (0)" << endl;
    }
    return 0;
}