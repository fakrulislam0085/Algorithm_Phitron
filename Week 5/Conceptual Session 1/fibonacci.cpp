//Top down approach

#include <bits/stdc++.h>
using namespace std;

int dp[100001];
int fibo(int n)
{
    //base case
    //in fibonacci series, the value of 1th index is 1, 
    //the value of 0th index is 0; 
    if(n < 2)
        return n;
    if(dp[n] != -1)    //optimization  or memoization
        return dp[n];
    
    else
    {
        dp[n] = fibo(n-1) + fibo(n-2);
        return dp[n];
    }
}
int main()
{
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));

    cout << fibo(n) << endl;
    return 0;
}