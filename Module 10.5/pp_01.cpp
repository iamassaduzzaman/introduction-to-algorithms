#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 5;
const int INF = 1e9;
vector<pii> g[N];
bool visited[N];
vector<int> dist(N, INF);

void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    dist[s] = 0;
    q.push({dist[s], s});
    visited[s] = true;

    while(!q.empty())
    {
        int f = q.top().second;
        q.pop();
        visited[f] = true;

        for(auto v: g[f])
        {
            int n = v.first;
            int w = v.second;
            
            if(visited[n]) continue;
            if(dist[n] > dist[f] + w)
            {
                dist[n] = dist[f] + w;
                q.push({dist[n], n});
            }
        
        }
    }

}

int main()
{
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int s, d;
    cin >> s >> d;

    dijkstra(s); 

    cout << dist[d] << endl;

    
    return 0;
}