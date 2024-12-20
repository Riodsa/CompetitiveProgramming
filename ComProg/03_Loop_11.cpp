#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    double ave=0,cnt=0;
    while(1)
    {
        double x;
        cin >> x;
        if(x == -1) break;
        ave += x;
        ++cnt;
    }
    if(cnt == 0) cout << "No Data";
    else
    {
        ave /= cnt;
        cout << round(ave*100)/100;
    }
    return 0;
}