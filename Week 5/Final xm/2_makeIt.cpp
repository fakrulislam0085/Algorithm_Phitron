#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll inpt;
int dp[100005];

bool makeIt(ll n)
{
    //base case to stop the recurtion
    if(n > inpt)    return false;
    if(n == inpt)   return true;
    if(dp[n] != -1) return dp[n];

    dp[n] = makeIt(n * 2) || makeIt(n + 3);
    return dp[n];

}
int main()
{
    //To avoid Time limit exceed error  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    
    int t;
    cin >> t;
    while(t--)
    {
        cin >> inpt;
        memset(dp, -1, sizeof(dp));

        bool flag = makeIt(1);

        if(flag)    cout << "YES" << endl;
        else    cout << "NO" << endl;
    }
    return 0;
}