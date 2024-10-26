//knapSack Top Down Approach

#include <bits/stdc++.h>
using namespace std;
const int maxW = 1000;
const int maxN = 1000;
int dp[maxN][maxW];

int knapSack(int n, int weight[], int value[], int w)
{

    if(n<=0 || w == 0)    //base case
        return 0;
    if(dp[n][w] != -1)
        return dp[n][w];

    if(weight[n] <= w)
    {
        //two options:
        //last weight niye dekhbo
        int opt1 = knapSack(n-1, weight, value, w-weight[n]) + weight[n];
        //last weight na niye dekhbo
        int opt2 = knapSack(n-1, weight, value, w);

        return dp[n][w] = max(opt1, opt2);
    }
    else
    {
        //one option: na niye dekhbo
        int opt1 = knapSack(n-1, weight, value, w);
        return opt1;
    }
}
int main()
{
    int n;
    cin >> n;
    int weight[n];
    int value[n];

    for(int i=0; i<n; i++)
    {
        cin >> weight[i];
    }
    for(int i=0; i<n; i++)
    {
        cin >> value[i];
    }
    int w;
    cin >> w;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=w; j++)
        {
            dp[i][j] = -1;
        }
    }
    
    
    cout << knapSack(n-1, weight, value, w);
    return 0;
}
