#include<iostream>
#include<cmath>
using namespace std;

#define ll long long

ll power_mod(ll a,ll k,ll m)
{
    if(k == 0) return 1;
    ll x = (ll)pow(power_mod(a,floor(k/2),m),2)%m;
    if(k%2==1) x = (x*a)%m;
    return x%m;
}

int main()
{
    ll a,k,m;
    cin >> a >> k >> m;
    cout << power_mod(a,k,m);
    return 0;
}