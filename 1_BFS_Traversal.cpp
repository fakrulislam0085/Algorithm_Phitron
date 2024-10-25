#include <bits/stdc++.h>
using namespace std;

vector <int> v[1005];  //maximum number of node will be the size
bool visAr[1005];  //boolean type visited array

void bfs(int src)
{
    queue <int> q;
    q.push(src);
    visAr[src] = true;

    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        cout << par << endl;

        for(int child : v[par])
        {
            if(visAr[child] == false)
            {
                q.push(child);
                visAr[child] = true;
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

    memset(visAr, false, sizeof(visAr));
    bfs(src);

    return 0;
}


//Time complexity of bfs: O(node number + edge number)  //O(v+e)
//Space complexity: O(node number)