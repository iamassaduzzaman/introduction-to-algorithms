#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adjList[N];
int adjMatrix[N][N] = {0};

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int k : adjList[i])
        {
            adjMatrix[i][k] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k <= n; k++)
        {
            cout << adjMatrix[i][k] << " ";
        }
        cout << endl;
    }

    return 0;
}