#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    multiset<ll> ss;
    for(int i=0;i<n;++i)
    {
        ll x; cin >> x;
        ss.insert(x);
    }
    for(int i=0;i<m;++i)
    {
        ll x; cin >> x;
        bool can = false;
        for(ll y : ss)
        {
            ll tar = x-y;
            if(y > x/2) break;
            if(ss.find(tar) != ss.end() && (tar!=y || ss.count(y)>=2))
            {
                can = true;
                break;
            }
        }
        if(can) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}