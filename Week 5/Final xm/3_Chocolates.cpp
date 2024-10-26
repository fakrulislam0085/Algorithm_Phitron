#include <bits/stdc++.h>
using namespace std;

bool chocolate(int n, int choc[])
{
    //base case
    if(n<0)
        return false;
    
    int opt1 = chocolate(n-1, choc) + choc[n];
    int opt2 = chocolate(n-1, choc);
    
}


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int choc[n];
        for(int i=0; i<n; i++)
        {
            cin >> choc[i];
        }

        bool flag = chocolate(n-1, choc);

        if(flag)    cout << "YES\n";
        else    cout << "NO\n";
    }
    return 0;
}