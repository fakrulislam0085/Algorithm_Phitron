#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;

    //make an adjlist
    vector <pair<int,int>> adjList[n];

    //input edge list and put them in adjList
    while(e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v,w});  //for directed only
    }

    //print output
    for(int i=0; i<n; i++)
    {
        cout << i << "->";
        for(pair<int,int> child : adjList[i])
        {
            cout << "{" << child.first << "," << child.second << "}" << " ";
        }
        cout << endl;
    }
    return 0;
}