#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    double dist[n][n];
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cin >> dist[i][j];
    for(int k=0;k<n;++k)
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(dist[i][j] < dist[i][k]*dist[k][j])
                    dist[i][j] = dist[i][k]*dist[k][j];
    bool hasGlitchMoney = false;
    for(int i=0;i<n;++i)
        if(dist[i][i] > 1) hasGlitchMoney = true;
    if(hasGlitchMoney) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}