#include <bits/stdc++.h>
using namespace std;

int n, m;
char building[1005][1005];
bool vis[1005][1005];
int cntRoom = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector <int> RmNmbr;

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
    cntRoom++;
    
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

    int cntAprt = 0;
    memset(vis, false, sizeof(vis));
    
    for(int i =0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(building[i][j] == '.' && vis[i][j] == false)
            {
                dfs(i, j);
                cntAprt++;
                if(cntAprt++)
                {
                    RmNmbr.push_back(cntRoom);
                    cntRoom = 0;
                }
            }
        }
    }
    
    if(RmNmbr.size() == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        sort(RmNmbr.begin(), RmNmbr.end());
        for(int nmbr: RmNmbr)
        {
            cout << nmbr << " ";
        }
    }
    
    return 0;
}