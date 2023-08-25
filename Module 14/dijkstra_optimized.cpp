#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N = 1e5 + 5;
const int INF = 1e9 + 5;
vector<pii> g[N];
bool visited[N];
vector<int> dist(N, INF);

void dijkstra(int source)
{
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  dist[source] = 0;
  pq.push({dist[source], source});

  while(!pq.empty())
  {
    int parent = pq.top().second;
    pq.pop();
    visited[parent] = true;

    for(auto child: g[parent])
    {
        int v = child.first;
        int w = child.second;

        if(visited[v]) continue;
        if(dist[v] > dist[parent] + w)
        {
            dist[v] = dist[parent] + w;
            pq.push({dist[v], v});
        }
    }
  }
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dijkstra(1);

    for(int i = 1; i <= n; i++)
    {
        cout << "Distance of " << i << ": " << dist[i] << endl;
    }
    
    return 0;
}

/*
input
5 7
1 3 2
1 2 10
2 3 1
3 4 2
4 5 7
2 4 3
2 5 2
*/