#include <bits/stdc++.h>
using namespace std;
const int size = 1e5;
vector <int> v[size];
bool visAr[size];
int countNode = 0;   //for node counting in a component
vector <int> CN;   //for putting number of node in a component

void dfs(int src)
{
    visAr[src] = true;
    countNode++;

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
            if(component++)
            {
                CN.push_back(countNode);
                countNode = 0;
            }
        }
    }

    sort(CN.begin(), CN.end());
    for(int val : CN)
    {
        cout << val << " ";
    }
    return 0;
}