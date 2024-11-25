#include <bits/stdc++.h>
using namespace std;

char mat[50][50];
bool vis[50][50];
int dis[50][50];
int n;
vector <pair<int,int>> d = {{0,1},{0,-1},{1,0},{-1,0}};
bool valid(int ci, int cj)
{
    if(ci>=0 && ci<n && cj>=0 && cj<n)
        return true;
    else
        return false;
}
void bfs(int si, int sj)
{
    queue <pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while(!q.empty())
    {
        pair <int,int> par = q.front();
        q.pop();
        int pari = par.first;
        int parj = par.second;

        for(int i=0; i<4; i++)
        {
            int ci = pari + d[i].first;
            int cj = parj + d[i].second;

            if(valid(ci,cj) && !vis[ci][cj] && mat[ci][cj] != 'T')
            {
                q.push({ci,cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[pari][parj] + 1;
            } 
        }
    }
}
int main()
{

    while(cin >> n)
    {
        int si, sj;
        int di, dj;
        for(int i=0;i<5;i++)
        {
            for(int j=0; j<n; j++)
            {
                cin >> mat[i][j];
                if(mat[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
                if(mat[i][j] == 'E')
                {
                    di = i;
                    dj = j;
                }
            }
        }
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        bfs(si, sj);
        cout << dis[di][dj] << endl;
    }
    return 0;
}