#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<string,double> exchange;
    int n; cin >> n;
    exchange["THB"] = 1;
    for(int i=0;i<n;++i)
    {
        string country;
        double rate;
        cin >> country >> rate;
        exchange[country] = rate;
    }
    double money;
    cin >> money;
    string s,r;
    int cnt = 0;
    while(cin >> s)
    {
        // if(s == "x") break;
        if(cnt == 0) cout << (int)money << ' ' << s << ' ';
        else
        {
            double tmp = int(money*exchange[r]/exchange[s]);
            cout << "-> " << (int)tmp << ' ' << s << ' ';
            money = tmp;
        }
        r = s;
        ++cnt;
    }
    return 0;
}