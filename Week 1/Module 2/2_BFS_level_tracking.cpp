#include <bits/stdc++.h>
using namespace std;
vector <int> v[1005];
bool visitedAr[1005];
int level[1005];  //level Tracking

void bfs(int src)
{
    queue <int> q;
    q.push(src);
    visitedAr[src] = true;
    level[src] = 0;

    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        // cout << par << endl;

        for(int child : v[par])
        {
            if(visitedAr[child] == false)
            {
                q.push(child);
                visitedAr[child] = true;
                level[child] = level[par] + 1;
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
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src;
    cin >> src;

    memset(visitedAr, false, sizeof(visitedAr));
    memset(level, -1, sizeof(level));

    bfs(src);

    for(int i=0; i<n; i++)
    {
        cout << i << ": " << level[i] << endl;
    }
    return 0;
}