#include<iostream>

using namespace std;

const int N = 10;

int n;
char g[N][N];
bool col[N], dg[N], rdg[N];  // col列，dg对角线，rdg反对角线；每行一定有一个皇后，无需判断，即n*n的棋盘上一定有n个皇后

void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; ++i) puts(g[i]);
        puts("");
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        // 判断框体中隐含着剪枝
        if (!col[i] && !dg[u + i] && !rdg[n - u + i])  // 行u，列i，对角线u+i，反对角线n-u+i
        {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = rdg[n - u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = rdg[n - u + i] = false;  // 回溯，恢复现场
            g[u][i] = '.';
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) g[i][j] = '.';

    dfs(0);

    return 0;
}

/*

input:
4

output:
.Q..
...Q
Q...
..Q.

..Q.
Q...
...Q
.Q..

O(n*n!)

*/


// 更为原始搜索方法，不考虑每行一定有一个皇后，直接搜每一个格子，时间复杂度巨高
// #include <iostream>

// using namespace std;

// const int N = 20;

// int n;
// char g[N][N];
// bool col[N], dg[N], udg[N];

// void dfs(int u)
// {
//     if (u == n)
//     {
//         for (int i = 0; i < n; i ++ ) puts(g[i]);
//         puts("");
//         return;
//     }

//     for (int i = 0; i < n; i ++ )
//         if (!col[i] && !dg[u + i] && !udg[n - u + i])
//         {
//             g[u][i] = 'Q';
//             col[i] = dg[u + i] = udg[n - u + i] = true;
//             dfs(u + 1);
//             col[i] = dg[u + i] = udg[n - u + i] = false;
//             g[u][i] = '.';
//         }
// }

// int main()
// {
//     cin >> n;
//     for (int i = 0; i < n; i ++ )
//         for (int j = 0; j < n; j ++ )
//             g[i][j] = '.';

//     dfs(0);

//     return 0;
// }
// 
// O(2^n^2)