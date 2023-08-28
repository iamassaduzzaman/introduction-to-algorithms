#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

const int N = 1e5 + 5;
vector<pii> g;

int main()
{
    int e;
    cin >> e;
    while(e--)
    {
        int u, v;
        cin >> u >> v;
        g.push_back({u, v});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    for(int i = 0; i < g.size(); i++)
    {
        pq.push({g[i].first, g[i].second});
    }
    
    for(int i = 0; i < g.size(); i++)
    {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
    
    return 0;
}

/*

6
3 4
3 2
3 5
1 2
1 4
1 5

*/