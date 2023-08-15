#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];

int visited[N] = {false};
int level[N] = {0};

bool flag = false;
int parent[N];

void bfs(int u, int d)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    parent[u] = -1;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        if (f == d)
            flag = true;

        for (int v : adjList[f])
        {
            if (!visited[v])
            {
                level[v] = level[f] + 1;
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
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int s, d;
    cin >> s >> d;
    bfs(s, d); // O(n+m)
    if (flag)
    {
        cout << "shortest distance: " << level[d] - level[s] << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    // Path finding: O(n)
    vector<int> path;
    int current = d;
    while (current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    cout << "path: ";
    for (int node : path)
        cout << node << " ";

    return 0;
}

/*

6
7
0 1
0 2
1 2
0 3
4 2
3 5
4 3

*/