#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll R,C,k;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> k;
    map<pair<ll,ll>,ll> ans;
    vector<ll> vec(k+1);
    ll m=R*C;
    for(int i=0;i<k;++i){
        ll r,c; cin >> r >> c;
        vec[i] = (r-1)*C+c;
        m = min(m,vec[i]);
    }
    vec[k] = m+R*C;
    sort(vec.begin(),vec.end());
    ll q; cin >> q;
    while(q--)
    {
        ll a,b,x; cin >> a >> b;
        if(ans.find({a,b})!=ans.end())
        {
            cout << ans[{a,b}] << '\n';
            continue;
        }
        x=(a-1)*C+b;
        ans[{a,b}] = *lower_bound(vec.begin(),vec.end(),x)-x;
        cout << ans[{a,b}] << '\n';
    }
}
