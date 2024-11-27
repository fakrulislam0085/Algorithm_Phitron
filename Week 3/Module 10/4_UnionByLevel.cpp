#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int par[N];
int group_size[N];
int level[N];

void dsu_Initialize(int n)
{
    for(int i=0; i<n; i++)
    {
        par[i] = -1;
        group_size[i] = 1;
        level[i] = 0;
    }
}

int dsu_leaderFind(int node)
{
    if(par[node] == -1)
    {
        return node;
    } 
    int leader = dsu_leaderFind(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_UnionBySize(int node1, int node2)
{
    int leaderA = dsu_leaderFind(node1);
    int leaderB = dsu_leaderFind(node2);
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

void dsu_UnionByLevel(int node1, int node2)
{
    int leaderA = dsu_leaderFind(node1);
    int leaderB = dsu_leaderFind(node2);
    if(level[leaderA] > level[leaderB])
    {
        par[leaderB] = leaderA;
    }
    else if(level[leaderB] > level[leaderA])
    {
        par[leaderA] = leaderB;
    }
    else
    {
        par[leaderA] = leaderB;   //jekhono ekta korlei hbe
        level[leaderB]++;
    }
}

int main()
{
    dsu_Initialize(8);
    
    dsu_UnionByLevel(1, 2);
    dsu_UnionByLevel(2, 3);
    dsu_UnionByLevel(4, 5);
    dsu_UnionByLevel(5, 6);
    dsu_UnionByLevel(1, 4);
    

    cout << dsu_leaderFind(1) << endl;
    cout << dsu_leaderFind(4) << endl;
    return 0;
}