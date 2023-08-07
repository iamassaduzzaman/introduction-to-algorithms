#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool visited[N];

void dfs(int u)
{
    // section 1: actions just after entering node u
    visited[u] = true;
    cout << "visiting node: " << u << endl;
    for(int v: adjList[u])
    {
        // setion 2: actions before entering a new neighbor
        if(visited[v] == true) continue;
        dfs(v);
        //section 3: actions after exiting a neighbor 
    }
    // section 4: actions before exiting node u
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

    // for(int i = 1; i <= n; i++)
    // {
    //     cout << "Node " << i << ": ";

    //     for(int j: adjList[i])
    //     {
    //        cout << j << " ";
    //     }
    //     cout << endl;
    // }

   dfs(1);

   cout << "visiting array\n";
   for(int i = 1; i <= n; i++)
   {
    cout << "Node " << i << " status: " << visited[i] << endl;
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