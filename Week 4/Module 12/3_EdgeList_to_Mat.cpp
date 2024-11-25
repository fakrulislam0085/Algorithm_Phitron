#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int mat[n][n];

    //declare a matrix with certain value
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j)    mat[i][j] = 0;
            else    mat[i][j] = -1;
        }
    }

    //edgelist input and assigning their value in matrix cell
    while(e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        mat[u][v] = w;
        mat[v][u] = w;  //for undirected graph
    }

    //print the result
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}