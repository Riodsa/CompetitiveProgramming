#include<bits/stdc++.h>
using namespace std;

char midd(char a,char b,char c)
{
    if(a >= b && a <= c) return a;
    else if(a >= c && a <= b) return a;
    if(b >= a && b <= c) return b;
    else if(b >= c && b <= a) return b;
    if(c >= a && c <= b) return c;
    else if(c >= b && c <= a) return c;
}

int main()
{
    int l,k;
    string a,b,x;
    cin >> l >> k;
    cin >> a;
    cin >> b;
    cin >> x;
    for(int i=0;i<k;++i)
    {
        for(int j=0;j<l;++j)
        {
            x[i] = midd(a[j],b[j],x[i]);
        }
    }
    cout << x;
    return 0;
}
