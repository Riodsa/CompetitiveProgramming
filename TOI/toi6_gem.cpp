#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m;
    cin >> n >> m;
    unordered_map<int,int> cnt;
    set<int> marble;
    unordered_map<int,int> curse;
    for(int i=0;i<n;++i)
    {
        int x; cin >> x;
        marble.insert(x);
        cnt[x]++;
    }
    for(int j=0;j<m/2;++j)
    {
        int a,b;
        cin >> a >> b;
        mp[a] = b;
        mp[b] = a;
    }
    int amo = 0;
    for(int i=1;i<=n;++i)
    {
        if(curse[i] == 0) amo+=cnt[i];
    }
    if(amo >= n)
    {
        cout << "Y" << '\n';
        return ;
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 5;
    while(t--)
    {
        solve();
    }
    return 0;
}
