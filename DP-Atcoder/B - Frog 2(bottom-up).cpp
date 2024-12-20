#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int h[N];
int dp[N];

int main()
{
    int n,k;
    cin >> n >> k;
    fill(dp,dp+n+1,-1);
    for(int i=1;i<=n;++i)
    {
        cin >> h[i];
    }
    dp[0] = 1e9+7;
    dp[1] = 0;
    for(int i=2;i<=n;++i)
    {
        int min_jump = 1e9+7;
        for(int j=1;j<=k;++j)
        {
            if(i-j > 0)
            {
                min_jump = min(min_jump,dp[i-j]+abs(h[i]-h[i-j]));
            }
        }
        dp[i] = min_jump;
    }
    cout << dp[n];
    return 0;
}
