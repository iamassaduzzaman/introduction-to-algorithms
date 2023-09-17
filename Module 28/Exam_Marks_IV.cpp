#include <bits/stdc++.h>
using namespace std;

const long long int MOD = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, val;
        cin >> n >> val;
        int w[n];
        for (int i = 0; i < n; i++)
        {
            cin >> w[i];
        }
        int s = 1000 - val;

        int dp[n + 1][s + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= s; i++)
            dp[0][i] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (w[i - 1] <= j)
                {
                    dp[i][j] = (dp[i][j - w[i - 1]] + dp[i - 1][j]) % MOD;
                }
                else
                {
                    dp[i][j] = (dp[i - 1][j]) % MOD;
                }
            }
        }

        cout << dp[n][s] % MOD << endl;
    }
    return 0;
}
