#include<bits/stdc++.h>
using namespace std;

const int N = 1501;
#define pii pair<int,int>
#define ppi tuple<int,int,int,int>
int tx,ty;
int n;
int x[5][N],y[5][N];
vector<ppi> res;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> tx >> ty >> n;
    for(int i=1;i<=4;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin >> x[i][j] >> y[i][j];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            res.push_back({x[1][i]+x[2][j],y[1][i]+y[2][j],i,j});
        }
    }
    sort(res.begin(),res.end());
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            int xx = tx-x[3][i]-x[4][j];
            int yy = ty-y[3][i]-y[4][j];
            ppi idx = *lower_bound(res.begin(),res.end(),ppi(xx,yy,0,0));
            if(get<0>(idx) == xx && get<1>(idx) == yy)
            {
                int r = get<2>(idx),c=get<3>(idx);
                cout << x[1][r] << " " << y[1][r] << "\n" << x[2][c] << " " << y[2][c] << "\n" << x[3][i] << " " << y[3][i] << "\n" << x[4][j] << " " << y[4][j] << "\n";
                return 0;
            }
        }
    }
    return 0;
}
