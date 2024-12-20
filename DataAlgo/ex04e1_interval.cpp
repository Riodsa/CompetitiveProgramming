#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> vec;
    vector<int> start(n);
    vector<int> stop(n);
    for(int i=0;i<n;++i) cin >> start[i];
    for(int i=0;i<n;++i) cin >> stop[i];
    vector<pair<int,int>> c;
    for(int i=0;i<n;++i) vec.push_back({stop[i],start[i]});
    sort(vec.begin(),vec.end());
    int now = 0;
    int ans = 0;
    for(auto [e,s] : vec)
    {
        if(now <= s)
        {
            ans++;
            now = e;
        }
        else continue;
    }
    cout << ans;
    return 0;
}