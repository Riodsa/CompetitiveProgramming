#include<bits/stdc++.h>
using namespace std;

const int N = 31;
int dp[N][N];

int C(int n,int k)
{
    if(n == k || k == 0) return 1;
    if(dp[n][k] != 0) return dp[n][k];
    dp[n][k] = C(n-1,k-1)+C(n-1,k);
    return dp[n][k];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    cout << C(n,k);
    return 0;
}