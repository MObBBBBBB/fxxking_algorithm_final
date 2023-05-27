/*
对于一个区间[l,r]，我们取m=l+r>>2，对区间 [l,m] 和 [m+1,r] 分治求解。

对于一个区间[l,r]，维护四个量：
lSum 表示[l,r]内以l为左端点的最大子段和
rSum 表示[l,r]内以r为右端点的最大子段和
mSum 表示[l,r]内的最大子段和
iSum 表示[l,r]的区间和

iSum = l.iSum + r.iSum;
lSum = max(l.lSum, l.iSum + r.lSum);
rSum = max(r.rSum, r.iSum + l.rSum);
mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);

时间O(n)
空间O(logn)
虽然空间大，但可以转换为任意区间，且可以将递归返回过程构造为一棵树，即 线段树
*/

#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    struct Status {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status) {lSum, rSum, mSum, iSum};
    };

    Status get(vector<int> &a, int l, int r) {
        if (l == r) {
            return (Status) {a[l], a[l], a[l], a[l]};
        }
        int mid = (l + r) >> 1;
        Status lSub = get(a, l, mid);
        Status rSub = get(a, mid + 1, r);
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};