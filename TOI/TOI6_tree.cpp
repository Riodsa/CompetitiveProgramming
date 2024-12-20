#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int,int>> p1;
    for(int i=1;i<=n-1;++i)
    {
        int u,v;
        cin >> u >> v;
        if(u > v) swap(u,v);
        p1.emplace_back(u,v);
    }
    vector<pair<int,int>> p2;
    for(int i=1;i<=n-1;++i)
    {
        int u,v;
        cin >> u >> v;
        if(u > v) swap(u,v);
        p2.emplace_back(u,v);
    }
    sort(p1.begin(),p1.end());
    sort(p2.begin(),p2.end());
    if(p1 == p2) cout << "Y";
    else cout << "N";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t=5;
    while(t--)
    {
        solve();
    }
    return 0;
}
