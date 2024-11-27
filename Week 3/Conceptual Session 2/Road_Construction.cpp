#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int parent[N];
int grpSz[N];
int cmponent, mx;

void dsuInitialize(int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i] = -1;
        grpSz[i] = 1;
    }
    cmponent = n;
    mx = INT_MIN;
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
        mx = max(mx, grpSz[ldr1]);
    }
    else
    {
        parent[ldr1] = ldr2;
        grpSz[ldr2] += grpSz[ldr1];
        mx = max(mx, grpSz[ldr2]);
    }
    cmponent--;
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

        cout << cmponent << " " << mx << endl;

    }
    return 0;
}