#include <bits/stdc++.h>
using namespace std;
int main()
{
    pair <string, int> p;
    p = make_pair("Fariha", 06);  //It is defined in #include <utility> header
    cout << p.first << " " << p.second << endl;
    
    pair <int, int> p2; 
    p2 = make_pair(6, 7); 
    cout << p2.first << " " << p2.second << endl; 
    
    return 0;
}
