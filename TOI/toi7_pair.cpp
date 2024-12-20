#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
const int N = 1e5+1;
int n;
vector<pii> num;
struct Fenwick
{
    ll a[N];
    void update(int idx,int value)
    {
        for(int i=idx;i<N;i += i&-i) a[i]+=value;
    }
    ll sum(int idx)
    {
        ll sum = 0;
        for(int i=idx;i>0;i -= i&-i) sum += a[i];
        return sum;
    }
};
Fenwick fw1,fw2;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0;i<n;++i)
    {
        ll a,b;
        cin >> a >> b;
        num.push_back({b,a});
    }
    sort(num.begin(),num.end(),greater<>());
    ll ans = 0;
    for(int i=0;i<n;++i)
    {
        ll a = num[i].second;
        ans += (a*fw2.sum(a)) + fw1.sum(a);
        fw1.update(a,a);
        fw2.update(a,1);
    }
    cout << ans;
    return 0;
}
