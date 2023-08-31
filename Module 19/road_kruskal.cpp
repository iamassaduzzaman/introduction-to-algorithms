#include <bits/stdc++.h>
using namespace std;

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

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

const int N = 1e5 + 5;
int parent[N];
int parentSize[N];

// intial value set
void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}

// find parent
int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}

// merge two group
void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);

    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            // A leader
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> g;
    vector<Edge> answer;
    dsu_set(n);
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.push_back(Edge(u, v, w));
    }

    sort(g.begin(), g.end(), cmp);

    for (Edge val : g)
    {
        int a = val.u;
        int b = val.v;
        int w = val.w;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA == leaderB)
            continue;

        answer.push_back(val);
        dsu_union(a, b);
    }

    long long int sum = 0;
    for (Edge val : answer)
    {
        sum += (long long)val.w;
    }

    if (answer.size()  == n - 1)
        cout << sum << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}
