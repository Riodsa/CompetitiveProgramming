#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e2+5, W = 1e5+5;
ll dp[N][W];
ll w[N],v[N];
int n,k;

ll solve(ll a,ll wei)
{
    if(a == 0 || wei == 0) return 0;

    if(dp[a][wei] != -1) return dp[a][wei];

    if(wei-w[a] >= 0)
    {
        dp[a][wei] = max(solve(a-1,wei),solve(a-1,wei-w[a])+v[a]);
    }
    else dp[a][wei] = solve(a-1,wei);

    return dp[a][wei];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;++i)
    {
        cin >> w[i] >> v[i];
    }
    cout << solve(n,k);
    return 0;
}
