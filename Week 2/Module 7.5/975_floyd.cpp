//basecamp website

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    cin >> n;
    ll adj[n][n];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> adj[i][j];
            if(adj[i][j] == -1)
            {
                adj[i][j] = INT_MAX;
            }
        }
    }

    //floyd warshall algorithm
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            { 
                if(adj[i][k] + adj[k][j] < adj[i][j])
                {
                        adj[i][j] = adj[i][k] + adj[k][j];
                }
            }   
        }
    }


    //output the shortest path
    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<n; j++)
    //     {
    //         if(adj[i][j] == INT_MAX)
    //             cout << "inf" << " ";
    //         else
    //             cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //output the maximum distance
    ll max = INT_MIN;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(adj[i][j] !=INT_MAX)
            {
                if(adj[i][j] > max)
                {
                    max = adj[i][j];
                }
            }
        }
    }

    cout << max << endl;
    return 0;
}