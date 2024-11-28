#include <bits/stdc++.h>
using namespace std;
class Edge
{
    public:
        int s, d , c;  //s = source, d = destination, c = cost
    Edge(int s, int d, int c)
    {
        this->s = s;
        this->d = d;
        this->c = c;
    }
};
const int N = 1e5+10;
int dis[N];

int main()
{
    int n, e;
    cin >> n >> e;
    vector <Edge> edgeList;

    while(e--)
    {
        int s, d, c;
        cin >> s >> d >> c;
        edgeList.push_back(Edge(s, d, c));
    }
    for(int i=0; i<n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[0] = 0;

    for(int i=1; i<n; i++)
    {
        for(Edge ed : edgeList)
        {
            int s = ed.s;
            int d = ed.d;
            int c = ed.c;

            if(dis[s] < INT_MAX && dis[s]+c < dis[d])
            {
                dis[d] = dis[s] + c;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        cout << i << "->" << dis[i] << endl;
    }
    return 0;
}