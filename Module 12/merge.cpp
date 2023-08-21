#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int m, int r)
{
    int leftSize = m - l + 1;
    int rightSize = r - m;
    int L[leftSize], R[rightSize];

    // making a two copy of the array
    int k = 0;
    for (int i = l; i <= m; i++)
    {
        L[k] = a[i];
        k++;
    }
    k = 0;
    for (int i = m + 1; i <= r; i++)
    {
        R[k] = a[i];
        k++;
    }

    // merge two copy by comparing 
    int i = 0, j = 0;
    k = l;
    while (i < leftSize && j < rightSize)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < leftSize)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    merge(a, 0, 3, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}

/*

input
10
2 3 5 10 1 4 6 8 9 15

*/