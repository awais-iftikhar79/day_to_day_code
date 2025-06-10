#include <iostream>
using namespace std;

int binary_to_dec(int binary)
{
    int ans = 0, power = 1, remainder = 0;

    while (binary > 0)
    {
        remainder = binary % 10;
        binary /= 10;

        ans += remainder * power;
        power *= 2;
    }
    return ans;
}

int main()
{
    int binary;
    cout << "Enter binary number " << endl;
    cin >> binary;
    int ans = binary_to_dec(binary);

    cout << "Decimal Number is : " << ans << endl;

    return 0;
}