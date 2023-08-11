#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adjList[N];
bool visited[N];

void dfs(int u)
{
    visited[u] = true;
    for(int v: adjList[u])
    {
        if(!visited[v])
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
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        // adjList[v].push_back(u);
    }
    
    int componentCount = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            componentCount++;
            dfs(i);
        }
    }

    cout << "total component: " << componentCount << endl;
    return 0;
}

/*

intput
7
5
1 2
1 3
2 4
2 3
5 6

*/