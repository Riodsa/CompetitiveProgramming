#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 5e2+5;
#define pii pair<ll,ll>
int n,m;
pii point[N];

struct edge
{
    ll u,v,w;

    bool operator < (const edge &x)const{
        if(w != x.w) return w < x.w;
        if(v != x.v) return v < x.v;
        return u < x.u;
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;++i)
    {
        cin >> point[i].first >> point[i].second;
    }
    vector<edge> g;
    for(int i=1;i<n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            ll dist = abs(point[i].first-point[j].first) + abs(point[i].second-point[j].second);
            g.push_back({i,j,dist});
        }
    }
    sort(g.begin(),g.end());
    queue<edge> q;
    for(auto x : g)
    {
        q.push(x);
//        cout << x.u << " " << x.v << " " << x.w << '\n';
    }
    vector<ll> human;
    for(int i=1;i<=m;++i)
    {
        ll x; cin >> x;
        human.push_back(x);
    }
    vector<int> graph[n+1];
    sort(human.begin(),human.end());
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    vector<ll> dis(n+1,1e18+7);
    dis[1] = 0;
    ll ans = 0;
    for(ll power : human)
    {
        while(!q.empty())
        {
            edge x = q.front();
            if(x.w <= power)
            {
                graph[x.u].push_back(x.v);
                graph[x.v].push_back(x.u);
                q.pop();
                pq.push({dis[x.u],x.u});
                pq.push({dis[x.v],x.v});
            }
            else break;
        }
        pq.push({dis[1],1});
        while(!pq.empty())
        {
            ll u = pq.top().second;
            pq.pop();
            for(auto v : graph[u])
            {
                if(dis[u] + 1 < dis[v])
                {
                    dis[v] = dis[u]+1;
                    pq.push({dis[v],v});
                }
            }
        }
//        cout << '\n';
//        cout << "dis[n] : " << dis[n] << '\n';
        ans += dis[n];
    }
    cout << ans;
    return 0;
}
