#include <bits/stdc++.h>
using namespace std;
vector <int> v[1005];
bool visitedAr[1005]; //created a visited array to track visiting
vector <int> v2;

void bfs(int src)
{
    queue <int> q;
    q.push(src);
    v2.push_back(src);
    visitedAr[src] = true;
    
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        
        for(int child : v[par])
        {
            if(visitedAr[child] == false)
            {
                q.push(child);
                v2.push_back(child);
                visitedAr[child] = true;
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
    
    bfs(src);
    cout << v2.size() << endl;
   
    return 0;
}