#include <bits/stdc++.h>
using namespace std;

int knapSack(int n, int weight[], int value[], int mxW)
{
    
    if(n<=0 || mxW == 0)    //base case
        return 0;
    
    if(weight[n] <= mxW)
    {
        //two options: niye dekhbo  or na niye dekhbo
        int opt1 = knapSack(n-1, weight, value, mxW - weight[n]) + value[n];
        int opt2 = knapSack(n-1, weight, value, mxW);

        return max(opt1, opt2);
    }
    else
    {
        //one option: na niye dekhte hbe
        int opt2 = knapSack(n-1, weight, value, mxW);
        return opt2;
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

    int mxW;
    cin >> mxW;

    cout << knapSack(n-1, weight, value, mxW);
    return 0;
}