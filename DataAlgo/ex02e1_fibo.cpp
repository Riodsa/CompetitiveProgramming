#include<bits/stdc++.h>
using namespace std;

const int N = 45;
int dp[N];

int fibo(int n)
{
    if(n == 0 || n == 1) return dp[n]; 
    if(dp[n] != 0) return dp[n];
    dp[n] = fibo(n-1)+fibo(n-2);
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    cout << fibo(n);
    return 0;
}