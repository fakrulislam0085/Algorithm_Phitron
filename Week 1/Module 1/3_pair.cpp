#include <bits/stdc++.h>
using namespace std;
class Pair
{
    public:
        int first, second;
    
    void make_pair(int a, int b)
    {
        first = a;
        second = b;
    }
};
int main()
{
    Pair p;
    //1st
    // p.first = 10;
    // p.second = 30;

   //2nd
    p.make_pair(10,20);

    cout << p.first << " " << p.second << endl;
    return 0;
}
