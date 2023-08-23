#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e; cin >> n >> e;
    vector<pair<int, int>> edgeList;

    for(int i = 0; i < e; i++)
    {
        int u, v; cin >> u >> v;
        edgeList.push_back({u, v});
    }

    for(auto vpair: edgeList)
    {
        cout << vpair.first << " ";
        cout << vpair.second << endl;
    }
    return 0;
}