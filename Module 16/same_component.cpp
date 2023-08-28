#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int v, e;
const int N = 1e3 + 5;
bool visited[N][N];
char g[N][N];
vector<pii> direc = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool isValid(int i, int j)
{
    return (i >= 0 && i < v && j >= 0 && j < e);
}

void dfs(int si, int sj)
{
    visited[si][sj] = true;
    for (auto vpair : direc)
    {
        int u = si + vpair.first;
        int v = sj + vpair.second;

        if (isValid(u, v) && !visited[u][v] && g[u][v] != '-')
        {
            dfs(u, v);
        }
    }
}
int main()
{
    cin >> v >> e;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < e; j++)
        {
            cin >> g[i][j];
        }
    }
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;

    dfs(si, sj);

    if (visited[di][dj])
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}