// PTA 7-11
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define INF 0xfffffff

struct Edge
{
    int start, end, weight, index;
};
struct Node
{
    int early_start, late_start, in_degree, out_degree;
};

int main()
{
    // 构建临接表
    int N, M;
    cin >> N >> M;
    vector<Node> nodes(N + 1, Node{0, INF, 0, 0});
    vector<Edge> edges;
    for (int i = 0; i < M; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back(Edge{x, y, w, i});
        nodes[x].out_degree++;
        nodes[y].in_degree++;
    }
    // 拓扑排序
    queue<int> q;
    vector<int> sorted;
    for (int i = 1; i <= N; i++)
        if (!nodes[i].in_degree)
        {
            q.push(i);
            sorted.push_back(i);
        }
    while (!q.empty())
    {
        for (auto i = edges.begin(); i != edges.end(); i++)
            if (i->start == q.front() && nodes[i->end].in_degree && !--nodes[i->end].in_degree)
            {
                q.push(i->end);
                sorted.push_back(i->end);
            }
        q.pop();
    }
    // 有环
    if (sorted.size() != N)
    {
        cout << "0" << endl;
        return 0;
    }
    // 最早开始时间
    int full_time = 0;
    for (auto i = sorted.begin(); i != sorted.end(); i++) // 正向
        for (auto j = edges.begin(); j != edges.end(); j++)
            if (j->end == *i)
            {
                nodes[*i].early_start = max(nodes[*i].early_start, nodes[j->start].early_start + j->weight);
                if (!nodes[*i].out_degree)
                    full_time = max(full_time, nodes[*i].early_start);
            }
    // 最迟开始时间
    for (auto i = nodes.begin() + 1; i != nodes.end(); i++)
        if (!i->out_degree)
            i->late_start = full_time; // 多终点最晚为全局最晚
    for (auto i = sorted.rbegin(); i != sorted.rend(); i++) // 反向
        for (auto j = edges.begin(); j != edges.end(); j++)
            if (j->start == *i)
                nodes[*i].late_start = min(nodes[*i].late_start, nodes[j->end].late_start - j->weight);
    // 机动时间, 输出
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) { return a.start != b.start ? a.start < b.start : a.index > b.index; });
    cout << full_time << endl;
    for (auto i = edges.begin(); i != edges.end(); i++)
        if (nodes[i->end].late_start - nodes[i->start].early_start == i->weight)
            cout << i->start << "->" << i->end << endl;
    return 0;
}
