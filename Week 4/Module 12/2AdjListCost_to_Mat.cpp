#include <bits/stdc++.h>
using namespace std;
void convert(int n, vector<pair<int,int>> adjList[])
{
    int mat[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j)
                mat[i][j] = 0;
            else
                mat[i][j] = -1;
        }
    }
    //now convert the list to matrix
    for(int i=0; i<n; i++)
    {
        for(pair<int,int> child : adjList[i])
        {
            int childNode = child.first;
            int childCost = child.second;

            mat[i][childNode] = childCost;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector <pair<int,int>> adjList[n];
    while(e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v,w});  //directed weighted grap
    }

    convert(n, adjList);
    return 0;
}