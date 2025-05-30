#include <bits/stdc++.h>
using namespace std;

int n, m;
char building[1005][1005];
bool vis[1005][1005];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};


bool valid(int x, int y)
{
    if(x<0 || x>=n || y<0 || y>=m || building[x][y] != '.')
    {
        return false;
    }
    else
        return true;
}

void dfs(int si, int sj)
{
    vis[si][sj] = true;
    
    for(int i=0; i<4; i++)
    {
        int ci = si + dx[i];
        int cj = sj + dy[i];
        
        if(valid(ci, cj) && vis[ci][cj] == false)
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    // Write your code here
    cin >> n >>m;
    for(int i =0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> building[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    int src_r, src_c;
    cin >> src_r >> src_c;
    int des_r, des_c;
    cin >> des_r >> des_c;


    dfs(src_r, src_c);

    if(vis[des_r][des_c])
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    
    
    return 0;
}