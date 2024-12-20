#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int INF = 1e9+7;
int dp[N];
int h[N];
int n;

int solve(int i)
{
    if(dp[i] != -1) return dp[i];

    if(i == 1) return dp[i] = 0;
    if(i == 0) return dp[i] = INF;

    return dp[i] = min(solve(i-1) + abs(h[i] - h[i-1]),
                       solve(i-2) + abs(h[i] - h[i-2]));

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        cin >> h[i];
    }
    fill(dp,dp+n+1,-1);
    cout << solve(n);
    return 0;
}

