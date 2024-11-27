#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int par[N];
int group_size[N];

void dsuInitialize(int n)
{
    for(int i=0; i<n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
    }
}

int leaderFind(int node)
{
    if(par[node] == -1)
    {
        return node;
    } 
    int leader = leaderFind(par[node]);
    par[node] = leader;
    return leader;
}

void dsuUnionBySize(int node1, int node2)
{
    int leaderA = leaderFind(node1);
    int leaderB = leaderFind(node2);
    if(group_size[leaderA] > group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}

int main()
{
    dsuInitialize(8);
    
    dsuUnionBySize(1, 2);
    dsuUnionBySize(2, 3);
    dsuUnionBySize(4, 5);
    dsuUnionBySize(5, 6);
    dsuUnionBySize(1, 4);

    cout << leaderFind(1) << endl;
    cout << leaderFind(4) << endl;
    return 0;
}