#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string,vector<string>> mp;
    getchar();
    string tmp = "";
    string songname = "",singername = "";
    for(int i=0;i<n;++i)
    {
        string str = "";
        getline(cin,str);
        int len = str.size();
        for(int j=0;j<len;++j)
        {
            // cout << str[j];
            if(str[j] == ',')
            {
                songname = tmp;
                tmp = "";
                ++j;
                continue;
            }
            else if(j == len-1)
            {
                tmp += str[j];
                singername = tmp;
                tmp = "";
                continue;
            }
            tmp.push_back(str[j]);
        }
        // cout << '\n';
        // cout << "song_name : " << songname << " singer_name : " << singername << '\n';
        mp[songname].push_back(singername);
    }
    string q;
    getline(cin,q);
    tmp = "";
    int len = q.size();
    for(int i=0;i<len;++i)
    {
        if(q[i] == ',' || i == len-1)
        {
            if(i == len-1) tmp.push_back(q[i]);
            string song = tmp;
            cout << song << " -> ";
            // cout << "Song : " << song << '\n';
            if(!mp[song].empty())
            {
                int ans = mp[song].size();
                int cnt = 0;
                for(auto it=mp[song].begin();it!=mp[song].end();++it)
                {
                    cout << *it;
                    if(cnt != ans-1) cout << ", ";
                    ++cnt;
                }
                cout << '\n';
            }
            else cout << "Not found\n";
            tmp = "";
            ++i;
        }
        else tmp.push_back(q[i]);
    }
    return 0;
}