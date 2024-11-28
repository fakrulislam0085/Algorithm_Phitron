#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector <int> adj[N];
bool visArr[N];
bool pathVisArr[N];
bool ans;

void dfs(int parent)
{
    visArr[parent] = true;
    pathVisArr[parent] = true;

    for(int child : adj[parent])
    {
        if(visArr[child])
        {
            ans = true;
        }
        if(!visArr[child])
        {
            visArr[child] = true;  //ay dui line na likhleo result akoi asbe
            pathVisArr[child] = true;
            dfs(child);
        }
    }
    pathVisArr[parent] = false;
}
int main()
{
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);  //directed graph
    }
    memset(visArr, false, sizeof(visArr));
    memset(pathVisArr, false, sizeof(pathVisArr));
    ans = false;

    for(int i=0; i<n; i++)
    {
        if(!visArr[i])
        {
            dfs(i);
        }
    }

    if(ans) cout << "YES, cycle";
    else    cout << "NO, not cycle";
    return 0;
}