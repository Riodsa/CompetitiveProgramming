#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<ll,ll>
const int INF = 1e9+7;
const int N = 7e2+1;
vector<pii> g[N];
ll dist[N];
ll n,start;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> start;
    fill(dist,dist+n+1,INF);
    dist[1] = 0;
    dist[2] = start;
    g[1].push_back({2,start});
    g[2].push_back({1,start});
    for(int i=3;i<=n;++i)
    {
        ll min_dist = INF;
        ll u = i;
        ll m;
        cin >> m;
        for(int i=0;i<m;++i)
        {
            int v,w;
            cin >> v >> w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
            min_dist = min(min_dist,dist[v]+w);
        }
        priority_queue<iii,vector<iii>,greater<>> pq;
        dist[u] = min_dist;
        pq.push({min_dist,u});
        while(!pq.empty())
        {
            auto [d,now] = pq.top();
            pq.pop();
            // cout << "Now at " << now << '\n';
            if(dist[now] < d) continue;
            for(auto [v,w] : g[now])
            {
                // cout << "go to " << v << " in " << dist[now]+w << " (old: " << dist[v] << ")\n";
                if(dist[v] > dist[now]+w)
                {
                    dist[v] = dist[now]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        // for(int i=1;i<=n;++i) cout << dist[i] << ' ';
        // cout << '\n';
        cout << dist[2] << ' ';
    }
    return 0;
}