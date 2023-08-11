#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adjList[N];

int visited[N] = {false};
int level[N] = {0};

bool flag = false;

void bfs(int u, int d)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        if (f == d)
            flag = true;

        for (int v : adjList[f])
        {
            if (!visited[v])
            {
                level[v] = level[f] + 1;
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int s, d;
        cin >> s >> d;
        bfs(s, d);
        if (flag)
        {
            cout << level[d] - level[s]<< endl;
        }
        else
        {
            cout << -1 << endl;
        }

        flag = false;
        for (int i = 0; i <= N; i++)
        {
            visited[i] = false;
            level[i] = 0;
        }
    }

    return 0;
}