#include<iostream>
#include<algorithm>

using namespace std;

const int N = 24000;

int v[N], w[N], dp[N];   // dp数组用滚动数组优化(从二维降阶一维)

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    // 二进制优化，摊销时间复杂度
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        int a, b, s;
        scanf("%d %d %d", &a, &b, &s);
        int k = 1;
        while (k <= s)
        {
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            s -= k;
            k *= 2;
        }
        if (s > 0)
        {
            cnt++;
            v[cnt] = a * s;
            w[cnt] = b * s;
        }
    }

    n = cnt;

    // 状态转移方程：dp[i][j] = max(dp[i-1][j], dp[i][j-v[i]] + w[i])
    for (int i = 1; i <= n; ++i)
        for (int j = m; j >= v[i]; --j)
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);  // 优化为一维
            
    printf("%d", dp[m]);

    return 0;
}


// 三维写法
// 状态转移方程：f[i,j] = max(f[i-1], f[i - 1][j - k*v[i]] + k * w[i])  (k属于0到s[i])
// int dp[N][N];
// for (int i = 1; i <= n; ++i)
//     for (int j = 0; j <= m; ++j)
//         for (int k = 0; k <= s[i] && k * v[i] <= j; ++k)
//             dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
// printf("%d", dp[n][m]);


/*

input:
4 5
1 2 3
2 4 1
3 4 3
4 5 2

output:
10

*/