#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;
const int N = 1e5+5;
int h[N];
int dp[N];
int n;

int main()
{
    fill(h,h+n+1,INF);
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        cin >> h[i];
    }
    for(int i=1;i<=n;++i)
    {
        if(i-2 >= 0) dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
    }
    cout << dp[n];
    return 0;
}
