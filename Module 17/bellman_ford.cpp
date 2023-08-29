#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;
const int N = 1e3 + 5;

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

vector<Edge> v;
vector<int> dist(N, INF);
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Edge ed(a, b, c);
        v.push_back(ed);
    }

    dist[1] = 0;

    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;
            if (dist[b] > dist[a] + w)
            {
                dist[b] = dist[a] + w;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << ": " << dist[i] << endl;
    }

    return 0;
}

/*

input:
4 4
1 2 5
2 3 2
3 4 -2
1 4 10

output:
Node 1: 0
Node 2: 5
Node 3: 7
Node 4: 5
*/