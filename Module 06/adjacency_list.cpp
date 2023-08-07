#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];
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

    for (int i = 1; i <= m; i++)
    {
        cout << "List " << i << ": ";
        for (int j : adjList[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}