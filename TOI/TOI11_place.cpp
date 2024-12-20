#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 2e5+1;
int par[N];
int connected = 0;

int root(int u)
{
    if(par[u] == u) return u;
    return par[u] = root(par[u]);
}

priority_queue<tuple<int,int,int>> pq;
int n,m;
ll cnt_flag;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;++i)
    {
        int u,v,w;
        cin >> u >> v >> w;
        pq.push({w-1,u,v});
    }
    for(int i=1;i<=n;++i) par[i] = i;
    while(!pq.empty())
    {
        auto [w,u,v] = pq.top();
        pq.pop();
//        cout << "u = " << u << " v = " << v << " w = " << w << '\n';
        if(connected == n-1) break;
        int pu = root(u);
        int pv = root(v);

        if(pu == pv) continue;

        par[pv] = pu;
        cnt_flag += w;
        ++connected;
    }
    cout << cnt_flag;
    return 0;
}
