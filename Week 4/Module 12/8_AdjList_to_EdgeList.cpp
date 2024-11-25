#include <bits/stdc++.h>
using namespace std;
class Edge{
    public:
        int u, v, w;
    Edge(int u,int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main()
{
    int n, e;
    cin >> n >> e;

    //take input an adjacency list
    vector <pair<int,int>> adjList[n];
    while(e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adjList[a].push_back({b,c});  //directed graph
    }  

    //make an EdgeList
    vector <Edge> edgeList;
    for(int i=0; i<n; i++)
    {
        for(pair<int,int> child : adjList[i])
        {
            int childNode = child.first;
            int childCost = child.second;
            edgeList.push_back(Edge(i, childNode, childCost));
        }
    }

    for(Edge edge : edgeList)
    {
        cout << edge.u << " " << edge.v << " " << edge.w << endl;
    }
    return 0;
}