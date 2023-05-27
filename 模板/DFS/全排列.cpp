#include<iostream>

using namespace std;

const int N = 10;

int n;
int path[N], st[N];  // path存储路径，如1 2 3；st存储当前数字有没有被使用

void dfs(int u)
{
    if (n == u)
    {
        for (int i = 0; i < n; ++i) printf("%d ", path[i]);
        puts("");
        return;
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!st[i])
        {
            path[u] = i;
            st[i] = 1;
            dfs(u + 1);
            st[i] = 0;  // 回溯，恢复现场
        }
    }
}

int main()
{
    scanf("%d", &n);

    dfs(0);   

    return 0;
}


/*

input:
3

output:
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

*/
