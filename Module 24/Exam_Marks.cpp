#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
bool exam_marks(int n, int a[], int s)
{
    if (n == 0)
    {
        if (s == 0)
            return true;
        else
            return false;
    }

    if (dp[n][s] != -1)
        return dp[n][s];

    if (a[n - 1] <= s)
    {
        bool op1 = exam_marks(n - 1, a, s - a[n - 1]);
        bool op2 = exam_marks(n - 1, a, s);
        return dp[n][s] = op1 || op2;
    }
    else
    {
        return dp[n][s] = exam_marks(n - 1, a, s);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int s = 1000 - m;

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                dp[i][j] = -1;
            }
        }

        if (exam_marks(n, a, s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
