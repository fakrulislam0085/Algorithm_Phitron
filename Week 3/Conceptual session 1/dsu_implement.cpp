#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define nl '\n'
using namespace std;

int parent[105];
int level[105];

void initialize(int sz)
{
    for(int i=0; i<sz; i++)
    {
        parent[i] = -1;
        level[i] = 0;
    }
}

int find(int node)
{
    if(parent[node] == -1)
    {
        return node;
    }
    else
    {
        int leader = find(parent[node]);
        parent[node] = leader;
        return leader;
    }
}

void Union(int p, int q) 
{
    int parentP = find(p);
    int parentQ = find(q);

    parent[parentQ] = parentP;
}

void UnionByRank(int p, int q)
{
    int parentP = find(p);
    int parentQ = find(q);

    if(level[parentP] > level[parentQ])
    {
        parent[parentQ] = parentP;
    }
    else if(level[parentQ] > level[parentP])
    {
        parent[parentP] = parentQ;
    }
    else
    {
        parent[parentQ] = parentP;
        level[parentP]++;
    }
}
int main()
{
    initialize(8);

    UnionByRank(1,2);
    UnionByRank(1,3);
    UnionByRank(4,5);
    UnionByRank(5,6);
    UnionByRank(7,8);

    for(int i=1; i<=8; i++)
    {
        int leaderA = find(1);
        int leaderB = find(i);

        if(leaderA != leaderB)
        {
            UnionByRank(1, i);
        }
    }


    return 0;
}