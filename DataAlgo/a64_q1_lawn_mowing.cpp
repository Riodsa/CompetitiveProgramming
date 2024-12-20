#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 5e5+1;
ll n,m,k;
ll qs[N];

ll solve(int start,int x)
{
    int l = start,r = n;
    int mid = (l+r)/2;
    ll ans = 0;
    while(l <= r)
    {
        mid = (l+r)/2;
        ll sum = qs[mid]-qs[start-1];
        ll cost = sum + (mid-start+1)*k;
        // cout << "start: " << start << " mid: " << mid << " cost: " << cost << " sum: " << sum << " tax: " << (mid-start+1)*k << '\n';
        if(cost <= x)
        {
            l = mid+1;
            ans = max(ans,sum);
        }
        else r = mid-1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    qs[0] = 0;
    for(int i=1;i<=n;++i)
    {
        ll x;cin >> x;
        qs[i] = qs[i-1]+x;
    }
    while(m--)
    {
        ll a,b;
        cin >> a >> b;
        a++;
        cout << solve(a,b) << "\n";
    }
    return 0;
}