#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector <int> ar[n];

    while(e--)
    {
        int a,b;
        cin >> a >> b;

        ar[a].push_back(b);
        ar[b].push_back(a);  //undirected grap
    }

    //connection
    // vector <int> v;
    // for(int x : ar[3])
    // {
    //     cout << x << " ";
    // }

    for(int i=0; i<ar[1].size(); i++)
    {
        cout << ar[1][i] << " ";
    }
    return 0;
}