#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
pii idx[8] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const int N = 2e3+1;
int n,m;
char b[N][N];
bool vis[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin >> b[i][j];
        }
    }
//    for(int i=1;i<=n;++i)
//    {
//        for(int j=1;j<=m;++j)
//        {
//            cout << b[i][j] << " ";
//        }
//        cout << '\n';
//    }
    int ans = 0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(b[i][j] == '1' && !vis[i][j])
            {
                queue<pii> q;
                q.push({i,j});
                ++ans;
                while(!q.empty())
                {
                    auto [x,y] = q.front();
                    q.pop();
                    for(int i=0;i<8;++i)
                    {
                        int nx = x+idx[i].first, ny = y+idx[i].second;
                        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
                        if(vis[nx][ny] || b[nx][ny] == '0') continue;
                        q.push({nx,ny});
                        vis[nx][ny] = true;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
