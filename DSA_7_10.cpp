// PTA 7-10
#include <iostream>
#include <vector>
using namespace std;

#define INF 0xfffffff

struct E
{
    int next, weight;
};

int main()
{
    // 构建临接表
    int N, M;
    cin >> N >> M;
    vector<vector<E>> G(N + 1);
    for (int i = 0; i < M; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        G[x].push_back(E{y, w});
        G[y].push_back(E{x, w});
    }
    // Prim
    int t_node = 1,
        sum_mst = 0;
    vector<int> low_cost(N + 1, INF), mst(N + 1);
    mst[1] = 1;
    for (int i = 1; i < N; i++)
    {
        // 更新边集
        for (auto j = G[t_node].begin(); j != G[t_node].end(); j++)
            low_cost[j->next] = max(low_cost[j->next], j->weight);
        // 搜索临近最短边
        int min_edge = INF,
            next_node = 0;
        for (int j = 1; j <= N; j++)
            if (!mst[j] && min_edge > low_cost[j])
            {
                min_edge = low_cost[j];
                next_node = j;
            }
        // 是否联通图？
        if (!next_node)
        {
            sum_mst = -1;
            break;
        }
        sum_mst += min_edge;
        mst[next_node] = t_node;
        t_node = next_node;
    }
    cout << sum_mst << endl;
    return 0;
}