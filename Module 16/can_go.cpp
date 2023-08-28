#include <bits/stdc++.h>
#define pii pair<long long int, long long int>
using namespace std;

const int N = 1e5 + 5;
const int INF = 1e9 + 5;
vector<pii> g[N];
bool visited[N];
vector<int> dist(N, INF);

void bfs(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dist[s] = 0;
    q.push({dist[s], s});

    while(!q.empty())
    {
        long long int v = q.top().second;
        q.pop();
        visited[v] = true;

        for(auto vpair: g[v])
        {
            long long int u = vpair.first;
            long long int w = vpair.second;
            
            if(visited[u]) continue;
            if(dist[u] > dist[v] + w)
            {
                dist[u] = dist[v] + w;
                q.push({dist[u], u});
            }
        }
    }
    
}

int main()
{
    long long int n, e;
    cin >> n >> e;
    while(e--)
    {
        long long int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    int s; cin >> s;
    bfs(s);

    int t; cin >> t;
    while(t--)
    {
        long long int d, dw;
        cin >> d >> dw;
        if(dist[d] <= dw)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}
