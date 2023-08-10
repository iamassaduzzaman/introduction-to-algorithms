#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool visited[N];
int height[N] = {0};

void dfs(int u)
{
    visited[u] = true;
    for(int v: adjList[u])
    {
        if(!visited[v])
        {
            dfs(v);
            height[u] = max(height[u], height[v] + 1);
        }
    }
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

    int k; cin >>k;

    dfs(1);

    cout << "height of " << k << " = " << height[k];
    return 0;
}