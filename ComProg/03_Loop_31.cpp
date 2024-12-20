#include<iostream>
#include<cmath>
using namespace std;

#define ll unsigned long long int

ll mpow(int a,int b)
{
    ll res = 1;
    while(b--) res *= a;
    return res;
}

int main()
{
    ll digit = 0;
    ll a,b;
    cin >> a >> b;
    string x = to_string(a);
    string y = to_string(b);
    int lena = x.size(),lenb = y.size();
    if(lena == lenb)
    {
        ll xx = (b-a+1)*lena;
        digit += xx;
    }
    else if(lena < lenb)
    {
        ll xx = (mpow(10,lena)-a) * lena;
        ll yy = (b - mpow(10,lenb-1)+1) * lenb;
        digit += xx + yy;
        for(int i=lena+1;i<=lenb-1;++i) digit += i*(mpow(10,i)-mpow(10,i-1));
    }
    cout << digit;
    return 0;
}