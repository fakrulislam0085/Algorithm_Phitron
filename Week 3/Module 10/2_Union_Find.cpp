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
    par[1] = 2;
    par[2] = 3;
    par[5] = 6;
    par[6] = 7;
}

int leaderFind(int node)
{
    if(par[node] == -1) return node;
    int leader = leaderFind(par[node]);
    par[node] = leader;
    return leader;
}

void dsuUnion(int node1, int node2)
{
    int leaderA = leaderFind(node1);
    int leaderB = leaderFind(node2);
    
    par[leaderA] = leaderB;   
}

int main()
{
    dsuInitialize(8);
    //cout << leaderFind(2) << endl;
    dsuUnion(1,5);
    //cout << leaderFind(2) << endl;
    
    return 0;
}