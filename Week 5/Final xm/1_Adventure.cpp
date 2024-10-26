#include <bits/stdc++.h>
using namespace std;
const int mxN = 1000;
const int mxW = 1000;
int dp[mxN][mxW];

int KnapSack(int n, int w, int weight[], int value[])
{
    //base case to stop the recursion
    if(n < 0 || w==0)
        return 0;
    if(dp[n][w] != -1)
    {
        return dp[n][w];
    }
    
    if(weight[n] <= w)
    {
        //two options
        int opt1 = KnapSack(n-1, w - weight[n], weight, value) + value[n];
        int opt2 = KnapSack(n-1, w, weight, value);
        return dp[n][w] = max(opt1, opt2);
    }
    else
    {
        //1th option
        int opt1 = KnapSack(n-1, w, weight, value);
        return dp[n][w] = opt1;
    }
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
        int n, w;
        cin >> n >> w;
        int weight[n];
        for(int i=0; i<n; i++)
        {
            cin >> weight[i];
        }
        int value[n];
        for(int i=0; i<n; i++)
        {
            cin >> value[i];
        }

        memset(dp, -1, sizeof(dp));

    cout << KnapSack(n-1, w, weight, value) << endl;

    }
    return 0;
}