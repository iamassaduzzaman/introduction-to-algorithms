#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
int n, m;
const int N = 1e3 + 5;
bool visited[N][N];
int dist[N][N];
vector<pii> direc = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    dist[si][sj] = 0;
    visited[si][sj] = true;

    while (!q.empty())
    {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();

        for (auto vpair : direc)
        {
            int ni = u + vpair.first;
            int nj = v + vpair.second;

            if (isValid(ni, nj) && !visited[ni][nj])
            {
                q.push({ni, nj});
                dist[ni][nj] = dist[u][v] + 1;
                visited[ni][nj] = true;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // input
        cin >> n >> m;
        int si, sj, di, dj;
        cin >> si >> sj >> di >> dj;

        // bfs call
        bfs(si, sj);

        // output
        if (isValid(di, dj) && visited[di][dj])
        {
            cout << dist[di][dj] << endl;
        }
        else
        {
            cout << -1 << endl;
        }

        // reset
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                visited[i][j] = false;
                dist[i][j] = 0;
            }
        }
    }
    return 0;
}