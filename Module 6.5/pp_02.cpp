#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int adjMatrix[N][N];
vector<int> adjList[N];


int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int k; cin >> k;
            adjMatrix[i][j] = k;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
           if(adjMatrix[i][j] != 0)
           {
            adjList[i].push_back(j);
           }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        cout << "List " << i << ": ";
        for(int k: adjList[i])
        {
           cout << k << " ";
        }
        cout << endl;
    }
    
    return 0;
}