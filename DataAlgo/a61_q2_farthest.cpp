#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,int>
const int N = 1e3+1;
const int INF = 1e9+7;
vector<pii> g[N];
ll dist[N];
bool vis[N];
int n;
ll max_dist = -1;
priority_queue<pii,vector<pii>,greater<pii>> pq;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            ll x; cin >> x;
            if(i == j) continue;
            if(x != -1) g[i].emplace_back(j,x);
        }
    }
    fill(dist,dist+n+1,INF);
    fill(vis,vis+n+1,false);
    vis[1] = true;
    dist[1] = 0;
    pq.push({dist[1],1});
    while(!pq.empty())
    {
        auto [d,u] = pq.top();
        pq.pop();
        vis[u] = true;
        for(auto [v,w] : g[u])
        {
            if(vis[v]) continue;
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                // cout << "PUSH " << v << '\n';
                pq.push({dist[v],v});
            }
        }
    }
    // for(int i=1;i<=n;++i)
    // {
    //     cout << i << ": ";
    //     for(auto [v,w] : g[i]) cout << '(' << v << "," << w << ") , ";
    //     cout << '\n';
    // }
    bool CanGoAll = true;
    for(int i=1;i<=n;++i)
    {
        if(dist[i] != INF) max_dist = max(max_dist,dist[i]);
        else CanGoAll = false;
    }
    if(CanGoAll) cout << max_dist << '\n';
    else cout << "-1";
    return 0;
}