#include <bits/stdc++.h>
using namespace std;
vector <int> v[1005];
bool visitedAr[1005]; //created a visited array to track visiting
int level[1005];  //level Tracking
int parent[1005]; //Created a parent array

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
                parent[child] = par;
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
        v[a].push_back(a);
    }
    int src, des;
    cin >> src >> des;

    memset(visitedAr, false, sizeof(visitedAr));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    bfs(src);

    int x = des;
    vector <int> path;
    while( x != -1)
    {
        path.push_back(x);
        x = parent[x];
    }

    reverse (path.begin(), path.end());
    for(int val : path)
    {
        cout << val << " ";
    }
    return 0;
}