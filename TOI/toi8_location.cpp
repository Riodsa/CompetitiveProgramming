#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+1;
int qs[N][N];
int n,m,k;
int mx = -1;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    cin >> k;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            int x; cin >> x;
            qs[i][j] = x + qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
        }
    }
//    for(int i=1;i<=n;++i)
//    {
//        for(int j=1;j<=m;++j)
//        {
//            cout << qs[i][j] << " ";
//        }
//        cout << '\n';
//    }
    for(int i=k;i<=n;++i)
    {
        for(int j=k;j<=m;++j)
        {
            mx = max(mx,qs[i][j]-qs[i-k][j]-qs[i][j-k]+qs[i-k][j-k]);
        }
    }
    cout << mx;
    return 0;
}
