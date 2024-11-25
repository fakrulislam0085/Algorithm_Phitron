#include <bits/stdc++.h>
using namespace std;
const int N = 105;
vector <int> adj[N];
int dis_frm_src[N];
int dis_frm_des[N];
bool vis[N];

void bfs(int s, int track)
{
    queue <int> q;
    q.push(s);
    if(track == 1)
    {
        dis_frm_src[s] = 0;
    }
    else
    {
        dis_frm_des[s] = 0;
    }
    vis[s] = true;

    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        for(int child : adj[par])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                if(track == 1)
                {
                    dis_frm_src[child] = dis_frm_src[par] +1;
                }
                else
                {
                    dis_frm_des[child] = dis_frm_des[par] + 1;
                }
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    int cs = 1;
    while(t--)
    {
        int n, e;
        cin >> n >> e;
        while(e--)
        {
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int s, d;
        cin >> s >> d;
        for(int i=0; i<n; i++)
        {
            vis[i] = false;
            dis_frm_src[i] = -1;
        }
        bfs(s, 1);
        for(int i=0; i<n; i++)
        {
            vis[i] = false;
            dis_frm_des[i] = -1;
        }
        bfs(d, 2);

        int ans = INT_MIN;
        for(int i=0; i<n; i++)
        {
            int val = dis_frm_src[i] + dis_frm_des[i];
            ans = max(ans, val);
        }
        cout << "Case" << cs++ << ": " << ans << endl;
        for(int i=0; i<n; i++)
        {
            adj[i].clear();
        }

    }
    return 0;
}