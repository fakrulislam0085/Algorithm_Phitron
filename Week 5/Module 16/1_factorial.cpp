#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    //base case for stopping the function
    if(n==0) return 1;

    int chotoFactorial = fact(n-1);
    return chotoFactorial * n;
}
int main()
{
    int n;
    cin >> n;
    
    int f = fact(n);

    cout << f << endl;

    return 0;
}