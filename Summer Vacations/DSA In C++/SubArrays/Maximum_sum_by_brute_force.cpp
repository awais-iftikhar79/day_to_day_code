#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int max_sum(vector<int> vec)
{
    int max_sum = INT_MIN;
    for (int i = 0; i < vec.size(); i++)
    {
        int current_sum = 0;
        for (int j = i; j < vec.size(); j++)
        {
            current_sum += vec[j];
            max_sum = max(current_sum, max_sum);
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