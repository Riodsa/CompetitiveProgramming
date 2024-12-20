#include<bits/stdc++.h>
using namespace std;

#define pis pair<int,string>
#define pic pair<int,char>
map<pis,pic> mp;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    mp[{1,"00"}] = {1,'0'};
    mp[{1,"11"}] = {2,'1'};
    mp[{2,"10"}] = {3,'0'};
    mp[{2,"01"}] = {4,'1'};
    mp[{3,"00"}] = {2,'1'};
    mp[{3,"11"}] = {1,'0'};
    mp[{4,"01"}] = {3,'0'};
    mp[{4,"10"}] = {4,'1'};

    int n;
    cin >> n;
    int s = 1,len,len2,sum,p;
    string ch = "";
    while(n--)
    {
        string str;
        cin >> str;
        len = str.length();
        ch.clear();
        string tmp = "";
        for(int i=0;i<len;i+=2)
        {
            tmp.clear();
            tmp.push_back(str[i]);
            tmp.push_back(str[i+1]);
            ch.push_back(mp[{s,tmp}].second);
//            cout << "ch = " << ch << '\n';
            s = mp[{s,tmp}].first;
        }
        len2 = ch.length();
        sum = 0 , p = 1;
        for(int i=len2-1;i>=0;--i)
        {
            sum += (ch[i]-'0')*p;
            p*=2;
        }
//        cout << ch << '\n';
//        cout << sum << '\n';
        if(sum >= 'A' && sum <= 'Z') cout << (char)sum;
    }
    return 0;
}
