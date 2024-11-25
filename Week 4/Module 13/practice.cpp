#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int dis[N];
int par[N];
vector <pair<int,int>> v[N];

class cmp
{
    public:
        bool operator()(pair<int,int> a, pair<int,int> b)
        {
            return a.second > b.second;
        }
};
void dijkstra(int src)
{
    priority_queue <pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;

    while(!pq.empty())
    {
        pair<int,int> parent = pq.top();
        pq.pop();

        int parentNode = parent.first;
        int parentCost = parent.second;

        for(pair<int,int> child : v[parentNode])
        {
            int childNode = child.first;
            int childCost = child.second;

            if(parentCost + childCost < dis[childNode])
            {
                dis[childNode] = parentCost + childCost;
                pq.push({childNode, dis[childNode]});
                par[childNode] = parentNode;
            }
        }
    }


}
int main()
{
    int n, e;
    cin >> n >> e;
    
    while(e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b,w});
        v[b].push_back({a, w});
    }
    for(int i=1; i<=n; i++)
    {
        dis[i] = INT_MAX;
        par[i] = -1;
    }

    dijkstra(1);

    if(dis[n] == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        int x = n;
        vector <int> path;
        while(x!=-1)
        {
            path.push_back(x);
            x = par[x];
        }
        reverse(path.begin(), path.end());
        for(int val : path)
        {
            cout << val << " ";
        }
        cout << endl;
    }



    return 0;
}