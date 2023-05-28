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

    // 状态转移方程：dp[i][j] = max(dp[i-1][j], dp[i][j-v[i]] + w[i])
    for (int i = 0; i < n; ++i)
        for (int j = v[i]; j <= m; ++j)  // 其实就是01背包正向遍历，考虑重复的情况
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);  // 优化为一维
    
    printf("%d", dp[m]);
    return 0;
}


// 三维做法
// 状态转移方程：dp[i][j] = max(dp[i-1][j], dp[i-1][j-k*v[i]] + k*w[i])
// int dp[N][N];
// for (int i = 0; i < n; ++i)
//     for (int j = 0; j <= m; ++j)
//         for (int k = 0; k * v[i] <= j; ++k)
//             dp[i][j] = max(dp[i][j], dp[i - 1][j - k*v[i]] + k*w[i]);
// printf("%d", dp[n - 1][m]);


/*

input:
4 5
1 2
2 4
3 4
4 5

output:
10

*/