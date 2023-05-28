#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1010;

int v[N], w[N], dp[N];  // dp数组用滚动数组优化(从二维降阶一维)

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d %d", &v[i], &w[i]);

	// 状态转移方程：dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i]] + w[i])
    for (int i = 0; i < n; ++i)
        for (int j = m; j >= v[i]; --j)  // 一维一定倒序遍历防止物品被重复计算
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);  // 一维的状态转移方程
    
    printf("%d", dp[m]);
    return 0;
}


// 二维写法
// int dp[N][N];
// for (int i = 0; i < n; ++i)
//     for (int j = v[i]; j <= m; ++j)
//     {
//         dp[i][j] = dp[i - 1][j];    
// 		   if (j >= v[i]) dp[i][j] = max(dp[i][j], dp[i][j-v[i]] + w[i]);
//     }


/*

input:
4 5
1 2
2 4
3 4
4 5

output:
8

*/