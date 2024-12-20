#include<bits/stdc++.h>
using namespace std;

int dayinmonth[] = {29,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int ans = 0;
    int d,m,y;
    cin >> d >> m >> y;
    y -= 543;
    m--;
    bool lp = false;
    if(y%400==0) lp = true;
    else if(y%100==0) lp = false;
    else if(y%4==0) lp = true;
    while(m > 0)
    {
        if(m != 2) ans += dayinmonth[m];
        else
        {
            if(lp) ans += 29;
            else ans += 28;
        }
        m--;
    }
    cout << ans+d;
    return 0;
}