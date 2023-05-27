#include<iostream>
#include<queue>
#include<climits>

using namespace std;

const int N = 110;

int n, m;
int maze[N][N];  // 记录迷宫
bool st[N][N];  // 记录迷宫中的某个位置是否走过
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };  // 存储方向

// 用来记录当每一步的状态和走过的路径长
struct step{
    int r, c;
    int val;
};

int bfs(int r, int c)
{
    queue<step> q;  // bfs的状态队列
    q.push(step{r, c, 0});  // bfs的初始状态
    while (!q.empty())
    {
        step s = q.front(); q.pop();  // 取出队首状态

        for (int i = 0; i < 4; ++i)
        {
            // 计算每个方向及其是否可行
            step next = {s.r + dir[i][0], s.c + dir[i][1], s.val + 1};
            if (next.r < 0 || next.r >= n || next.c < 0 || next.c >= m || 
                maze[next.r][next.c] == 1 || st[next.r][next.c])  // 可以理解为限界函数
                continue;
            else if (next.r == n - 1 && next.c == m - 1) return next.val;  // 到达终点返回最短距离
            st[next.r][next.c] = true;  // 记录该位置已经走过了
            q.push(next);  // 向队列中推入下一个状态
        }
    }
    return INT_MAX;  // 假设被困住了，返回无穷大
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) scanf("%d", &maze[i][j]);

    printf("%d", bfs(0, 0));

    return 0;
}


/*
走迷宫
给定一个 n×m 的二维整数数组，用来表示一个迷宫，数组中只包含 0 或 1，其中 0 表示可以走的路，1 表示不可通过的墙壁。
最初，有一个人位于左上角 (1,1) 处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。
请问，该人从左上角移动至右下角 (n,m) 处，至少需要移动多少次。
数据保证 (1,1) 处和 (n,m) 处的数字为 0，且一定至少存在一条通路。.

input:
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0

output:
8

*/