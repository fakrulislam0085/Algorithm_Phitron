#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int par[N];

void dsuInitialize(int n)
{
    for(int i=0; i<n; i++)
    {
        par[i] = -1;
    }
    par[2] = 1;
    par[1] = 5;
    par[3] = 4;
}

int leaderFind(int node)
{
    if(par[node] == -1) return node;
    
    // Path compression using recursive call
    int leader = leaderFind(par[node]);
    par[node] = leader;
    return leader;
}

int main()
{
    dsuInitialize(6);
    cout << leaderFind(0) << endl;
    cout << leaderFind(1) << endl;
    cout << leaderFind(2) << endl;
    cout << leaderFind(4) << endl;
    cout << leaderFind(5) << endl;
    return 0;
}
