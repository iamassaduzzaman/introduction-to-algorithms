#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

const int N = 1e3 + 5;
char g[N][N];
bool visited[N][N];
int dist[N][N];
int n, m;
vector<pii> direc = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
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

    while(!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for(pii vpair: direc)
        {
            int ni = i + vpair.first;
            int nj = j + vpair.second;
            
            if(isValid(ni, nj) && !visited[ni][nj])
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                dist[ni][nj] = dist[i][j] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
           cin >> g[i][j]; 
        }
    }
    
    int si, sj; cin >> si >> sj;
    bfs(si, sj);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
           cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

/*

intput
2 4
....
....
0 1

output
1 0 1 2 
2 1 2 3 

*/