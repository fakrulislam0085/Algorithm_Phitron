#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class Edge
{
public:
    ll u, v, c;
    Edge(ll u, ll v, ll c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
const long long int INF = 1e18 + 5;
ll dis[10001];
int main()
{
    ll n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    
    int src;
    cin >> src;
    dis[src] = 0;

    int tC;
    cin >> tC;
    while(tC--)
    {
        int d;
        cin >> d;

        for (int i = 1; i <= n - 1; i++)
        {
            for (Edge ed : EdgeList)
            {
                ll u, v, c;
                u = ed.u;
                v = ed.v;
                c = ed.c;
                if (dis[u] < INF && dis[u] + c < dis[v])
                {
                    dis[v] = dis[u] + c;
                }
            }
        }

        bool cycle = false;
        for (Edge ed : EdgeList)
        {
            ll u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < INF && dis[u] + c < dis[v])
            {
                cycle = true;
                break;
            }
        }

        if (cycle)
        {
            cout << "Negative Cycle Detected" << endl;
            break;
        }
        else
        {
            if(d<=n && src<=n)
            {
                if(dis[d] != INF)
                {
                    cout << dis[d] << endl;
                }
                else
                {
                    cout << "Not Possible" << endl;
                }
            }
        
            else 
            {
                cout << "NO" << endl;
            }
        }

    }
    
    return 0;
}