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
        adjList[v].push_back(u);
    }
    int k;
    cin >> k;

    int cnt = 0;
    for (int v : adjList[k])
    {
        cnt++;
    }

    cout << cnt << endl;
    return 0;
}