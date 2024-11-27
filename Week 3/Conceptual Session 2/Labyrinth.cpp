#include <bits/stdc++.h>
using namespace std;
char mapB[1001][1001];
bool vis[1001][1001];
int dis[1001][1001];
vector <pair<int,int>> d = {{1,0},{-1,0},{0,1},{0,-1}};
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

            if(mapB[i][j] == 'A')
            {
                si = i;
                sj = j; 
            }
            if(mapB[i][j] == 'B')
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
        cout << "YES" << endl;
        cout << dis[di][dj] << endl;

        pair <int,int> p = {di,dj};
        vector <pair<int,int> > path;
        while(!(p.first == si && p.second == sj))
        {
            path.push_back(p);
            p = parent[p.first][p.second];
        }
        path.push_back({si,sj});

        // for(int i=0; i<path.size(); i++)
        // {
        //     cout << path[i].first << " " << path[i].second << endl;
        // }

        //soja path pawar jonno
        reverse(path.begin(), path.end());
        string ans = "";

        for(int i=0; i<path.size()-1; i++)
        {
            if(path[i].first == path[i+1].first)
            {
                //0 and 1 index a thaka pair ar first value/row jody change na hoy, 
                //tar mane movement hoyeche left/right a.
                //otherwise, movement up/down a
                
                //ekhn check korbo pair ar second value/colum bereche naki komeche
                if(path[i].second == path[i+1].second + 1)
                {
                    ans += "L";
                }
                else
                {
                    ans +="R";
                }
            }
            else
            {
                //movement up/ down a.
                if(path[i].first == path[i+1].first + 1)
                {
                    ans += "U";
                }
                else
                {
                    ans += "D";
                }
            }
        }
        cout << ans << endl;
    }   
    else    cout << "NO" << endl;

    return 0;
}