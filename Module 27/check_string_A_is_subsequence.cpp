#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();

    // NORMAL APPROACH o(n+m)
    // int p = 0;
    // bool isSubsequence = false;
    // for (char c : b)
    // {
    //     if (c == a[p])
    //     {
    //         p++;
    //     }

    //     if (p == a.size())
    //     {
    //         isSubsequence = true;
    //     }
    // }

    // if (isSubsequence)
    //     cout << "YES\n";
    // else
    //     cout << "NO\n";

    // LCS approach O(n*m)
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = n, j = m;
    string ans;
    while (i != 0 && j != 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            ans += a[i - 1];
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    if (ans == a)
        cout << endl
             << "YES\n";
    else
        cout << endl
             << "NO\n";

    return 0;
}

/*
input
AXE
BKAZXKJXKEL
*/