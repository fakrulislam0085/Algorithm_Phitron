#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;  //10 to the power 5 = 1e5  
vector <int> v[N];
bool visAr[N];

void dfs(int src)
{
    cout << src << endl;
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
    int c = 0;
    for(int i=0; i<n; i++)
    {
        if(visAr[i] == false)
        {
            dfs(i);
            c++;
        }
    }
    cout << "component - " << c << endl;
    
    return 0;  
}