#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e3 + 5;
const int INF = 1e9 +5;
vector<pii> g[N];
vector<int> dist(N, INF);

void naiveDijkstra(int src)
{
    queue<int> q;
    q.push(src);
    dist[src] = 0;
    
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();

        for(auto pair: g[parent])
        {
            int node = pair.first;
            int weight =pair.second;

            if(dist[node] > dist[parent] + weight)
            {
                dist[node] = dist[parent] + weight;
                q.push(node);
            }
        }
    }

}

int main()
{
    int n, e;
    cin >> n >> e;
    for(int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    naiveDijkstra(1);

    for(int i = 1; i <= n; i++)
    {
        cout << "Distance of " << i << ": " << dist[i] << endl;
    }

    return 0;
}



/*
5
7
1 3 2
1 2 10
2 3 1
3 4 2
4 5 7
2 4 3
2 5 2

*/