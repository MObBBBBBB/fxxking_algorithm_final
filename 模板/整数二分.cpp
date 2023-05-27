#include<iostream>
#include<algorithm>
using namespace std;
typedef int status;

// 可以是任意将序列一分为二的条件
// bool check(...)
// {
//     return ...;
// }

int main()
{
	status arr[] = { 23,6,4,8,49,616,479,64,4,-1 };
    int n = sizeof(arr) / sizeof(status);
    sort(arr, arr + n);

    int k = 64; // 假设k为要找的数

    int l = 0, r = n - 1;

    // l = mid 如有多个匹配，l为最右侧的；
    while (l < r)
    {
        int mid = l + r + 1 >> 1;   // 记得+1
        if (arr[mid] <= k) l = mid;  // if中的条件为check(...)
        else r = mid - 1;
    }

    // r = mid 如有多个匹配，r为最左侧的
    while (l < r)
    {
        int mid = l + r >> 1;
        if (arr[mid] >= k) r = mid;
        else l = mid + 1;
    }

    cout << (arr[l] == k) << endl;

	return 0;
}