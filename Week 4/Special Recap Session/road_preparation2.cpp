#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5+5;
int parent[N];
int sz[N];

void dsu_initialize(int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i] = -1;
        sz[i] = 1;
    }
}

int dsu_find(int node)
{
    if(parent[node] == -1)
        return node;
    else
    {
        int leader = dsu_find(parent[node]);
        parent[node] = leader;
        return leader;
    }
}

void dsu_Union(int p, int q)
{
    int leaderP = dsu_find(p);
    int leaderQ = dsu_find(q);

    if(sz[leaderP] > sz[leaderQ])
    {
        parent[leaderQ] = leaderP;
        sz[leaderP] += sz[leaderQ];
    }
    else
    {
        parent[leaderP] = leaderQ;
        sz[leaderQ] += sz[leaderP];
    }
}

class Edge
{
    public:
        ll u, v, w;
    Edge(ll u, ll v, ll w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool cmp(Edge a, Edge b)
{
    if(a.w < b.w)
        return true;
    else
        return false;
}
int main()
{
    int n, e;
    cin >> n >> e;

    dsu_initialize(n);
    vector <Edge> edgeList;
    while(e--)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u,v,w));
    }

    sort(edgeList.begin(), edgeList.end(), cmp);
    ll totalCost = 0;
    int component = n;

    for(Edge ed : edgeList)
    {
        int leader1 = dsu_find(ed.u);
        int leader2 = dsu_find(ed.v);

        if(leader1 != leader2)
        {
            dsu_Union(ed.u, ed.v);
            totalCost += ed.w;
            component--;
        }
    }

    if(component == 1)
    {
        cout << totalCost << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
    
    return 0;
}