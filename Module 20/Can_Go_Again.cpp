#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const long long int INF = 1e18;
vector<long long int> dist(N, INF);

// edge class
class Edge
{
public:
    int u, v, w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

vector<Edge> g;
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Edge ed(u, v, w);
        g.push_back(ed);
    }
    int src;
    cin >> src;
    dist[src] = 0;

    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < g.size(); j++)
        {
            Edge val = g[j];
            int u = val.u;
            int v = val.v;
            int w = val.w;

            if (dist[u] != INF && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    bool cycle = false;
    for (int j = 0; j < g.size(); j++)
    {
        Edge val = g[j];
        int u = val.u;
        int v = val.v;
        int w = val.w;

        if (dist[u] != INF && dist[v] > dist[u] + w)
        {
            cycle = true;
            break;
            dist[v] = dist[u] + w;
        }
    }

    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
    }
    else
    {
        int q;
        cin >> q;
        while (q--)
        {
            int d;
            cin >> d;
            if(dist[d] == INF) cout << "Not Possible\n";
            else cout << dist[d] << endl;
        }
    }
    return 0;
}
