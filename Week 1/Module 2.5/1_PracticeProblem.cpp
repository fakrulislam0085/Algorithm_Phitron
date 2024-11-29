#include <bits/stdc++.h>
using namespace std;
vector <int> v[1005];
bool visAr[1005];
int level[1005];
int parent[1005];
bool flag = false;  //global variable

void printShortestPath(int s, int d)
{
    queue<int> q;
    q.push(s);
    visAr[s] = true;
    level[s] = 0;
    
    
    while(!q.empty())
    {
        int par = q.front();
        q.pop();

        if(par == d)
        {
            flag = true;
        }
        for(int child : v[par])
        {
            if(visAr[child] == false)
            {
                q.push(child);
                visAr[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
        }
    }
    if(flag == false) cout << -1 << endl;
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
    int q;
    cin >> q;
    
    while(q--)
    {
        int s, d;
        cin >> s >> d;

        memset(visAr, false, sizeof(visAr));
        memset(level, -1, sizeof(level));
        memset(parent, -1, sizeof(parent));

        printShortestPath(s,d);

        int x = d;
        vector <int> path;
        while(x != -1)
        {
            path.push_back(x);
            x = parent[x];
        }
       
        if(flag != false)
        {
            cout << path.size() -1 << endl;
        }
    }
    return 0;
}
