#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int act[N][4];
int dp[N][4];
int n;

int solve(int a,int prev)
{
    if(a == n+1) return 0;
    if(dp[a][prev] != -1) return dp[a][prev];
    int mx = -1;
    for(int i=1;i<=3;++i)
    {
        if(i != prev)
        {
            mx = max(mx,solve(a+1,i)+act[a][i]);
        }
    }
//    cout << "mx = " << mx << " a = " << a << " prev = " << prev << '\n';
    return dp[a][prev] = mx;
}

int main()
{
    cin >> n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=3;++j)
        {
            cin >> act[i][j];
        }
    }
    int ans = solve(1,4);
    cout << ans;
    return 0;
}
