#include<bits/stdc++.h>
using namespace std;

const int N = 3e2+1;
struct pipe
{
    int u,r,d,l;
};
int n,m;
pipe p[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            int x; cin >> x;
            if(x == 11) p[i][j].u = p[i][j].l = 1;
            else if(x == 12) p[i][j].u = p[i][j].l = 1;
            else if(x == 13) p[i][j].d = p[i][j].l = 1;
            else if(x == 14) p[i][j].d = p[i][j].r = 1;
            else if(x == 21) p[i][j].d = p[i][j].u = 1;
            else if(x == 22) p[i][j].l = p[i][j].r = 1;
            else if(x == 31) p[i][j].d = p[i][j].l = p[i][j].r = p[i][j].u = 1;
        }
    }
    return 0;
}
