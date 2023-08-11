#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool visited[N];
int cnt = 0;

void dfs(int u)
{
    visited[u] = true;
    cnt++;
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
    }
    int k;
    cin >> k;

    dfs(k);
    cout << cnt-1 << endl;

    return 0;
}

// for(int i = 0; i <= n; i++)
// {
//     cout << "list " << i << ": ";
//     for(int v: adjList[i])
//     {
//         cout << v << " ";
//     }
//     cout << endl;
// }