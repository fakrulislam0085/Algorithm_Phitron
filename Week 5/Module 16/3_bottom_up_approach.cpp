#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    a[0] = 0;  //the first value of fibonacci series is 0
    a[1] = 1;  //the second value of fibonnaci series is 1


    //O(n) complexity 
    //bottom-up technique
    for(int i=2; i<=n; i++)
    {
        a[i] = a[i-1] + a[i-2];   //index 2 will be the sum of indo-1, ind-0
    }

    cout << a[n] << endl;
    return 0;
}