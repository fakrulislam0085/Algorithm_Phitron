#include <bits/stdc++.h>
using namespace std;

vector <int> v[1005];  //maximum number of node will be the size
bool visAr[1005];  //boolean type visited array

void bfs(int src, int destination)
{
    queue <pair <int, int>> q;
    q.push({src, 0});
    visAr[src] = true;
    bool flag = false;

    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        int par = p.first;
        int level = p.second;

        if(par == destination)
        {
            cout << level << endl;
            flag = true;
        }
        for(int child : v[par])
        {
            if(visAr[child] == false)
            {
                q.push({child, level+1});
                visAr[child] = true;
            }
        }
    }
    if(flag == false)
    {
        cout << -1 << endl;
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

    memset(visAr, false, sizeof(visAr));
    bfs(src, 4);

    return 0;
}