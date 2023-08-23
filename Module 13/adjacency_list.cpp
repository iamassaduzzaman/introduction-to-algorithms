#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adjList[n+1];
    while(e--)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i = 0; i < n+1; i++)
    {
        cout << "Index " << i << ": ";
        for(auto v:  adjList[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}