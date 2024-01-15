#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> printClosest(int arr[], int brr[], int n, int m, int x)
{

    vector<int> v;

    int i = 0, j = m - 1;
    int sum = 0;
    int a, b;
    int ans = INT_MAX;
    while (i < n && j >= 0)
    {

        if (abs(arr[i] + brr[j] - x) < ans)
        {
            ans = abs(arr[i] + brr[j] - x);
            a = arr[i];
            b = brr[j];
        }

        if ((arr[i] + brr[j]) - x < 0)
        {
            i++;
        }
        else if ((arr[i] + brr[j]) - x > 0)
        {
            j--;
        }
        else
        {
            break;
        }
    }
    if (a < b)
    {
        v.push_back(a);
        v.push_back(b);
    }
    else
    {
        v.push_back(b);
        v.push_back(a);
    }
    return v;
}