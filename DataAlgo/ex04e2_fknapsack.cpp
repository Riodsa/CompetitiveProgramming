#include<bits/stdc++.h>
using namespace std;

#define ddd tuple<double,double,double>

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    double W,n;
    cin >> W >> n;
    vector<ddd> item;
    vector<double> value(n),weight(n);
    for(int i=0;i<n;++i) cin >> value[i];
    for(int i=0;i<n;++i) cin >> weight[i];
    for(int i=0;i<n;++i)
    {
        double profit = value[i]/weight[i];
        item.emplace_back(profit,value[i],weight[i]);
    }
    sort(item.begin(),item.end(),greater<>());
    // for(ddd x : item)
    // {
    //     auto [p,v,w] = x;
    //     cout << "profit: " << p << " value: " << v << " weight: " << w << '\n';
    // }
    // cout << '\n';
    auto it = item.begin();
    double ans = 0;
    double total_weight = 0;
    while(1)
    {
        auto [p,v,w] = *it;
        if(total_weight + w <= W)
        {
            ans += v;
            total_weight += w;
        }
        else
        {
            double remain_weight = W-total_weight;
            double new_value = p*remain_weight;
            total_weight += remain_weight;
            ans += new_value;
            break;
        }
        if(total_weight == W) break;
        if(it == item.end()) break;
        it++;
        // cout << "total_weight: " << total_weight << '\n';
    }
    cout << fixed << setprecision(4) << ans;
    return 0;
}