// PTA 7-8
#include <stdio.h>

#define INF 999999
#define MAX_SIZE 105

int G[MAX_SIZE][MAX_SIZE];

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
        int x, y, distance;
        scanf("%d %d %d", &x, &y, &distance);
        G[x][y] = G[y][x] = distance; // 注意起始值
    }
    // Floyd
    for (int t = 1; t <= V; t++)
        for (int i = 1; i <= V; i++)
            for (int j = i + 1; j <= V; j++)
                if (G[i][j] > G[i][t] + G[t][j])
                    G[i][j] = G[j][i] = G[i][t] + G[t][j];
    // 筛选
    int len = INF,
        animal = 0;
    for (int i = 1; i <= V; i++)
    {
        int hard_len = 0;
        for (int j = 1; j <= V; j++)
            if (hard_len < G[i][j])
                hard_len = G[i][j];
        if (len > hard_len)
        {
            len = hard_len;
            animal = i;
        }
    }
    if (!animal)
        printf("0\n");
    else
        printf("%d %d\n", animal, len);
    return 0;
}