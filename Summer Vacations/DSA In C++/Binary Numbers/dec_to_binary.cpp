#include <iostream>
using namespace std;

int dec_to_binary(int dec)
{
    int ans = 0, power = 1, remainder = 0;

    while (dec > 0)
    {
        remainder = dec % 2;
        ans += remainder * power;

        dec /= 2;
        power *= 10;
    }
    return ans;
}

int main()
{
    int decimal;
    cout << "Enter decimal number " << endl;
    cin >> decimal;
    int ans = dec_to_binary(decimal);

    cout << "Binary form is : " << ans << endl;

    return 0;
}