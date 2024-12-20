#include<iostream>
#include<map>
#include<set> 
#include<vector>
using namespace std;

int main()
{
    map<string,set<string>> mp;
    string str;
    string a,b;
    while(getline(cin,str))
    {
        a = "",b = "";
        int cnt = 0;
        string tmp = "";
        int len = str.size();
        for(int i=0;i<len;++i)
        {
            if(str[i] == ' ' || i == len-1)
            {
                if(i == len-1) tmp += str[i];
                if(cnt == 0)
                {
                    a = tmp;
                    cnt = 1;
                }
                else if(cnt == 1)
                {
                    b = tmp;
                    cnt = 2;
                }
                tmp = "";
                continue;
            }
            tmp += str[i];
        }
        // if(a == "x") break;
        if(cnt == 1) break;
        mp[a].insert(b);
        mp[b].insert(a);
        // cout << "a = " << a << " b = " << b << '\n';
    }
    set<string> ss;
    string s;
    s = a;
    // cout << "s = " << s << '\n';
    // for(auto it = mp.begin();it != mp.end();++it)
    // {
    //     cout << it->first << " : ";
    //     for(string station : it->second) cout << station << ' ';
    //     cout << '\n';
    // }
    ss.insert(s);
    for(string x : mp[s])
    {
        ss.insert(x);
        for(string y : mp[x])
        {
            ss.insert(y);
        }
    }
    for(string x : ss) cout << x << '\n';
    return 0;
}