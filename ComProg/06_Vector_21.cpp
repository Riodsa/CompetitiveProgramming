#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string encode(string s)
{
    int len = s.size();
    vector<string> vec;
    for(int i=0;i<=len;++i)
    {
        string tmp = s.substr(i,len-i) + '$' + s.substr(0,i);
        vec.emplace_back(tmp);
    }
    // for(string x : vec) cout << x << '\n';
    sort(vec.begin(),vec.end());
    string result = "";
    for(string x : vec) result += x[x.size()-1];
    return result;
}

int main()
{
    string s;
    cin >> s;
    cout << encode(s);
    return 0;
}