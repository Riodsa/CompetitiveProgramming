#include <iostream>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

ll F(ll n)
{ // Fibonacci number
    if(n == 0) return 0;
    if(n == 1) return 1;
    return F(n-1)+F(n-2);
}
ll M(ll n)
{ // Motzkin number
    if(n == 0 || n == 1) return 1;
    int sum = M(n-1);
    for(int k=0;k<=n-2;++k) sum += M(k)*M(n-2-k);
    return sum;
}
ll S(ll n)
{ // Schröder–Hipparchus Number
    if(n == 1 || n == 2) return 1;
    if(n >= 3) return ((6*n-9)*S(n-1)-(n-3)*S(n-2))/n;
    return 0;
}
ll D(ll n)
{ // Derangement
    if(n == 0) return 1;
    return n*D(n-1) + pow(-1,n);
    return 0;
}
int main()
{
    map<string, ll (*)(ll)> func = {{"F", F}, {"M", M}, {"S", S}, {"D", D}};
    string fn;
    ll p;
    while (cin >> fn >> p)
    {
        if (func.find(fn) != func.end())
            cout << fn << '(' << p << ") = " << func[fn](p) << '\n';
    }
    return 0;
}
