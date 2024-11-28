#include <bits/stdc++.h>
using namespace std;
class Edge
{
    public:
        int A, B , C;  
    Edge(int s, int d, int c)
    {
        this->A = s;
        this->B = d;
        this->C = c;
    }
};
const int N = 1e5+10;
int dis[N];

int main()
{
    int n, e;
    cin >> n >> e;
    vector <Edge> EdgeList; 

    //edge reading
    while(e--)
    {
        int s, d, c;
        cin >> s >> d >> c;
        EdgeList.push_back(Edge(s, d, c));
    }

    //distance array initializing
    for(int i=0; i<n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[0] = 0;

    //bellman-ford algorithm
    for(int i=1; i<n; i++)
    {
        for(Edge ed : EdgeList)
        {
            int s = ed.A;
            int d = ed.B;
            int c = ed.C;

            if(dis[s] < INT_MAX && dis[s]+c < dis[d])
            {
                dis[d] = dis[s] + c;
            }
        }
    }

    //Cycle checking
    bool cycle = false;
    for(Edge ed : EdgeList)
        {
            int s = ed.A;
            int d = ed.B;
            int c = ed.C;

            if(dis[s] < INT_MAX && dis[s]+c < dis[d])
            {
                cycle = true;
                break;
            }
        }

    //output printing
    if(cycle)
    {
        cout << "Cycle Found: No answer" << endl;
    }   
    else
    {
        for(int i=0; i<n; i++)
    {
        cout << i << "->" << dis[i] << endl;
    }
    }
   
    return 0;
}