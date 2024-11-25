#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+20;
vector <int> adjList[N];
bool vis[N];
int dist[N];

void bfs(int src)
{
    queue <int> q;
    q.push(src);
    vis[src] = true;
    dist[src] = 0;

    while(!q.empty())
    {
        int par = q.front();
        q.pop();

        for(int child : adjList[par])
        {
            if(!vis[child])
            {
                vis[child] = true;
                dist[child] = dist[par] + 1;
                q.push(child);
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
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b); 
        adjList[b].push_back(a); //undirected
    }
    int x, y, k;
    cin >> x >> y >> k;
    memset(vis, false, sizeof(vis));
    memset(dist, -1, sizeof(dist));

    bfs(x);

    cout << dist[y];
    
    if(dist[y] != -1 && dist[y] <= k*2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}