#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool visited[N];

bool dfs(int u, int p = -1)
{
    bool ifCycle = false;
    visited[u] = true;
    for(int v: adjList[u])
    {
      if(v == p) continue;
      if(visited[v]) return true;
      ifCycle |= dfs(v, u);
    }
    return ifCycle;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    if(dfs(1, -1)) cout << "YES\n";
    else cout << "NO\n";
    
    return 0;
}