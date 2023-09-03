#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

const int N = 1e5 + 5;
vector<pii> g[N];
bool visited[N];
int n, e;

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

// coparison class
class cmp
{
    public:
    bool operator()(Edge a, Edge b)
    {
        return (a.w > b.w);
    }
};

vector<Edge> edgeList;
void prims(int src)
{
    priority_queue<Edge, vector<Edge>, cmp> pq;
    pq.push(Edge(src, src, 0));

    int cnt = 0;
    while(!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();
        int u = parent.u;
        int v = parent.v;
        int w = parent.w;
        if(visited[v]) continue;

        cnt++;
        visited[v] = true;
        edgeList.push_back(parent);
        for(pii vpair: g[v])
        {
            pq.push(Edge(v, vpair.first, vpair.second));
        }
    }

    long long int sum = 0;
    for(Edge wt: edgeList)
    {
        sum += (long long int)wt.w;
    }

    if(n == cnt) cout << sum << endl;
    else cout << -1 << endl;

}

int main()
{
    cin >> n >> e;
    while(e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    prims(1);
    
    return 0;
}