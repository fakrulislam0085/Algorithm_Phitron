#include <bits/stdc++.h>
#define long long int ll
using namespace std;
const int N = 1e5+5;
vector <int> adj[N];
// vector <int> connect[1005];
bool vis[N];
int countNode = 0;

void dfs(int src)
{
    vis[src] = true;
    
   // connect.push_back(src);

    for(int child : adj[src])
    {
        if(!vis[child])
        {
            countNode++;
            dfs(child);
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
    

    int component = 0;
    for(int i=1; i<n+1; i++)
    {
        dfs(1);
        component++;
        if(component++)
        {
            cout << countNode << endl;
            // for(int i=1; i<countNode+1; i++)
            // {
            //     cout << connect[i] << " ";
            // }
            countNode = 0;
            
        }
    }

    return 0;
}