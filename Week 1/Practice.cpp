#include <bits/stdc++.h>
using namespace std;
vector <int> v[1005];
bool vis[1005];
int level[1005];
int main()
{
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));

    int src;
    cin >> src;

    bfs(src);
    return 0;

                      
}