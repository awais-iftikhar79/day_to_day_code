#include <iostream>
using namespace std;

int update_bit(int n, int pos, int val)
{
    return (n & ~(1 << pos)) | (val << pos);
}
int main()
{
    int num = 8;
    int k, val;
    cout << "Enter bit number you want to update" << endl;
    cin >> k;
    cout << "Enter bit you want to set (0,1)" << endl;
    cin >> val;
    cout << "After updating the bit .\nThe new number is : " << update_bit(num, k, val) << endl;
    return 0;
}