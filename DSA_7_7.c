// PTA 7-7
#include <stdio.h>

#define INF 99999

int G[10001][10001];

int main()
{
    // 构建图
    int V, E;
    scanf("%d%d", &V, &E);
    for (int i = 0; i <= V; i++)
    {
        G[i][i] = 0;
        for (int j = i + 1; j <= V; j++)
            G[i][j] = G[j][i] = INF;
    }
    for (int i = 0; i < E; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        G[x][y] = G[y][x] = 1; // 注意起始值
    }
    // Floyd
    for (int t = 1; t <= V; t++)
        for (int i = 1; i <= V; i++)
            for (int j = i + 1; j <= V; j++)
                if (G[i][j] > G[i][t] + G[t][j])
                    G[i][j] = G[j][i] = G[i][t] + G[t][j];
    // 输出
    for (int i = 1; i <= V; i++)
    {
        int number = 0;
        for (int j = 1; j <= V; j++)
            if (G[i][j] <= 6)
                number++;
        printf("%d: %.2lf%%\n", i, number * 100.0 / V);
    }

    return 0;
}
