#include<bits/stdc++.h>
using namespace std;

map<vector<pair<int,int>>,int> mp;

int main()
{
    int t,q;
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t >> q;
    while(t--)
    {
        int n;
        cin >> n;
        vector<pair<int,int>> g;
        for(int i=0;i<n-1;++i)
        {
            int u,v;
            cin >> u >> v;
            if(u > v) swap(u,v);
            g.emplace_back(u,v);
        }
        sort(g.begin(),g.end());
        mp[g]++;
    }
    while(q--)
    {
        int n;
        cin >> n;
        vector<pair<int,int>> g;
        for(int i=0;i<n-1;++i)
        {
            int u,v;
            cin >> u >> v;
            if(u > v) swap(u,v);
            g.emplace_back(u,v);
        }
        sort(g.begin(),g.end());
        cout << mp[g] << '\n';
    }
    return 0;
}
