#include <iostream>
using namespace std;

int setbit(int n, int pos)
{
    return (n | (1 << pos));
}
int main()
{
    int num = 15;
    int k;
    cout << "Enter position of bit you want to set 1" << endl;
    cin >> k;
    cout << "After changing bit ,The new number is : " << setbit(num, k) << endl;

    return 0;
}