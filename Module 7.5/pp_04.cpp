#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adjList[N];
bool visited[N];
queue<int> q;

void dfs(int u)
{
    visited[u] = true;
    q.push(u);
    for (int v : adjList[u])
    {
        if (!visited[v])
        {
            dfs(v);
            visited[v] = true;
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

    int totalComponent = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            totalComponent++;
            dfs(i);
        }
    }

    cout << totalComponent << endl;

    return 0;
}