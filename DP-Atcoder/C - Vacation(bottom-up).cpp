#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int dp[N][4];
int act[N][4];

int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=3;++j)
        {
            cin >> act[i][j];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=3;++j)
        {
            int max_cost = -1;
            for(int k=1;k<=3;++k)
            {
                if(j!=k)
                {
                    max_cost = max(max_cost,dp[i-1][k]+act[i][k]);
                }
            }
            dp[i][j] = max_cost;
        }
    }
    int ans = -1;
    for(int i=1;i<=3;++i)
    {
        ans = max(ans,dp[n][i]);
    }
    cout << ans;
    return 0;
}
