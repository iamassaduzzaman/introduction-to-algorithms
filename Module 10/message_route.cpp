#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
bool visited[N];
bool found = false;
int parent[N];

void bfs(int u, int target)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    parent[u] = -1;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        if (f == target)
            found = true;
        for (int v : g[f])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
                parent[v] = f;
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
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs(1, n);

    if (found)
    {
        vector<int> path;
        int current = n;
        while (current != -1)
        {
            path.push_back(current);
            current = parent[current];
        }

        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (int v : path)
            cout << v << " ";
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}