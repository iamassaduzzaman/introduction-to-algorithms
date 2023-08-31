#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

const int N = 1e5 + 5;
vector<pii> g[N];
bool visited[N];

// edge
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

// comparison
class cmp
{
public:
    bool operator()(Edge a, Edge b)
    {
        return (a.w > b.w);
    }
};

vector<Edge> edgeList;
void prims(int s)
{
    priority_queue<Edge, vector<Edge>, cmp> pq;
    pq.push(Edge(s, s, 0));

    while (!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();
        int u = parent.u;
        int v = parent.v;
        int w = parent.w;
        if (visited[v])
            continue;


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

    edgeList.erase(edgeList.begin()); // delete first element of the vector
    cout << endl;
    for (Edge val : edgeList)
    {
        cout << val.u << " " << val.v << " " << val.w << endl;
    }
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

    prims(1);

    return 0;
}

/*
input:
8 11
1 5 2
1 2 4
1 4 10
5 4 5
2 4 8
2 3 18
3 4 11
4 8 9
4 7 11
7 6 1
8 6 2

output:
1 5 2
1 2 4
5 4 5
4 8 9
8 6 2
6 7 1
4 3 11

*/
