#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
    string song,artist,genre,time;
    map<string,int> mp;
    while(cin >> song >> artist >> genre >> time)
    {
        if(song == "X") break;
        int tmp=0;
        int min=0,sec=0;
        min = stoi(time.substr(0,time.size()-2));
        sec = stoi(time.substr(time.size()-2,2));
        tmp += 60*min+sec;
        mp[genre] += tmp;
    }
    vector<pair<int,string>> ans;
    for(auto it=mp.begin();it != mp.end();++it)
    {
    //     cout << it->first << " : " << it->second << '\n';
        ans.push_back({it->second,it->first});
    }
    sort(ans.begin(),ans.end(),greater<>());
    int len = ans.size();
    for(int i=0;i<min(3,len);++i)
    {
        int min = ans[i].first/60;
        int sec = ans[i].first%60;
        cout << ans[i].second << " --> " << min << ":" << sec << '\n';
    }
    return 0;
}