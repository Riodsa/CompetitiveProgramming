#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<pair<int,int>>> g(n+1);
    vector<bool> vis(n+1,false);
    vector<int> cost(n+1);
    vector<int> dist(n+1,1e9+7);
    // priority_queue<iii,vector<iii>,greater<>> pq;
    priority_queue<pii,vector<pii>,greater<>> pq;
    vector<int> atk_first;
    for(int i=0;i<k;++i)
    {
        int x; cin >> x;
        atk_first.push_back(x);
    }
    for(int i=0;i<n;++i) cin >> cost[i];
    for(int a : atk_first)
    {
        dist[a] = cost[a];
        pq.push({dist[a],a});
    }
    for(int i=0;i<m;++i)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back({v,cost[v]});
        g[v].push_back({u,cost[u]});
    }
    int min_time = 0;
    while(!pq.empty())
    {
        auto [d,u] = pq.top();
        pq.pop();
        if(d > dist[u]) continue;
        // cout << "hacked server number: " << u << " used time: " << d << '\n';
        vis[u] = true; 
        // cout << "around: ";
        for(auto [v,w] : g[u])
        {
            // cout << "(" << v << ", " << w << ") ";
            if(dist[v] > d + w)
            {
                dist[v] = d + w;
                pq.push({dist[v],v});
            }
        }
        // cout << '\n';
    }
    for(int i=0;i<n;++i) min_time = max(min_time,dist[i]);
    cout << min_time;
    return 0;
}