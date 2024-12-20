#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int main()
{
    map<string,vector<string>> mp;
    map<string,vector<string>> alpha;
    map<string,int> idx;
    int n;
    cin >> n;
    for(int i=0;i<n;++i)
    {
        string s; cin >> s;
        string c;
        while(cin >> c)
        {
            if(c == "*") break;
            mp[s].push_back(c);
            alpha[c].push_back(s);
        }
        idx[s] = i;
    }
    string key;
    cin >> key;
    bool found = false;
    set<string> ss;
    vector<pair<int,string>> ans;
    for(string s : mp[key])
    {
        // cout << s << " : ";
        if(!alpha[s].empty()) 
        {
            for(string c : alpha[s]) 
            {
                if(c != key)
                {
                    // cout << c << ' ';
                    ss.insert(c);
                    // cout << ">> " << c << '\n';
                    found = true;
                }
            }
        }
        // cout << '\n';
    }
    for(string xx : ss) ans.push_back({idx[xx],xx});
    sort(ans.begin(),ans.end());
    if(!found) cout << ">> Not Found";
    else for(auto x : ans) cout << ">> " << x.second << '\n';
    return 0;
}