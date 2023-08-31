#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

const int N = 1e5 + 5;
vector<pii> g[N];
bool visited[N];

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

class cmp
{
public:
    bool operator()(Edge a, Edge b)
    {
        return (a.w > b.w);
    }
};

void prims(int s, int n)
{
    vector<Edge> edgeList;
    int cnt = 0;
    priority_queue<Edge, vector<Edge>, cmp> pq;
    pq.push({s, s, 0});

    while (!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();
        int u = parent.u;
        int v = parent.v;
        int w = parent.w;
        if (visited[v])
            continue;

        cnt++;
        visited[v] = true;
        edgeList.push_back(parent);
        for (pii vpair : g[v])
        {
            if (!visited[vpair.first])
            {
                pq.push({v, vpair.first, vpair.second});
            }
        }
    }

    edgeList.erase(edgeList.begin());
    long long int sum = 0;
    for (Edge val : edgeList)
    {
        sum += (long long int)val.w;
    }

    if (cnt == n)
        cout << sum << endl;
    else
        cout << "IMPOSSIBLE" << endl;
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    prims(1, n);

    return 0;
}