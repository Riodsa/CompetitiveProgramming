#include<iostream>
#include<cmath>
using namespace std;

int dayinmonth(int i,int y)
{
    if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) return 31;
    else if(i == 4 || i == 6 || i == 9 || i == 11) return 30;
    else if(i == 2 && ((y%4==0&&y%100!=0) || y%400 == 0)) return 29;
    else return 28;
}

int main()
{
    double d1,m1,y1;
    double d2,m2,y2;
    cin >> d1 >> m1 >> y1;
    y1 -= 543;
    cin >> d2 >> m2 >> y2;
    y2 -= 543;
    double red=0,black=0,blue=0;
    red += dayinmonth(m1,y1)-d1+1;
    for(int i=m1+1;i<=12;++i) red += dayinmonth(i,y1);
    for(int i=y1+1;i<=y2-1;++i)
    {
        // cout << i << ' ';
        // if((i%4==0&&i%100!=0) || i%400 == 0) black += 366;
        // else black += 365;
        black += 365;
    }
    blue += d2-1;
    for(int i=m2-1;i>=1;--i) blue += dayinmonth(i,y2);
    double t = red + black + blue;
    // cout << "t = " << t << " red = " << red << " black = " << black << " blue = " << blue;
    double phy = sin((2*M_PI*t)/23);
    double emo = sin((2*M_PI*t)/28);
    double intel = sin((2*M_PI*t)/33);
    cout << t << ' ' << round(phy*100)/100 << ' ' << round(emo*100)/100 << ' ' << round(intel*100)/100;
    return 0;
}