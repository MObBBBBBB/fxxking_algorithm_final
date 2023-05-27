/*
时间O(n^2)
空间O(1)
*/

#include<vector>
#include<algorithm>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int max = INT_MIN, n = int(nums.size());
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum > max) max = sum;
        }
    }

    return max;
}