#include<iostream>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;

long gcd(long a,long b)
{
    if(b == 0) return a;
    return gcd(b,a%b);
}

int main()
{
    string a,b,c;
    cin >> a >> b >> c;
    int lenb = b.size(), lenc = c.size();
    double fraction = stoi(b)*pow(10,lenc)+stoi(c) - stoi(b);
    double div = (pow(10,lenc)-1) * pow(10,lenb);
    int upper = stoi(a)*div + fraction;
    double g = gcd(upper,div);
    // cout << upper << ' ' << div;
    // cout << (stoi(a)*div + fraction);
    cout << setprecision(0) << fixed << round(upper/g) << " / " << round(div/g);
    return 0;
}