#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll input;

bool recur(ll n)
{
    //base case
    //if val > product, the program must stop
    if(n > input)
        return false;
    if(n == input)
        return true;
    
    return recur(n*10) || recur(n*20);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> input;
        bool flag = recur(1);   

        if(flag)    
            cout << "YES\n";
        else   
            cout << "NO\n";
    }
    return 0;
}