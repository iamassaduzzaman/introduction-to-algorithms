#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;

int main()
{
    int n, e;
    cin >> n >> e;
    long long int dist[n + 1][n + 1];

    // initializing the initial distance
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    // edge input
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        if(dist[a][b] > w)
        {
           dist[a][b] = w;
        }
    }

    // floyd warshell algorithm
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k]!=INF && dist[k][j]!=INF && dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF)
            cout << "-1" << endl;
        else
            cout << dist[a][b] << endl;
    }
    return 0;
}
