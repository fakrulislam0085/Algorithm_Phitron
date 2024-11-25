#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5+10;

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

void dsu_Union_by_size(int p, int q)
{
    int leader1 = find(p);
    int leader2 = find(q);
    if(leader1 == leader2) return;

    else if(sz[leader1] > sz[leader2])
    {
        parent[leader2] = leader1;
        sz[leader1] += sz[leader2];
    }
    else
    {
        parent[leader1] = leader2;
        sz[leader2] += sz[leader1];
    }
}

class Edge {
    public:
        ll x, y, z;
    Edge(ll x, ll y, ll z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};
bool cmp(Edge a, Edge b)
{
    if(a.z <= b.z)
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
    int connectedEdges = 0;
    int removeEdges = 0;

    for(Edge ed : edgeList)
    {
        int leader1 = find(ed.x);
        int leader2 = find(ed.y);

        if(leader1 != leader2)
        {
            dsu_Union_by_size(ed.x, ed.y);
            totalCost += ed.z;
            connectedEdges++;
        }
        else
        {
            removeEdges++;
        }
    }

    if(connectedEdges == n-1)   //road 4 ta means edge 3 ta 
    {
        cout << removeEdges << " " << totalCost << endl;
    }
    else cout << "Not Possible" << endl;

    return 0;
}