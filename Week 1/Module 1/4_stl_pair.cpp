#include <bits/stdc++.h>
using namespace std;
int main()
{
    /*STL pair syntax: pair<datatype, datatype> variable; 
    After declaring our pair we can print the value as variable.first and variable.second 
     */
    pair <string, int> p;
    p = make_pair("Fariha", 06);  //It is defined in #include <utility> header
    cout << p.first << " " << p.second << endl;

    pair <int, int> p2; 
    p2 = make_pair(6, 7); 
    cout << p2.first << " " << p2.second << endl; 

    //withour using make_pair() 
    pair <int, string> p2(2, "graph");  //1st way
    pair <string, int> p3;  //2nd way
    p3 = {"tree", 5}; 
    cout << p2.first << " " << p2.second << endl << p3.first << " " << p3.second << endl; 
    
    return 0;
}
