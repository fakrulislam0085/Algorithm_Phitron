#include <bits/stdc++.h>
using namespace std;
const int size = 1e5;
vector <int> v[size];
bool visAr[size];

void dfs(int src)
{
    visAr[src] = true;
    for(int child : v[src])
    {
        if(visAr[child] == false)
        {
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
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(visAr, false, sizeof(visAr));
    int component = 0;

    for(int i=0; i<n; i++)
    {
        if(visAr[i] == false)
        {
            dfs(i);
            component++;
        }
    }

    cout << component << endl;
    return 0;
}