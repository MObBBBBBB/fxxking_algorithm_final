/*
取max(前一个元素与当前元素的和, 当前元素的值)
将其与当前最大值比较
状态转移方程：f(n) = max{f(n-1) + nums[i], nums[i]}
时间O(n)
空间（优化后）O(1)
*/

#include<vector>
#include<algorithm>
using namespace std;


int maxSubArray(vector<int>& nums)
{
    int pre = 0, maxAns = nums[0];
    for (int &x : nums) 
    {
        pre = max(pre + x, x);
        maxAns = max(maxAns, pre);
    }

    return maxAns;
}

