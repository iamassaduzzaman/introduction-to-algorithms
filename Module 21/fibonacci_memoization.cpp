#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll N = 1e5 + 5;
ll save[N];

ll fibonacci(int n)
{
    if (n == 0 || n == 1)
        return 1;

    if (save[n] != -1)
        return save[n];

    ll a = fibonacci(n - 1);
    ll b = fibonacci(n - 2);
    save[n] = a + b;
    return a + b;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        save[i] = -1;
    }

    cout << fibonacci(n) << endl;
    return 0;
}