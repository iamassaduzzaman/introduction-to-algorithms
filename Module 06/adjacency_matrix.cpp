#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int adjacenyMatrix[N][N];
int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjacenyMatrix[u][v] = 1;
        adjacenyMatrix[v][u] = 1; // undirected / directed
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adjacenyMatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}