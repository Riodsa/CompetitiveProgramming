#include<bits/stdc++.h>
using namespace std;

const int N = 5;
bool vis[N][N];
double land[N][N];
int n,m;
double ans = 200000000;
int x[] = {-1,-1,0,1,1,1,0,-1};
int y[] = {0,1,1,1,0,-1,-1,-1};

void solve(int cnt,double cost)
{
    if(cnt == n*m)
    {
        ans = min(ans,cost);
        return ;
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(vis[i][j]) continue;

            if(!vis[i][j])
            {
                vis[i][j] = true;
                for(int k=0;k<8;++k)
                {
                    int row = i+y[k];
                    int col = j+x[k];
                    if(row >= 1 && row <= m && col >= 1 && col <= n && !vis[row][col])
                    {
                        land[row][col] += land[i][j]*(0.10);
                    }
                }
            }
            solve(cnt+1,cost+land[i][j]);
            for(int k=0;k<8;++k)
            {
                int row = i+y[k];
                int col = j+x[k];
                if(row >= 1 && row <= m && col >= 1 && col <= n && !vis[row][col])
                {
                    land[row][col] -= land[i][j]*(0.10);
                }
            }
            vis[i][j] = false;
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin >> land[i][j];
        }
    }
    solve(0,0);
    printf("%.2lf",ans);
    return 0;
}
