/*
若当前指针所指的元素之前的所有元素的和小于0，则丢弃之前的子序列
取当前元素值与之前元素和中的最大值
时间O(n)
空间O(1)
*/

#include<vector>
#include<algorithm>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int result = INT_MIN, sum = 0;
    for (int &x : nums)
    {
        if (x < 0)
        {
            sum = 0;
            continue;
        }
        sum += x;
        result = max(result, sum);
    }

    return result;
}

