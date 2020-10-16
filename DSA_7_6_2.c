// PTA 7-6
#include <stdio.h>

int G[11][11] = {0},
    V,
    E;

void CreatG();
void DFS();
void BFS();

int main()
{
    CreatG();
    DFS();
    BFS();
    return 0;
}

void CreatG()
{
    scanf("%d%d", &V, &E);
    for (int i = 0; i < E; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        G[x][y] = G[y][x] = 1;
    }
}

void DFS()
{
    int visited[11] = {0},
        s[20] = {0},
        top = -1;
    for (int i = 0; i < V; i++)
        if (!visited[i])
        {
            printf("{ ");
            s[++top] = i;
            while (top >= 0)
            {
                int t = s[top--];
                if (visited[t]) continue; // 防止重复访问
                visited[t] = 1;
                printf("%d ", t);
                for (int j = V - 1; j > i; j--)
                    if (G[t][j] && !visited[j])
                        s[++top] = j;
            }
            printf("}\n");
        }
}

void BFS()
{
    int visited[11] = {0},
        q[20] = {0},
        rear = -1,
        front = -1;
    for (int i = 0; i < V; i++)
        if (!visited[i])
        {
            printf("{ ");
            visited[i] = 1;
            q[++rear] = i;
            while (front < rear)
            {
                int t = q[++front];
                printf("%d ", t);
                for (int j = i; j < V; j++)
                    if (G[t][j] && !visited[j])
                    {
                        visited[j] = 1;
                        q[++rear] = j;
                    }
            }
            printf("}\n");
        }
}