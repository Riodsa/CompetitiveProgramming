#include<bits/stdc++.h>
using namespace std;
int main()
{
    double x=0,y=0;
    while(1)
    {
        string s;
        cin >> s;
        if(s == "*") break;
        double sum = 0;
        string ord = "";
        for(int i=0;i<s.size();++i)
        {
            if(s[i] >= 'A' && s[i] <= 'Z') ord += s[i];
            else
            {
                sum += (s[i]-'0');
                if(s[i+1] >= '0' && s[i+1] <= '9') sum *= 10;
            }
        }
        double sum2 = sum/(double)sqrt(2);
        if(ord == "N")
        {
            y += sum;
        }
        else if(ord == "NE")
        {
            y += sum2;
            x += sum2;
        }
        else if(ord == "E")
        {
            x += sum;
        }
        else if(ord == "SE")
        {
            x += sum2;
            y -= sum2;
        }
        else if(ord == "S")
        {
            y -= sum;
        }
        else if(ord == "SW")
        {
            x -= sum2;
            y -= sum2;
        }
        else if(ord == "W")
        {
            x -= sum;
        }
        else if(ord == "NW")
        {
            x -= sum2;
            y += sum2;
        }
//        cout << ord << " " << sum << '\n';
    }
    printf("%.3lf %.3lf\n",x,y);
    double dis = sqrt(pow(x,2)+pow(y,2));
    printf("%.3lf",dis);
    return 0;
}
