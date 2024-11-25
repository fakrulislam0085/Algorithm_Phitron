#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+10;
bool vis[N]
int parent[N];
// int dx[4] = {-1,0,1,0};   // row er move
// int dy[4] = {0,1,0,-1};   //col er move

int n, m;
char grap[N][N];

bool valid(int ci, int cj)
{
    if(ci>=0 && ci<n && cj>=0 && cj<m)
    {
        return true;
    }
    else
        return false;
}

void bfs(int si, int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;

    while(!q.empty())
    {
        pair <int,int> node = q.front();
        q.pop();

        int ni = node.first;
        int nj = node.second;

        for(int i=0; i<4; i++)
        {
            int ci = ni + dx[i];
            int cj = nj + dy[i];

            if(valid(ci, cj) && !vis[ci][cj])
            {
                vis[ci][cj] = true;
                q.push({ci,cj});
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    memset(vis, false, sizeof(vis));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> graph[i][j];
        }
    }

    
    return 0;
}