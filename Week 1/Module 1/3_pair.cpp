#include <bits/stdc++.h>
using namespace std;
class myPair
{
    public:
        int f, s;
    
    void make_pair(int a, int b)
    {
        f = a;
        s = b;
    }
};
int main()
{
    myPair p;
    //1. initialize here
    // p.f = 10;
    // p.s = 30;

    //2. or call our function
    p.make_pair(10,20);
    cout << p.f << " " << p.s << endl;
    
    return 0;
}
