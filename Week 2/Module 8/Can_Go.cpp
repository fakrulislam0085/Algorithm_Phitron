#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 10000;
vector<pair<int, int>> v[N];
int dis[N];

class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};
void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;

    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int node = parent.first;
        ll cost = parent.second;

        for (pair<int, int> child : v[node])
        {
            int childNode = child.first;
            ll childCost = child.second;
            if (cost + childCost < dis[childNode])
            {
                // path relax
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
}
int main()
{
    ll n, e;
    cin >> n >> e;
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        //v[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    int s;
    cin >> s;

    dijkstra(s);

    int tc;
    cin >> tc;
    while(tc--)
    {
        ll d, dw;
        cin >> d >> dw;
        
        if(d <= n)
        {
            if(dis[d] != INT_MAX && dis[d] <= dw)
            {
            cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        
        else 
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}