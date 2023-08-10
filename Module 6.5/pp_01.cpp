#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adjList[N];
bool visited[N];
stack<int> st;

void dfs(int u)
{
    visited[u] = true;
    for (int v : adjList[u])
    {
        if (!visited[v])
        {
            dfs(v);
            cout << v << " ";
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
    }

    dfs(1);
    cout << 1; 

    return 0;
}