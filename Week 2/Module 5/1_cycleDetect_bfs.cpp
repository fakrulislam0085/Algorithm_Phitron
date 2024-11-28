#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector <int> adj[N];
bool visAr[N];
int parentArray[N];
bool ans;

void bfs(int s)
{
    queue <int> q;
    q.push(s);
    visAr[s] = true;
    
    while(!q.empty())
    {
        int parent = q.front();
        q.pop();

        for(int child : adj[parent])
        {
            if(visAr[child] == true && parentArray[parent] != child)
            {
                ans = true;
            }
            if(!visAr[child])
            {
                visAr[child] = true;
                parentArray[child] = parent;
                q.push(child);
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
            bfs(i);
        }
    }

    if(ans)
        cout << "Cycle Found" << endl;
    else
        cout << "Cycle does not Found" << endl;

    
    return 0;
}