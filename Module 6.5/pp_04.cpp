#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool visitd[N];
int depth[N] = {0};

void dfs(int u)
{
    visitd[u] = true;
    for (int l : adjList[u])
    {
        if (!visitd[l])
        {
            depth[l] = depth[u] + 1;
            dfs(l);
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
        // adjList[v].push_back(u);
    }
    int k;
    cin >> k;

    dfs(1);

    cout << "Depth of " << k << " = " << depth[k];

    // for(int i = 1; i <=n; i++)
    // {
    //     cout << "List " << i << ": ";
    //     for(int v: adjList[i])
    //     {
    //        cout << v << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
/*
7
6
1 2
2 4
2 5
1 3
3 6
1 7
7
*/