#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5+10;
int leader[N];
int group_size[N];

void dsu_initialize(int n)
{
    for(int i=1; i<=n; i++)
    {
        leader[i] = -1;
        group_size[i] = 1;
    }
}
int find(int node)
{
    if(leader[node] == -1)
    {
        return node;
    }
    int l = find(leader[node]);
    leader[node] = l;
    return l;
}
void Union(int x, int y)
{
    int leaderA = find(x);
    int leaderB = find(y);

    if(group_size[leaderA] > group_size[leaderB])
    {
        leader[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        leader[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}
class Edge {
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
    int n, m;
    cin >> n >> m;

    dsu_initialize(n);
    vector<Edge> EdgeList;

    for(int i=0; i<m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;

        EdgeList.push_back(Edge(u, v, w));
    }

    sort(EdgeList.begin(), EdgeList.end(), cmp);

    ll totalcost = 0;
    int edge_lagbe = 0;

    for(Edge ed : EdgeList)
    {
        int u_er_leader = find(ed.u);
        int v_er_leader = find(ed.v);

        if(u_er_leader != v_er_leader)
        {
            Union(ed.u, ed.v);
            totalcost += ed.w;
            edge_lagbe++;
        }
    }

    int leader_hote_hbe = find(1);
    bool shobai_connected = true;

    for(int i=1; i<=n; i++)
    {
        if(find(i) != leader_hote_hbe)
        {
            shobai_connected = false;
        }
    }

    if(shobai_connected)
    {
        cout << edge_lagbe << " ";
        cout << totalcost << endl;
    }    
    else    cout << "IMpossible" << endl;
    
    
    return 0;
}