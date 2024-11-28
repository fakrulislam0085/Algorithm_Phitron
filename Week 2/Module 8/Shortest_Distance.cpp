#include <bits/stdc++.h>
#define ll long long int
const long long int INF = 1e18;
using namespace std;

int main()
{
    ll n, e;
    cin >> n >> e;

    //create a matrix and putting it's cell value = highest number(here, INF)
    ll adj[n+1][n+1];
    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<n+1; j++)
        {
            adj[i][j] = INF;
            if(i == j)
            {
                adj[i][j] = 0;
            }
        }
    }

    //input the cost of each cell
    while(e--)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a][b] = min(adj[a][b], w);
    }
    //now time to make the least possible cost for each cell
    //floyd warshall algorithm
    for(int k=1; k<n+1; k++)
    {
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<n+1; j++)
            {
                if(adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    //taking q queries as input
    int q;
    cin >> q;
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        if(adj[x][y] == INF)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << adj[x][y] << endl;
        }
    }
    return 0;
}