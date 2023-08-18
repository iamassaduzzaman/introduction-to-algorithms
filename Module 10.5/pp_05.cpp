#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 5;
vector<string> g;
bool visited[N][N];
int level[N][N];
pii parent[N][N];
vector<pii> direc = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
int n, m;
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    level[si][sj] = 0;
    visited[si][sj] = true;

    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for (pii d : direc)
        {
            int ni = i + d.first;
            int nj = j + d.second;

            if (isValid(ni, nj) && !visited[ni][nj] && g[ni][nj] != 'x')
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
                parent[ni][nj] = {i, j};
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    int si, sj, di, dj;
    for (int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        for (int j = 0; j < m; j++)
        {
            if (x[j] == 's')
                si = i, sj = j;
            if (x[j] == 'e')
                di = i, dj = j;
        }
        g.push_back(x);
    }

    bfs(si, sj);
    if (level[di][dj] != 0)
    {
        cout << level[di][dj] << endl;

        vector<pii> path;
        pii current = {di, dj};
        while (true)
        {
            path.push_back({current.first, current.second});
            if (current.first == si && current.second == sj)
                break;
            current = {parent[current.first][current.second]};
        }

        reverse(path.begin(), path.end());

        for (int i = 1; i < path.size(); i++)
        {
            if (path[i - 1].first == path[i].first)
            {
                if (path[i - 1].second == path[i].second + 1)
                {
                    cout << "L";
                }
                else
                {
                    cout << "R";
                }
            }
            else
            {
                if (path[i - 1].first == path[i].first + 1)
                {
                    cout << "U";
                }
                else
                {
                    cout << "D";
                }
            }
        }
    }
    else
        cout << -1 << endl;
    return 0;
}