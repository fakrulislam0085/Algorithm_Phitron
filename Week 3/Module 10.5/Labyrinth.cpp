#include <bits/stdc++.h>
using namespace std;
int n, m;
char mapBld[1001][1001];
bool vis[1001][1001];
vector <pair<int,int>> d = {{1,0}, {-1,0}, {0,-1}, {0,1}};

bool valid(int ci, int cj)
{
    if(ci<n && ci>=0 && cj<m && cj>=0 && mapBld[ci][cj] == '.' || 
    mapBld[ci][cj] == 'A' || mapBld[ci][cj] == 'B')
        return true;
    else
        return false;
}
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for(int i=0; i<4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if(valid(ci, cj) && !vis[ci][cj])
        {
            vis[ci][cj] = true;
            dfs(ci, cj);
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> mapBld[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    int srci, srcj, desi, desj;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(mapBld[i][j] == 'A')
            {
                srci = i;
                srcj = j;
            }
            if(mapBld[i][j] == 'B')
            {
                desi = i;
                desj = j;
            }
        }
    }
    
    dfs(srci, srcj);

    if(vis[desi][desj] == true)
    {
        cout << "YES" << endl;

    }
        
    else
        cout << "NO" << endl;
        

    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << mapBld[i][j] ;
        }
        cout << endl;
    }

    cout << srci << srcj << endl << desi << desj;
    return 0;
}