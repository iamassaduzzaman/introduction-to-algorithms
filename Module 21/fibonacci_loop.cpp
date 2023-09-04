#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    lli n;
    cin >> n;
    lli a[n+1];
    a[0] = 1;
    a[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        a[i] = a[i-1] + a[i-2];
    }
    cout << a[n] << endl;
    
    return 0;
}