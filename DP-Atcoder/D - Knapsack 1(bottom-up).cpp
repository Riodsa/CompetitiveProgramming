#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int W = 1e5+5,N = 1e2+5;
ll dp[N][W];
int n,k;
ll w[N],v[N];

int main()
{
    cin >> n >> k;
    for(int i=1;i<=n;++i)
    {
        cin >> w[i] >> v[i];
    }
    dp[0][0] = 0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=k;++j)
        {
            if(j-w[i] >= 0)
            {
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << dp[n][k];
    return 0;
}
