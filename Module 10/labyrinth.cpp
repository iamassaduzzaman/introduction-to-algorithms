#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 5;
vector<string> g;
bool visited[N][N];
int level[N][N] = {0};
pii parent[N][N];
int n, m;
vector<pii> direc = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        int f = q.front().first;
        int s = q.front().second;
        q.pop();

        for (auto d : direc)
        {
            int ni = f + d.first;
            int nj = s + d.second;

            if (isValid(ni, nj) && !visited[ni][nj] && g[ni][nj] != '#')
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[f][s] + 1;
                parent[ni][nj] = {f, s};
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
            if (x[j] == 'A')
            {
                si = i;
                sj = j;
            }
            if (x[j] == 'B')
            {
                di = i;
                dj = j;
            }
        }
        g.push_back(x);
    }

    bfs(si, sj);

    if (level[di][dj] != 0)
    {
        cout << "YES\n";
        cout << level[di][dj] << endl;

        vector<pii> path;
        pii current = {di, dj};
        while (true)
        {
            path.push_back(current);
            if (current.first == si && current.second == sj)
                break;
            current = parent[current.first][current.second];
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
    {
        cout << "NO\n";
    }

    return 0;
}

/*

INPUT
5 8
########
#.A#...#
#.##.#B#
#......#
########

OUTPUT
YES
9
LDDRRRRRU


*/