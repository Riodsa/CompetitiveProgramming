#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
const int N = 1e3+1;
int n,m;
char b[N][N];
pii idx[4] = {{-1,0},{1,0},{0,1},{0,-1}};
int cnt,ans = -1;

void flood(int r,int c)
{
    b[r][c] = '_';
    for(int i=0;i<4;++i)
    {
        int rr = r+idx[i].first , cc = c+idx[i].second;
        if(rr < 1 || rr > n || cc < 1 || cc > m) continue;
        if(b[rr][cc] != 'X' && b[rr][cc] != '_') flood(rr,cc);
    }
    return ;
}

void bfs(int r,int c)
{
    b[r][c] = '-';
    for(int i=0;i<4;++i)
    {
        int rr = r+idx[i].first , cc = c+idx[i].second;
        if(rr < 1 || rr > n || cc < 1 || cc > m) continue;
        if(b[rr][cc] == '_') ++cnt;
        else if(b[rr][cc] == 'X') bfs(rr,cc);
    }
}

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
    flood(n,m);
//    for(int i=1;i<=n;++i)
//    {
//        for(int j=1;j<=m;++j)
//        {
//            cout << b[i][j];
//        }
//        cout << '\n';
//    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(b[i][j] == 'X')
            {
                cnt = 0;
                b[i][j] = '-';
                bfs(i,j);
                ans = max(ans,cnt);
            }
        }
    }
    cout << ans;
    return 0;
}
