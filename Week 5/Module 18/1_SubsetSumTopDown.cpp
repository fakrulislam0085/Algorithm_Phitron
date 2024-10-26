#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];

bool subsetSum(int n, int ar[], int s)
{
    //base case
    if(n == 0)
    {
        if(s == 0)
            return true;
        else    
            return false;
    }

    if(dp[n][s] != -1)
        return dp[n][s];

    if(ar[n-1] <= s)
    {
        bool opt1 = subsetSum(n-1, ar, s-ar[n-1]);
        bool opt2 = subsetSum(n-1, ar, s);
        return dp[n][s] = opt1 || opt2;
    }
    else
    {
        return dp[n][s] = subsetSum(n-1, ar, s);
    }
}
int main()
{
    int n;
    cin >> n;
    int ar[n];
    for(int i=0; i<n; i++)
    {
        cin >> ar[i];
    }
    int s;
    cin >> s;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=s; j++)
        {
            dp[i][j] = -1;
        }
    }
    if(subsetSum(n, ar, s))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}