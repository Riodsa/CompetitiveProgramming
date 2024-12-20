#include<iostream>
#include<map>
#include<set>
using namespace std;

set<string> ans;

void ana(string s,string str,int len,map<char,int> all_char,map<char,int> now_char)
{
    int l = s.size();
    // cout << "s = " << s << "[" << l << "]" << " str = " << str << " len = " << len << '\n';
    if(l == len)
    {
        ans.insert(s);
        return ;
    }
    else if(l > len) return ;
    for(int i=0;i<len;++i)
    {
        if(now_char[str[i]] < all_char[str[i]])
        {
            s.push_back(str[i]);
            now_char[str[i]]++;
            ana(s,str,len,all_char,now_char);
            now_char[str[i]]--;
            s.pop_back();
        }
    }
}

int main()
{
    string x;
    cin >> x;
    int len = x.size();
    map<char,int> mp,tmp;
    for(int i=0;i<len;++i) mp[x[i]]++;
    // cout << "x = " << x << " len = " << len << '\n'; 
    ana("",x,len,mp,tmp);
    for(string a : ans) cout << a << ' ';
    return 0;
}