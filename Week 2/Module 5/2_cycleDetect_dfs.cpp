#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector <int> adj[N];
bool visAr[N];
int parentArray[N];
bool ans;

void dfs(int parent)
{
    visAr[parent] = true;
    for(int child : adj[parent])
    {
        if(visAr[child] == true && child != parentArray[parent])
        {
            ans = true;
        }
        if(visAr[child] == false)
        {
            parentArray[child] = parent;
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

    memset(visAr, false, sizeof(visAr));
    memset(parentArray, -1, sizeof(parentArray));
    ans = false;

    for(int i=0; i<n; i++)
    {
        if(!visAr[i])
        {
            dfs(i);
        }
    } 

    if(ans)
        cout << "Cycle detected" << endl;
    else    
        cout << "Cycle Not Detected" << endl;
    return 0;
}