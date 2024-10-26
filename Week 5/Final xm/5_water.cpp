#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int H[n];
        for(int i=0; i<n; i++)
        {
            cin >> H[i];
        }

        int sz = sizeof(H);
        sort(H, sz)  //sorting in ascending order

        for(int i=0; i<n; i++)
        {
            cout << H[i] << " ";
        }
        cout << endl;
    }
    return 0;
}