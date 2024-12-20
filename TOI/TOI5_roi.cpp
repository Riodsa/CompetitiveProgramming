#include<bits/stdc++.h>
using namespace std;

int ansi,ansj;
double minprof = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tar;
    cin >> tar;
    for(int i=74;i<=144;++i)
    {
        int t = 100;
        for(int j=1000;j<=15000;j+=500)
        {
            double in = ( ((100 - 0.8569 * exp(0.09*(i-100))) * j)/100 ) * i;
            double out = tar + (j*t);
            double profit = in-out;
            if(profit > 0 && profit < minprof)
            {
                ansj = j;
                ansi = i;
                minprof = profit;
            }
            --t;
        }
    }
    printf("%d\n%d\n%.2lf",ansj,ansi,minprof);
    return 0;
}
