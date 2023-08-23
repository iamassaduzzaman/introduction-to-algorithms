#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
bool visited[N];

void dfs(int src)
{
    visited[src] = true;
    cout << src << endl;

    for (int child : g[src])
    {
        if (!visited[child])
        {
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    return 0;
}

/*
5
4
1 2
1 3
2 4
4 5
*/