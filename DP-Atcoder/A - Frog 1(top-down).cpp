#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int INF = 1e9+7;
int h[N];
int dp[N];

int solve(int n)
{
    if(dp[n] != -1) return dp[n];
    if(n == 1) return dp[n] = 0;
    if(n == 0) return dp[n] = INF;

    return dp[n] = min(solve(n-1)+abs(h[n-1]-h[n]),solve(n-2)+abs(h[n-2]-h[n]));;
}

int main()
{
    int n;
    cin >> n;
    fill(dp,dp+n+1,-1);
    for(int i=1;i<=n;++i)
    {
        cin >> h[i];
    }
    cout << solve(n);
    return 0;
}
