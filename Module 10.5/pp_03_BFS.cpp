#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 5;
vector<string> g;
bool visited[N][N];
int level[N][N];
vector<pii> direc = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int n, m;
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

    while(!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for(auto vpari: direc)
        {
            int ni = i + vpari.first;
            int nj = j + vpari.second;

            if(isValid(ni, nj) && !visited[ni][nj] && g[ni][nj] != 'x')
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
            }
        }

    }
}

int main()
{
    cin >> n >> m;
    int si, sj, di, dj;
    for(int i = 0; i < n; i++)
    {
        string x; cin >> x;
        for(int j = 0; j < m; j++)
        {
            if(x[j] == 's')
            {
                si = i;
                sj = j;
            }
            if(x[j] == 'e')
            {
                di = i; 
                dj = j;
            }
        }
        g.push_back(x);
    }

    bfs(si, sj);

    if(level[di][dj] != 0) cout << "YES\n";
    else cout << "NO\n"; 
    
    return 0;
}