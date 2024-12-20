#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool sort_top_price(pair<string,double> &a,pair<string,double> &b)
{
    if(a.second != b.second) return a.second > b.second;
    else
    {
        return a.first < b.first;
    }
}

int main()
{
    vector<string> id;
    vector<double> cost;
    vector<double> sale;
    string cmd;
    int n = 0;
    while(1)
    {
        cin >> cmd;
        if(cmd == "END") break;
        double price;
        cin >> price;
        id.emplace_back(cmd);
        cost.emplace_back(price);
        sale.emplace_back(0);
        ++n;
    }
    while(cin >> cmd)
    {
        // if(cmd == "-1") break;
        for(int i=0;i<n;++i)
        {
            if(cmd == id[i])
            {
                sale[i] += cost[i];
            }
        }
    }
    vector<pair<string,double>> ans;
    for(int i=0;i<n;++i) ans.emplace_back(id[i],sale[i]);
    sort(ans.begin(),ans.end(),sort_top_price);
    // for(int i=0;i<n;++i) cout << ans[i].first << ' ' << ans[i].second << '\n';
    int cnt = 0;
    for(int i=0;i<min(n,3);++i) 
    {
        if(ans[i].second != 0) cout << ans[i].first << ' ' << ans[i].second << '\n';
        else ++cnt;
    }
    // cout << "Cnt = " << cnt << '\n';
    if(cnt == n || cnt == 3) cout << "No Sales";
    return 0;
}