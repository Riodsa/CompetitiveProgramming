#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int INF = 1e9+7;
int h[N];
int dp[N];
int n,k;

int solve(int a)
{
    if(dp[a] != -1) return dp[a];
    if(a == 0) return dp[a] = INF;
    if(a == 1) return dp[a] = 0;

    int min_j = INF;
    for(int i=1;i<=k;++i)
    {
        if(a-i > 0)
        {
            min_j = min(min_j,solve(a-i)+abs(h[a]-h[a-i]));
        }
    }
    return dp[a] = min_j;
}

int main()
{
    cin >> n >> k;
    fill(dp,dp+n+1,-1);
    for(int i=1;i<=n;++i)
    {
        cin >> h[i];
    }
    cout << solve(n);
    return 0;
}
