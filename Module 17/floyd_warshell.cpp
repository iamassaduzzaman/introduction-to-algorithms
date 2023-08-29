#include <bits/stdc++.h>
using namespace std;
const int INF = 1e7;

int main()
{
    int n, e;
    cin >> n >> e;
    int dist[n + 1][n + 1];

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
        dist[a][b] = w;
    }
    cout << endl;

    // output before applying floyd warshell
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
                cout << "X ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;


    // floyd warshell algorithm
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // output after applying floyd warshell
    cout << "Updated" << endl << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
                cout << "X ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*

input:
4 6
1 2 3
2 1 2
1 4 5
4 3 2
3 2 1
2 4 4

output:
0 3 X 5 
2 0 X 4 
X 1 0 X 
X X 2 0 

Updated

0 3 7 5 
2 0 6 4 
3 1 0 5 
5 3 2 0 

*/