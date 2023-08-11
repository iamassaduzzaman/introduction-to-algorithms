#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool visited[N];
int level[N] = {0};

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        for (int v : adjList[f])
        {
            if (!visited[v])
            {
                level[v] = level[f] + 1;
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int l; cin >> l;

    bfs(1);

    cout << "Level of " << l << " = " << level[l] << endl;

    return 0;
}
