#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
const int N = 1e3+1;
int a[N],b[N];
int m,n;
pii dp[N][N];

pii add(pii dp,int time)
{
    if(dp.second+time > m)
    {
        ++dp.first;
        dp.second = time;
    }
    else dp.second += time;
    return dp;
}

pii cmp(pii a,pii b)
{
    if(a.first == b.first) return (a.second<b.second?a:b);
    else return (a.first>b.first?b:a);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    for(int i=1;i<=n;++i)
    {
        cin >> a[i];
        dp[i][0] = add(dp[i-1][0],a[i]);
    }
    for(int i=1;i<=n;++i)
    {
        cin >> b[i];
        dp[0][i] = add(dp[0][i-1],b[i]);
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            dp[i][j] = cmp(add(dp[i-1][j],a[i]),add(dp[i][j-1],b[j]));
        }
    }
    cout << dp[n][n].first+1 << '\n' << dp[n][n].second;
    return 0;
}
