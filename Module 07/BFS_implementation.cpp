#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adjList[N];

bool visited[N];
int depth[N] = {0};

void bfsTraversal(int val)
{
    queue<int> q;
    q.push(val);

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        cout << "visiting node: " << f << endl;
        visited[f] = true;

        for (int n : adjList[f])
        {
            if (!visited[n])
            {
                depth[n] = depth[f] + 1;
                q.push(n);
                visited[n] = true;
            }
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
        // adjList[v].push_back(u); // directed / undirected
    }
    
    cout << endl;

    bfsTraversal(1);

    cout << endl;

    for(int i = 1; i <= n; i++)
    {
        cout << "depth of node " << i << ": " << depth[i] <<endl; 
    }

    return 0;
}

/*
tree input
12
11
1 2
1 3
1 10
2 4
2 5
3 9
10 11
10 12
5 6
5 7
7 8

*/