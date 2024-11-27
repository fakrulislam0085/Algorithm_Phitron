#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int parent[N];
int grpSz[N];

void dsuInitialize(int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i] = -1;
        grpSz[i] = 1;
    }
}

int find(int node)
{
    if(parent[node] == -1) return node;
    else
    {
        int leader = find(parent[node]);
        parent[node] = leader;
        return leader;
    }
}

void UnionBySize(int p, int q)
{
    int ldr1 = find(p);
    int ldr2 = find(q);

    if(ldr1 == ldr2)    return;
    
    if(grpSz[ldr1] > grpSz[ldr2])
    {
        parent[ldr2] = ldr1;
        grpSz[ldr1] += grpSz[ldr2];
    }
    else
    {
        parent[ldr1] = ldr2;
        grpSz[ldr2] += grpSz[ldr1];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    dsuInitialize(n);

    while(m--)
    {
        int x, y;
        cin >> x >> y;
        UnionBySize(x, y);
    }

    // for(int i=1; i<=n; i++)
    // {
    //     cout << i << "->" << parent[i] << endl;
    // }

    vector <int> leaders;
    for(int i=1; i<=n; i++)
    {
        if(parent[i] == -1)
            leaders.push_back(i);
    }

    cout << leaders.size() -1 << endl;   //leaders 3 ta hole road hbe 2 ta
    for(int i=0; i<leaders.size()-1; i++)
    {
        cout << leaders[i] << " " << leaders[i+1] << endl;
    }
    return 0;
}