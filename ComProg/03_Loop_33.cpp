#include<iostream>
#include<climits>
using namespace std;

int main()
{
    bool zig_zag = false;
    bool zag_zig = false;
    int cnt = 0;
    int mx1 = INT_MIN,mx2 = INT_MIN;
    int mn1 = INT_MAX,mn2 = INT_MAX;
    while(1)
    {
        int x,y;
        cin >> x;
        if(x == -998 || x == -999)
        {
            if(x == -998) zig_zag = true;
            else if(x == -999) zag_zig = true;
            break;
        }
        cin >> y;
        if(cnt%2 == 0)
        {
            if(mx1 < x) mx1 = x;
            if(mn1 > x) mn1 = x;
            if(mx2 < y) mx2 = y;
            if(mn2 > y) mn2 = y;
        }
        else
        {
            if(mx1 < y) mx1 = y;
            if(mn1 > y) mn1 = y;
            if(mx2 < x) mx2 = x;
            if(mn2 > x) mn2 = x;
        }
        ++cnt;
    }
    if(zig_zag && !zag_zig) cout << mn1 << ' ' << mx2;
    else if(!zig_zag && zag_zig) cout << mn2 << ' ' << mx1;
    return 0;
}