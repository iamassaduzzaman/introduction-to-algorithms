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
int tempArea = 0;

void dfs(int si, int sj)
{
    visited[si][sj] = true;
    tempArea++;
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
    int minArea = INT_MAX;
    cin >> v >> e;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < e; j++)
        {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < e; j++)
        {
            if(!visited[i][j] && g[i][j] == '.')
            {
                dfs(i, j);
                if(tempArea <= minArea)
                {
                   minArea = tempArea;
                }
                tempArea = 0;
            }
        }
    }

    if(minArea == INT_MAX) cout << -1 << endl;
    else cout << minArea << endl;

    return 0;
}