#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<string> loser;
    set<string> winner;
    string s;
    while(getline(cin,s))
    {
        if(s == "X") break;
        int len = s.size();
        string tmp = "";
        for(int i=0;i<len;++i)
        {
            if(s[i] == ' ') 
            {
                winner.insert(tmp);
                tmp = "";
                continue;
            }
            else if(i == len-1)
            {
                tmp += s[i];
                loser.insert(tmp);
            }
            tmp += s[i];
        }
    }
    // cout << "Winner : ";
    // for(string w : winner) cout << w << ' ';
    // cout << '\n';
    // cout << "Loser : ";
    // for(string l : loser) cout << l << ' ';
    // cout << '\n';
    int cnt = 0;
    for(auto it = winner.begin();it != winner.end();++it)
    {
        if(loser.find(*it) == loser.end())
        {
            cout << *it << ' ';
            ++cnt;
        }
    }
    if(cnt == 0) cout << "None";
    return 0;
}