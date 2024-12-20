#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e6+5;
const int M = 1e2+5;
const int MOD = 1e9+7;
int dp[N];
int coin[M];
int n,k;
 
int main()
{
    cin >> k;
    for(int i=1;i<=k;++i)
    {
        coin[i] = i;
    }
    dp[0] = 1;
    for(int i=1;i<=k;++i)
    {
        for(int j=1;j<=k;++j)
        {
            if(j-coin[i] >= 0)
            {
                dp[j] = (dp[j] + dp[j-coin[i]])%MOD;
            }
        }
    }
    cout << dp[k];
}
