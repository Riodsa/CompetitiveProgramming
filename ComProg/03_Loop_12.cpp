#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    double a,L=0,U,x;
    cin >> a;
    U = a;
    x = (L+U)/2;
    while(abs(a-pow(10,x)) > (pow(10,-10)*max(a,pow(x,2))))
    {
        if(pow(10,x) > a) U = x;
        else L = x;
        x = (L+U)/2;
    }
    cout << x;
    return 0;
}