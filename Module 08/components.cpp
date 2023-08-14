#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adjList[N];
bool visited[N];

int cnt = 1;
vector<int> v;

void bfs(int u)
{
    queue<int> qq;
    qq.push(u);

    while (!qq.empty())
    {
        int f = qq.front();
        qq.pop();
        visited[f] = true;

        for (int v : adjList[f])
        {
            if (!visited[v])
            {
                cnt++;
                qq.push(v);
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

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            bfs(i);
            v.push_back(cnt);
            cnt = 1;
        }
    }

    sort(v.begin(), v.end());
    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (*it != 1)
        {
            cout << *it << " ";
        }
    }

    return 0;
}