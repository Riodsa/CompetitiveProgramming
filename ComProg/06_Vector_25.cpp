#include<bits/stdc++.h>
using namespace std;

string upgrade(string x)
{
    if(x == "A") return "A";
    else if(x == "B+") return "A";
    else if(x == "B") return "B+";
    else if(x == "C+") return "B";
    else if(x == "C") return "C+";
    else if(x == "D+") return "C";
    else if(x == "D") return "D+";
    else if(x == "F") return "D";
    else return "";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    vector<pair<string,string>> vec;
    while(cin >> s)
    {
        if(s == "q") break;
        string grade;
        cin >> grade;
        vec.push_back({s,grade});
    }
    string up;
    cin.ignore();
    getline(cin,up);
    string tmp = "";
    int len = up.size();
    for(int i=0;i<len;++i)
    {
        if(up[i] == ' ' || i == len-1)
        {
            if(i == len-1) tmp += up[i];
            for(int j=0;j<(int)vec.size();++j)
            {
                if(tmp == vec[j].first) vec[j].second = upgrade(vec[j].second);
            }
            tmp = "";
            continue;
        }
        tmp += up[i];
    }
    for(auto x : vec)
    {
        cout << x.first << ' ' << x.second << '\n';
    }
    return 0;
}