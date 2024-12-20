#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    double maxscore,minscore;
    if(a <= b && a <= c && a <= d) minscore = a;
    if(b <= a && b <= c && b <= d) minscore = b;
    if(c <= a && c <= b && c <= d) minscore = c;
    if(d <= a && d <= b && d <= c) minscore = d;
    if(a >= b && a >= c && a >= d) maxscore = a;
    if(b >= a && b >= c && b >= d) maxscore = b;
    if(c >= a && c >= b && c >= d) maxscore = c;
    if(d >= a && d >= b && d >= c) maxscore = d;
    if(a == maxscore && b == minscore) cout << round((c+d)/2*100)/100;
    else if(a == maxscore && c == minscore) cout << round((b+d)/2*100)/100;
    else if(a == maxscore && d == minscore) cout << round((b+c)/2*100)/100;
    else if(b == maxscore && c == minscore) cout << round((a+d)/2*100)/100;
    else if(b == maxscore && d == minscore) cout << round((a+c)/2*100)/100;
    else if(c == maxscore && d == minscore) cout << round((a+b)/2*100)/100;

    else if(a == minscore && b == maxscore) cout << round((c+d)/2*100)/100;
    else if(a == minscore && c == maxscore) cout << round((b+d)/2*100)/100;
    else if(a == minscore && d == maxscore) cout << round((b+c)/2*100)/100;
    else if(b == minscore && c == maxscore) cout << round((a+d)/2*100)/100;
    else if(b == minscore && d == maxscore) cout << round((a+c)/2*100)/100;
    else if(c == minscore && d == maxscore) cout << round((a+b)/2*100)/100;
    return 0;
}