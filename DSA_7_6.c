// PTA 7-6
#include <stdio.h>

int G[11][11],
    visited[11],
    V,
    E;

void CreatG();
void DFSpath();
void BFSpath();

int main()
{
    CreatG();
    DFSpath();
    BFSpath();
    return 0;
}

void CreatG()
{
    scanf("%d%d", &V, &E);
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 11; j++)
            G[i][j] = 0;
    for (int i = 0; i < E; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        G[x][y] = G[y][x] = 1;
    }
}

void DFS(int i)
{
    visited[i] = 1;
    printf("%d ", i);
    for (int j = 0; j < V; j++)
        if (G[i][j] && !visited[j])
            DFS(j);
}

void DFSpath()
{
    for (int i = 0; i < V; i++)
        visited[i] = 0;
    for (int i = 0; i < V; i++)
        if (!visited[i])
        {
            printf("{ ");
            DFS(i);
            printf("}\n");
        }
}

void BFS(int i)
{
    for (int j = 0; j < V; j++)
        if (G[i][j] && !visited[j])
            printf("%d ", j);
    for (int j = 0; j < V; j++)
        if (G[i][j] && !visited[j])
        {
            visited[j] = 1;
            DFS(j);
        }
}

void BFSpath()
{
    for (int i = 0; i < V; i++)
        visited[i] = 0;
    for (int i = 0; i < V; i++)
        if (!visited[i])
        {
            printf("{ %d ", i);
            visited[i] = 1;
            BFS(i);
            printf("}\n");
        }
}