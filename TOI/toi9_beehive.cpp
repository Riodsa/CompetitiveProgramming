#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
const int N = 1e3+1;
pii dp[N][N];
int hive[N][N];
int n,m;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin >> hive[i][j];
        }
    }
    for(int j=1;j<=m;++j) dp[1][j] = {hive[1][j],1};
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            int o = (i&1?-1:1);
            if(dp[i-1][j].first == dp[i-1][j+o].first)
            {
                dp[i][j].first = dp[i-1][j].first + hive[i][j];
                dp[i][j].second = dp[i-1][j].second + dp[i-1][j+o].second;
            }
            else
            {
                dp[i][j].first = max(dp[i-1][j].first,dp[i-1][j+o].first)+hive[i][j];
                dp[i][j].second = (dp[i][j].first==dp[i-1][j].first+hive[i][j]?dp[i-1][j].second:dp[i-1][j+o].second);
            }
        }
    }
    int mx = -1;
    int cnt = 0;
    for(int j=1;j<=m;++j) mx = max(mx,dp[n][j].first);
    for(int j=1;j<=m;++j) if(dp[n][j].first == mx) cnt += dp[n][j].second;
    cout << mx << " " << cnt;
    return 0;
}
