#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    double xm,ym, xe,ye, re,rp;
    cin >> xe >> ye >> re >> rp >> xm >> ym;
    double x,y,A,B,C,c = re-rp;
    A = xm-xe, B = ym-ye, C = sqrt(A*A+B*B);
    double radio = c/C;
    x = A*radio;
    y = B*radio;
    // cout << "A = " << A << " B = " << B << " C = " << C << " Radio = " << radio << '\n';
    cout << round(xe+x) << ' ' << round(ye+y);
    return 0;
}