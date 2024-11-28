#include <bits/stdc++.h>
using namespace std;
const int N = 100;
vector<pair<int,int>> adj[N];
int dis[N];

void dijkstra(int s)
{
    queue<pair<int, int>> q;
    q.push({s,0}); 
    dis[s] = 0;

    while(!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int parentnode = parent.first;
        int cost = parent.second;
        
        for(pair<int,int> child : adj[parentnode]) 
        {
            int childNode = child.first;
            int childcost = child.second;
            if(cost + childcost < dis[childNode])
            {
                //path relaxation
                dis[childNode] = cost + childcost;
                q.push({childNode, dis[childNode]});
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
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    for(int i=0; i<n; i++)
    {
        dis[i] = INT_MAX;
    }

    dijkstra(0);

    for(int i=0; i<n; i++)
    {
        cout << i << "->" << dis[i] << endl;
    }

    return 0;
}