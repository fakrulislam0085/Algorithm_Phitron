#include <bits/stdc++.h>
using namespace std;
class edge
{
    public:
        int a, b, c;
    edge(int s, int d, int c)
    {
        this->a = s;
        this->b = d;
        this->c = c;
    }
};
const int N = 1e5+10;
int dis[N];

int main()
{
    int n, m;
    cin >> n >> m;
    vector <edge> EdgeList;
    while(m--)
    {
        int s, d, c;
        cin >> s >> d >> c;
        EdgeList.push_back(edge(s,d,c));
    }
    for(int i=1; i<=n; i++)
    {
        dis[i] = 30000;  //when there is no distance(prosno onusare INT_MAX use na kore ata korchi)
    }
    dis[1] = 0;

    for(int i=1; i<n; i++)
    {
        for(edge ed : EdgeList)
        {
            int s, d, c;
            s = ed.a;
            d = ed.b;
            c = ed.c;

            if(dis[s] < 30000 && dis[s]+c < dis[d])
            {
                dis[d] = dis[s] + c;
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        cout << dis[i] << " ";
    }

    return 0;
}