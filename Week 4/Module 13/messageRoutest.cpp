#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector <int> adj[N];
bool vis[N];
int dis[N];
int parent[N];

void bfs(int src)
{
    queue <int> q;
    q.push(src);
    vis[src] = true;
    dis[src] = 0;

    while(!q.empty())
    {
        int par = q.front();
        q.pop();

        for(int child : adj[par])
        {
            if(!vis[child])
            {
                dis[child] = dis[par] + 1;
                vis[child] = true;
                parent[child] = par;
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
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    memset(parent, -1, sizeof(parent));

    bfs(1);

    if(dis[n] == -1)
        cout << "IMPOSSIBLE" << endl;
    else
    {
        cout << dis[n]+1 << endl;
        int x = n;
        vector<int> path;
        while(x != -1)
        {
            path.push_back(x);
            x = parent[x];
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