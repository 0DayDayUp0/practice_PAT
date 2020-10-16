// PTA 7-9
#include <stdio.h>
#include <vector>
using namespace std;

#define INF 999999

struct E
{
    int next;
    int cost;
    int dis;
};

int main()
{
    // 构建临接表
    int N, M, S, D;
    scanf("%d %d %d %d", &N, &M, &S, &D);
    vector<vector<E>> G(N);
    for (int i = 0; i < M; i++)
    {
        int x, y, d, c;
        scanf("%d %d %d %d", &x, &y, &d, &c);
        G[x].push_back(E{y, c, d});
        G[y].push_back(E{x, c, d});
    }
    // Dijkstr
    vector<bool> visited(N, false);
    vector<int> cost(N, 0), dis(N, INF);
    visited[S] = true;
    dis[S] = 0;
    int t_node = S;
    for (int i = 0; i < N; i++)
    {
        // 更新距离，花费
        for (int j = 0; j < G[t_node].size(); j++)
        {
            int next = G[t_node][j].next;
            int c = G[t_node][j].cost;
            int d = G[t_node][j].dis;
            if (visited[next])
                continue;
            if (dis[next] > dis[t_node] + d || (dis[next] == dis[t_node] + d && cost[next] > cost[t_node] + c))
            {
                dis[next] = dis[t_node] + d;
                cost[next] = cost[t_node] + c;
            }
        }
        // 寻找最近未访问节点
        int min = INF;
        for (int j = 0; j < N; j++)
        {
            if (visited[j])
                continue;
            if (dis[j] < min)
            {
                min = dis[j];
                t_node = j;
            }
        }
        visited[t_node] = true;
    }
    printf("%d %d\n", dis[D], cost[D]);
    return 0;
}
