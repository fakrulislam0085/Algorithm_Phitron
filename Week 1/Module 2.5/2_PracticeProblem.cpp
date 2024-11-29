#include <bits/stdc++.h>
using namespace std;
vector <int> v[1001];
bool visAr[1001];
int level[1001];
vector <int> print;

void levelOrderPrint(int s, int l)
{
    queue <int> q;
    q.push(s);
    visAr[s] = true;
    level[s] = 0;

    while(!q.empty())
    {
        int par = q.front();
        q.pop();

        if(level[par] == l)
        {
            print.push_back(par);
        }

        for(int child : v[par])
        {
            if(visAr[child] == false)
            {
                q.push(child);
                visAr[child] = true;
                level[child] = level[par] + 1;
            }
        }
    }
}
int main()
{
    int n,e;
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int s = 0;
    int l;
    cin >> l;

    memset(visAr, false, sizeof(visAr));
    memset(level, -1, sizeof(level));

    levelOrderPrint(s,l);

    for(int i=print.size()-1; i>=0; i--)
    {
        cout << print[i] << " ";
    }

    return 0;
}