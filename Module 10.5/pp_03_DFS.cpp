#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 5;
vector<string> g;
bool visited[N][N];
int n, m;
bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}
vector<pii> direc = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

void dfs(int si, int sj)
{
    if (!isValid(si, sj))
        return;
    if (visited[si][sj])
        return;
    if (g[si][sj] == 'x')
        return;

    visited[si][sj] = true;

    for(auto v: direc)
    {
        dfs(si + v.first, sj + v.second);
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
            {
                si = i;
                sj = j;
            }
            if (x[j] == 'e')
            {
                di = i;
                dj = j;
            }
        }
        g.push_back(x);
    }

    dfs(si, sj);

    if(visited[di][dj]) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}