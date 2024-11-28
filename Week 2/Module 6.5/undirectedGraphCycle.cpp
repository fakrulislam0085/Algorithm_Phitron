#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> adj[N];
bool visAr[N];
int parentAr[N];
bool ans;

void bfs(int src)
{
    queue <int> q;
    q.push(src);
    visAr[src] = true;

    while(!q.empty())
    {
        int parent = q.front();
        q.pop();

        for(int child : adj[parent])
        {
            if(visAr[child] == true && parentAr[parent] != child)
            {
                ans = true;
            }
            if(!visAr[child])
            {
                visAr[child] = true;
                parentAr[child] = parent;
                q.push(child);
            }
        }
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(visAr, false, sizeof(visAr));
    memset(parentAr, -1, sizeof(parentAr));
    ans = false;
    int count = 0;

    for(int i=0; i<v; i++)
    {
        if(!visAr[i])
        {
            bfs(i);
        }
    }

    if(ans) count++;
    cout << count << endl;

    return 0;
}