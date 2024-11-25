#include <bits/stdc++.h>
using namespace std;
char mapB[1001][1001];
bool vis[1001][1001];
int dis[1001][1001];
vector <pair<int,int>> d = {{0,1},{0,-1},{-1,0},{1,0}};
int n, m;
pair <int,int> parent[1001][1001];

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
    queue <pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while(!q.empty())
    {
        pair <int,int> par = q.front();
        q.pop();
        int parRow = par.first;
        int parCol = par.second;

        for(int i=0; i<4; i++)
        {
            int ci = parRow + d[i].first;
            int cj = parCol + d[i].second;

            if(valid(ci, cj) && !vis[ci][cj] && mapB[ci][cj] != '#')
            {
                vis[ci][cj] = true;
                dis[ci][cj] = dis[parRow][parCol] + 1;
                parent[ci][cj] = {parRow, parCol};
                q.push({ci, cj});
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    int si, sj, di, dj;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> mapB[i][j];

            if(mapB[i][j] == 'R')
            {
                si = i;
                sj = j; 
            }
            if(mapB[i][j] == 'D')
            {
                di = i;
                dj = j; 
            }
        }
    }
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));

    bfs(si, sj);

    if(vis[di][dj])
    {
        // cout << "YES" << endl;
        // cout << dis[di][dj] << endl;

        pair <int,int> p = {di,dj};
        vector <pair<int,int> > path;
        while(!(p.first == si && p.second == sj))
        {
            path.push_back(p);
            p = parent[p.first][p.second];
        }

        //reverse(path.begin(), path.end());
        for(int i=1; i<path.size(); i++)
        {
            //cout << path[i].first << " " << path[i].second << endl;

            int xi = path[i].first;
            int xj = path[i].second;

            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    mapB[xi][xj] = 'X';
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout << mapB[i][j];
            }
            cout << endl;
        }
    }   
    else
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout << mapB[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}