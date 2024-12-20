#include<bits/stdc++.h>
#define TC while(t--)
#define DEBUG(x) cout<<"Debug "<<#x<<':'<<x<<endl;
#define EL "\n"
#define ll long long
#define pii pair<int,int>
#define sz(x) (int)x.size()
#define st first
#define nd second
#define pb push_back
using namespace std;
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}
struct Edge
{
    ll u,v,w;
};
bool cmp(Edge a,Edge b)
{
    if(a.w!=b.w) return a.w<b.w;
    if(a.v!=b.v) return b.v<b.v;
    return a.u<b.u;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<pair<ll,ll>> vec(n+1);
    for(int i=1; i<=n; i++)
    {
        ll x,y;
        cin>>x>>y;
        vec[i]= {x,y};
    }
    vector<Edge> edge;
    for(int i=1; i<=n-1; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            ll dist=abs(vec[i].st-vec[j].st)+abs(vec[i].nd-vec[j].nd);
            edge.pb({i,j,dist});
        }
    }
    sort(edge.begin(),edge.end(),cmp);
    queue<Edge> q;
    for(auto it:edge)
    {
        cout<<it.u<<" "<<it.v<<" "<<it.w<<EL;
        q.push(it);
    }
    vector<int> graph[n+1];
    vector<ll> sorted;
    for(int i=1; i<=k; i++)
    {
        ll x;
        cin>>x;
        sorted.pb(x);
    }
    sort(sorted.begin(),sorted.end());
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    vector<ll> dist(n+1,INT_MAX);
    dist[1]=0;
    ll sum=0;
    for(auto it:sorted)
    {
        while(!q.empty())
        {
            Edge x=q.front();
            if(x.w<=it)
            {
                //cout<<x.u<<" asdas "<<x.v<<EL;
                graph[x.u].pb(x.v);
                graph[x.v].pb(x.u);
                q.pop();
                pq.push({dist[x.u],x.u});
                pq.push({dist[x.v],x.v});
            }
            else break;
        }
        pq.push({dist[1],1});
        while(!pq.empty())
        {
            ll u=pq.top().nd;
            cout << u << " ";
            pq.pop();
            for(auto v:graph[u])
            {
                if(dist[u]+1<dist[v])
                {
                    dist[v]=dist[u]+1;
                    pq.push({dist[v],v});
                }
            }
        }
        cout << '\n';
        cout << "dis[n] : " << dist[n] << "\n";
        sum+=dist[n];
        //DEBUG(dist[n]);
    }
    cout<<sum<<EL;
}
int main()
{
    fast();
    solve();
    /*int t;
    cin>>t;
    TC{
    	solve();
    }*/
    return 0;
}
/*
5 2
0 1
2 2
3 6
6 6
9 10
10
15
*/
