#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
typedef pair<int, int> pii;
vector<string> g;
bool visited[N][N];
int level[N][N];
vector<pii> direc = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
bool isValid(int i, int j)
{
    return (i >= 0 && i < 8 && j >= 0 && j < 8);
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

        for (auto d : direc)
        {
            int ni = i + d.first;
            int nj = j + d.second;

            if (isValid(ni, nj) && !visited[ni][nj])
            {
                q.push({ni, nj});
                level[ni][nj] = level[i][j] + 1;
                visited[ni][nj] = true;
            }
        }
    }
}

// reset
void resetVisitLevel()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            level[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x, y;
        cin >> x >> y;
        int si, sj, di, dj;
        si = x[0] - 'a';
        sj = x[1] - '1';
        di = y[0] - 'a';
        dj = y[1] - '1';
        bfs(si, sj);
        cout << level[di][dj] << endl;
        resetVisitLevel();
    }
    return 0;
}
