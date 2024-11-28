#include <bits/stdc++.h>
using namespace std;
bool vis[100][100];
int des[100][100];
vector <pair<int,int>> d = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},{1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
int n, m;

bool valid(int x, int y)
{
    if (x<0 || x>=n || y<0 || y>=m)
        return false;
    return true;
}
void bfs(int si, int sj)
{
    queue <pair <int,int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    des[si][sj] = 0;

    while(!q.empty())
    {
        pair <int,int> par = q.front();
        q.pop();
        int a = par.first;
        int b = par.second;

        for(int i=0; i<8; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;

            if(valid(ci, cj) == true && vis[ci][cj] == false)
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                des[ci][cj] = des[a][b] + 1;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        int ki, kj;
        cin >> ki >> kj;
        int qi, qj;
        cin >> qi >> qj;

        memset(vis, false, sizeof(vis));
        memset(des, -1, sizeof(des));
        
        bfs(ki, kj);

        cout << des[qi][qj] << endl;

    }
    return 0;
}