#include <bits/stdc++.h>
using namespace std;
#define lli long long int

const int N = 1e5 + 5;
int val;
lli dp[N];
bool reach(lli i)
{
    if (val < i)
    {
        return false;
    }
    else if (val == i)
    {
        return true;
    }
    else if (dp[i] != -1)
    {
        return dp[i];
    }
    else
    {
        return dp[i] = reach(i + 3) || reach(i * 2);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> val;
        for (int i = 0; i < N; i++)
        {
            dp[i] = -1;
        }
        if (reach(1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}