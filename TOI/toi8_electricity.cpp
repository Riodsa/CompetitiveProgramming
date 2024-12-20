#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+1;
int n,k;
int num[N];
int dp[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;++i) cin >> num[i];
    fill(dp,dp+1+n,1e9+7);
    dp[1] = num[1];
    deque<pair<int,int>> dq;
    dq.push_back({dp[1],1});
    for(int i=2;i<=n;++i)
    {
        while(!dq.empty() && i-dq.front().second > k) dq.pop_front();
        dp[i] = num[i] + dq.front().first;
        while(!dq.empty() && dq.back().first > dp[i]) dq.pop_back();
        dq.push_back({dp[i],i});
    }
    cout << dp[n];
    return 0;
}
