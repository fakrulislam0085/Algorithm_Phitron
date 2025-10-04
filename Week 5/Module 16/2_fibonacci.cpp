#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e6 + 10;
ll dp[N];

//top-down technique
ll fibo(ll n)
{
    if(n == 0 || n == 1)   //base case
    {
        return n;   //in the fibonacci series, the value of 0 index is 0, and value of 1 index is 1
    }

    //memoization
    if(dp[n] != -1)
    {
        return dp[n];
    }
    
    ll sum = fibo(n-1) + fibo(n-2);
    dp[n] = sum;
    return sum;
}

int main()
{
    ll n;
    cin >> n;   

    memset(dp, -1, sizeof(dp));

    ll ans = fibo(n);

    cout << ans << endl;
    return 0;
}
