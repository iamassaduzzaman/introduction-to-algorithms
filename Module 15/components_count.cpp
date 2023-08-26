#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
bool visited[N];
vector<int> value;

void dfs(int source)
{
    visited[source] = true;
    value.push_back(source);
    for (int v : g[source])
    {
        if (!visited[v])
        {
            visited[v] = true;
            dfs(v);
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cnt = 0;
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            cnt++;
            dfs(i);

            cout << "component: ";
            for (int val : value)
            {
                cout << val << " ";
            }
            cout << endl;
            value.clear();
        }
    }

    cout << "Total Components: " << cnt << endl;

    return 0;
}

/*
input
5
2
1 2
3 4

output
component: 1 2
component: 3 4
component: 5
Total Components: 3

*/