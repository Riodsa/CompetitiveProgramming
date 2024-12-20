#include<bits/stdc++.h>
using namespace std;

const int N = 3e3+5;
int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string a,b;
    cin >> a;
    cin >> b;
    int n = a.size();
    int m = b.size();

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(a[i] == b[j])
            {
                if(i>0&&j>0) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = 0;
            }
            else
            {
                if(i>0&&j>0) dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                else if(i>0&&j==0) dp[i][j] = dp[i-1][j];
                else if(i==0&&j>0) dp[i][j] = dp[i][j-1];
            }
        }
    }
    string s = "";
    n--;
    m--;
    while(n>=0 || m>=0)
    {
        if(a[n] == b[m])
        {
            s += a[n];
            n--;
            m--;
        }
        else
        {
            if(n>0 && m>0)
            {
                if(dp[n-1][m] > dp[n][m-1]) n--;
                else m--;
            }
            else if(n>0&&m==0) n--;
            else if(n==0&&m>0) m--;
        }
    }
    reverse(s.begin(),s.end());
    cout << s;
    return 0;
}
