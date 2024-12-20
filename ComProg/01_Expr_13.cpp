#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    float a,b,c;
    cin >> a >> b >> c;
    float x1 = (-b-sqrt(pow(b,2) - 4*a*c))/(2*a);
    float x2 = (-b+sqrt(pow(b,2) - 4*a*c))/(2*a);
    cout << round(x1*1e3)/1e3 << ' ' << round(x2*1e3)/1e3;
    return 0;
}