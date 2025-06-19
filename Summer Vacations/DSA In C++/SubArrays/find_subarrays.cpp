#include <iostream>
#include <vector>
using namespace std;

void print_subarray(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i; j < vec.size(); j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << k;
            }
            cout << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<int> vect = {1, 2, 3, 4, 5};
    print_subarray(vect);

    return 0;
}