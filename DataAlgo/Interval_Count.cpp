#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 2e5+5;
ll n,m,k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    vector<int> vec;
    for(int i=0;i<n;++i)
    {
        ll x; cin >> x;
        vec.push_back(x);
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<m;++i)
    {
        ll x; cin >> x;
        auto start = lower_bound(vec.begin(),vec.end(),x-k);
        auto end = upper_bound(vec.begin(),vec.end(),x+k);
        cout << end-start << ' ';
    }
    return 0;
}