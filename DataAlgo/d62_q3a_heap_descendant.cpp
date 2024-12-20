#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> descendant;

void solve(ll u,ll mCap)
{
    descendant.push_back(u);
    if(2*u+1 < mCap) solve(2*u+1,mCap);
    if(2*u+2 < mCap) solve(2*u+2,mCap);
    return ;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a;
    cin >> n >> a;
    solve(a,n);
    sort(descendant.begin(),descendant.end());
    cout << descendant.size() << '\n';
    for(auto b : descendant) cout << b << ' ';
    return 0;
}