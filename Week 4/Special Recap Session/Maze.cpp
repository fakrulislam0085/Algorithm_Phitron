#include <bits/stdc++.h>
using namespace std;
int n, m;
char mat[1005][1005];
bool vis[1005][1005];
vector <pair<int,int>> v = {{-1,0},{1,0},{0,-1},{0,1}};
vector <int> cnt;

bool valid(int ci, int cj)
{
    if(ci>=0 && ci<n && cj>=0 && cj<m)
        return true;
    else
        return false;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;

    for(int i=0; i<4; i++)
    {
        int ci = si + v[i].first;
        int cj = sj + v[i].second;

        if(valid(ci,cj) && !vis[ci][cj] && mat[ci][cj] == '.')
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    cin >> n >>m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> mat[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(vis[i][j] == false && mat[i][j] == '.')
            {
                dfs(i, j);
                cnt.push_back(countDot);
                countDot = 0;
            }
        }
    }

    if(cnt.size() == 0) cout << -1 << endl;
    else
    {
        sort(cnt.begin(), cnt.end());
        cout << cnt.front() << endl;
        
    }
    


    return 0;