#include<bits/stdc++.h>
using namespace std;

#define ll long long
unordered_map<ll,ll> mp;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    while(n--)
    {
        ll ord;
        cin >> ord;
        if(ord == 0)
        {
            ll x,y;
            cin >> x >> y;
            mp[x] = y;
        }
        else if(ord == 1)
        {
            ll x;
            cin >> x;
            cout << mp[x] << '\n';
        }
    }
    return 0;
}
