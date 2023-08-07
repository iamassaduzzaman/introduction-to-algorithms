#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool visited[N];
int depth[N];
int height[N];

void dfs(int u)
{
    visited[u] = true;
    // cout << "visiting node: " << u << endl;
    for(int v: adjList[u])
    {
        if(visited[v] == true) continue;
        depth[v] = depth[u] + 1;
        dfs(v);
        height[u] = max(height[u], height[v] + 1);
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
        adjList[v].push_back(u); // undirected / directed
    }

   dfs(1);

   for(int i = 1; i <= n; i++)
   {
    cout << "depth of node " << i << ": " << depth[i] << endl;
   }

   cout << "-------------------" << endl;
   
   for(int i = 1; i <= n; i++)
   {
    cout << "height of node " << i << ": " << height[i] << endl;
   }
    return 0;
}

/*
tree input
10
9
1 2
1 3
1 10
2 4
3 5 
3 6
4 7
4 8
6 9

graph input
11
11
1 2
2 3
3 8
1 5
5 4
5 6
4 7
6 7
7 8
8 9
10 11
*/