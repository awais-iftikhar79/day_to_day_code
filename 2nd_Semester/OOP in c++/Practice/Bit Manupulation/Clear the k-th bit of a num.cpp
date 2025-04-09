#include <iostream>
using namespace std;

int clearbit(int n, int pos)
{
    return (n & (~(1 << pos)));
}
int main()
{
    int num = 10;
    int k;
    cout << "Enter position of which you want to clear bit (=0)" << endl;
    cin >> k;
    cout << "After clearing bit at " << k << "-th bit \nThe number is : " << clearbit(num, k) << endl;

    return 0;
}