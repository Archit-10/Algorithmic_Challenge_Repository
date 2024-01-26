#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int viralAdvertising(int n)
{
    int liked = 0;
    int sum = 0;
    int shared = 5;
    for (int i = 1; i <= n; i++)
    {
        liked = floor(shared / 2);
        sum += liked;
        shared = liked * 3;
    }
    return sum;
}