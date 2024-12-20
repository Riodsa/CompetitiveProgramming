#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int V = 1e5+1;
const int N = 1e2+5;
ll w[N],v[N];
ll dp[V];
int n,k;

int main()
{
    cin >> n >> k;
    for(int i=1;i<=n;++i)
    {
        cin >> w[i] >> v[i];
    }
    for(int i=0;i<V;++i) dp[i] = 1e18;
    dp[0] = 0;
    for(int i=1;i<=n;++i)
    {
        for(int j=V-1;j>=0;--j)
        {
            if(dp[j]+w[i] <= k) dp[j+v[i]] = min(dp[j+v[i]],dp[j]+w[i]);
        }
    }
    for(int j=V-1;j>=0;--j)
    {
        if(dp[j] != 1e18)
        {
            cout << j;
            break;
        }
    }
    return 0;
}
