#include <iostream>
using namespace std;

int toggle_bit(int n, int pos)
{
    return (n ^ (1 << pos));
}
int main()
{
    int num = 12;
    int k;
    cout << "Enter bit number you want to toggle" << endl;
    cin >> k;
    cout<<"After toggling the required bit\nThe new number is : "<<toggle_bit(num,k)<<endl;

    return 0;
}