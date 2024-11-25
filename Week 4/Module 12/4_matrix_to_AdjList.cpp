#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int mat[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> mat[i][j];
        }
    }

    vector <pair<int,int>> adjList[n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(mat[i][j] > 0)
            {
                adjList[i].push_back({j, mat[i][j]}); //adjList a i index a j and cost push korbo
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        cout << i << "->";
        for(pair<int,int> child : adjList[i])
        {
            cout << "{" << child.first << "," << child.second << "}";
        }
        cout << endl;
    }


    return 0;
}