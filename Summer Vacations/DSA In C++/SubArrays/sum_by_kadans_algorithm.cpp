#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int max_sum(vector<int> vec)
{
    int max_sum = INT_MIN;
    int current_sum = 0;
    for (int value : vec)
    {
        current_sum += value;
        max_sum = max(current_sum, max_sum);
        if (current_sum < 0)
        {
            current_sum = 0;
        }
    }
    return max_sum;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    int sum = max_sum(vec);
    cout << "Maximum Subarray sum is : " << sum << endl;

    return 0;
}