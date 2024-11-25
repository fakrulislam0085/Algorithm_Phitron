#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int parent[N];
int group_size[N];

void dsu_initialize(int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i] = -1;
        group_size[i] = 1;
    }
}

int dsu_find(int node)
{
    if(parent[node] == -1) return node;
    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}

int dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    if(group_size[leaderA] > group_size[leaderB])
    {
        parent[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}
int main()
{
    int n;
    cin >> n;
    dsu_initialize(n);
    vector <pair<int, int> > delEdge;
    vector <pair<int, int> > createEdge;

    for(int i=1; i<n; i++)
    {
        int a, b;
        cin >> a >> b;

        int leadera = dsu_find(a);
        int leaderb = dsu_find(b);

        if(leadera == leaderb)
        {
            delEdge.push_back({a,b});
        }
        else
        {
            dsu_union_by_size(a, b);
        }
    }

    cout << delEdge.size() << endl;

    for(int i=2; i<=n; i++)
    {
        int leaderA = dsu_find(1);
        int leaderB = dsu_find(i);

        if(leaderA != leaderB)
        {
            createEdge.push_back({1,i});
            dsu_union_by_size(1,i);
        }
    }

    for(int i=0; i<delEdge.size(); i++)
    {
        cout << delEdge[i].first << " " << delEdge[i].second << " "
        << createEdge[i].first << " " << createEdge[i].second << endl;
    }
    return 0;
}