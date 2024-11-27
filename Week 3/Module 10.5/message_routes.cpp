#include <bits/stdc++.h>
#define long long int ll
using namespace std;
const int N = 1e5+50;
vector <int> v[N];
bool vis[N];
int con[N];

void dfs(int src)
{
    vis[src] = true;
    for(int child : v[N])
    {
        
    }
}
int main()
{
    // induction makes time infinite finite.
    // Statement: The sum of time first n natural number is 
    // 0 is not a Natural Number.

    ll n, m;
    cin >> n >> m;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    for(int i=1; i<=n; i++)
    {
        con[i] = -1;
    }
    con[1] = 0;

    dfs(1);

    for(int child : v[N])
    {
        cout << child << endl;
    }

    return 0;
}