#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
bool visited[N];

// list 1: 3
// list 3: 1, 2, 5
// step 01. if value is the parent of list (since undirected graph) then skip
// step 02. if value is already visited and not a parent of list then cycle detected
// step 03. if 1 and 2 isn't true then call dfs again

bool dfs(int u, int p = -1)
{
    bool cycle = false;
    visited[u] = true;
    for(int v: adjList[u])
    {
        if(v == p) continue; 
        if(visited[v]) return true;
        cycle = cycle || dfs(v, u); 
    }
    return cycle; 
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


    if(dfs(1, -1))
    {
        cout << "cycle detected\n";
    }
    else
    {
        cout << "no cycle detected\n";
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "list " << i << ": ";
    //     for (int v : adjList[i])
    //     {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}

/*

list 1: 3 
list 2: 3 4 
list 3: 1 2 5 
list 4: 2 5 
list 5: 3 4 

*/

/*
sample input 01:
8
7
1 3
2 3
3 5
2 4
6 7
6 7
7 8

sample input 02:
5
5
1 3
2 3
3 5
2 4
4 5

*/