#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+1;
const int K = 11;
const int MOD = 1000003;
int n,k;
int num[K];
int dp[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for(int i=0;i<k;++i)
    {
        cin >> num[i];
        dp[num[i]] = 1;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<k;++j)
        {
            if(i-num[j] >= 0)
            {
                dp[i] += (dp[i-num[j]])%MOD;
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[n];
    return 0;
}