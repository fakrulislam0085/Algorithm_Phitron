#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
vector <int> v[N];
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
        int x;
        cin >> x;
        vector <int> v2;

        for(int val : v[x])
        {
            v2.push_back(val);
        }

        sort(v2.begin(), v2.end());
        if(!v2.size())
        {
            cout << -1 << endl;
        }
        else
        {
            for(int i = v2.size()-1; i>=0; i--)
            {
                cout << v2[i] << " ";
            }
            cout<< endl;
        }
    }
    return 0;
}