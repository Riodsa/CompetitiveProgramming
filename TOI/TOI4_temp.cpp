#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
const int N = 25;
int b[N][N];
int m;
int ans = -6;
pii idx[4] = {{1,0},{0,1},{-1,0},{0,-1}};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m;
    int x,y;
    cin >> x >> y;
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin >> b[i][j];
        }
    }
    queue<pii> q;
    q.push({y,x});
    while(!q.empty())
    {
        int posy,posx;
        tie(posy,posx) = q.front();
        q.pop();
        if(ans < b[posy][posx]) ans = b[posy][posx];
        for(int i=0;i<4;++i)
        {
            int ty,tx;
            ty = posy+idx[i].first;
            tx = posx+idx[i].second;
            if(ty < 1 || ty > m || tx < 1 || tx > m) continue;
            if(b[ty][tx] != 100 && b[ty][tx] > b[posy][posx])
            {
                q.push({ty,tx});
            }
        }
    }
    cout << ans;
    return 0;
}
