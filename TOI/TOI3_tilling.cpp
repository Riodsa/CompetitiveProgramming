#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
const int N = 18;
int board[N][N];
bool vis[N][N];
int si = 0;
int ans = 0;
int n;

pii idx[4] = {{1,0},{-1,0},{0,1},{0,-1}};
int cntx,cnty;
void bfs(int r,int c,int num)
{
//    cout << "now at " << r << " " << c << '\n';
    vis[r][c] = true;
    for(int i=0;i<4;++i)
    {
        int r1 = r+idx[i].first;
        int c1 = c+idx[i].second;
        if(r1 < 1 || r1 > n || c1 < 1 || c1 > n) continue;
        if(board[r1][c1] == num && !vis[r1][c1])
        {
            if(i == 0 || i == 1) ++cnty;
            else if(i == 2 || i == 3) ++cntx;
            ++si;
            bfs(r1,c1,num);
        }
    }
}

int main()
{
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin >> board[i][j];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(board[i][j] != 0 && !vis[i][j])
            {
//                cout << i << " " << j << '\n';
                cntx = 0;
                cnty = 0;
                si = 1;
                bfs(i,j,board[i][j]);
//                cout << "cntx = " << cntx << " cnty = " << cnty << '\n';
//                cout << "si = " << si << '\n';
                if(si == 3)
                {
                    if(cntx == 1 || cnty == 1)
                    {
                        ++ans;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}
