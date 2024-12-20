#include<bits/stdc++.h>
using namespace std;

const int N = 5e3+1;
int dp[N][N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string a,b;
    cin >> a >> b;
    int lena = a.size();
    int lenb = b.size();
    // cout << "a: " << a << '\n';
    // cout << "b: " << b << '\n';
    for(int i=0;i<=lena;++i)
    {
        for(int j=0;j<=lenb;++j)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(a[i-1] == b[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout << dp[lena][lenb];
    return 0;
}