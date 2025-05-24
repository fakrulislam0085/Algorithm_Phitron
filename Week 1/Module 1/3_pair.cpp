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
    //1st
    // p.first = 10;
    // p.second = 30;

   //or call our function
    p.make_pair(10,20);
    cout << p.f << " " << p.s << endl;


    /*STL pair syntax: pair<datatype, datatype> variable; 
    After declaring our pair we can print the value as variable.first and variable.second 
    we can initialize pair in two ways */

    pair <int, string> p2(2, "graph");  //1st
    pair <string, int> p3;  //2nd
    p3 = {"tree", 5}; 
    cout << p2.first << " " << p2.second << endl << p3.first << " " << p3.second << endl; 

    return 0;
}
