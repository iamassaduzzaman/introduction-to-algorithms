#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9 + 10;
const int N = 1e5 + 10;
vector<pii> g[N];
bool visited[N];
vector<int> dist(N, INF);

void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[s] = 0;
    pq.push({dist[s], s});

    while(!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();
        visited[node] = true;

        for(auto vpair: g[node])
        {
            int w = vpair.second;
            int nod = vpair.first;

            if(visited[nod]) continue;
            if(dist[nod] > dist[node] + w)
            {
                dist[nod] = dist[node] + w;
                pq.push({dist[nod], nod});
            }

        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v, w; 
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    
    int s, d;
    cin >> s >> d;

    dijkstra(s);

    cout << dist[d] << endl;
    return 0;
}