#include<bits/stdc++.h>
using namespace std;

#define ll long long

map<ll,vector<ll>> mat;

ll mpow(ll a,ll b)
{
    if(b == 0) return 1;
    ll x = (mpow(a,b/2)*mpow(a,b/2));
    if(b%2 == 1) x *= a;
    return x;
}

const ll N = mpow(2,30);
int n,k;
vector<ll> matmul(vector<ll> m,vector<ll> n)
{
    vector<ll> x(4);
    ll m1=m[0],m2=m[1],m3=m[2],m4=m[3];
    ll n1=n[0],n2=n[1],n3=n[2],n4=n[3];
    x[0] = ((m1*n1)%k+(m2*n3)%k)%k;
    x[1] = ((m1*n2)%k+(m2*n4)%k)%k;
    x[2] = ((m3*n1)%k+(m4*n3)%k)%k;
    x[3] = ((m3*n2)%k+(m4*n4)%k)%k;
    return x;
}

vector<ll> matpow(vector<ll> a,ll b)
{
    if(b == 1) return mat[1];
    if(mat.find(b) != mat.end()) return mat[b];
    else
    {
        vector<ll> x = matpow(a,b/2);
        x = matmul(x,x);
        if(b%2 == 1) x = matmul(x,a);
        mat[b] = x;
        return mat[b];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    vector<ll> matx(4);
    cin >> matx[0] >> matx[1] >> matx[2] >> matx[3];
    mat[1] = matx;
    vector<ll> ans = matpow(mat[(ll)1],n);
    for(int x : ans) cout << x << ' ';
    return 0;
}