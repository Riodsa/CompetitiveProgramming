#include<bits/stdc++.h>
using namespace std;

const int N = 1e3+1;
int n,e,k;
vector<int> g[N];
bool vis[N];
int ans = -1;
int ans_idx = -1;

void dfs(int u,int prev,int depth,int &cnt)
{
    if(!vis[u]) cnt++;
    vis[u] = true;
    if(depth < k)
        for(int v : g[u]) if(v != prev) dfs(v,u,depth+1,cnt);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> e >> k;
    for(int i=0;i<e;++i)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j) vis[j] = false;
        int cnt = 0;
        dfs(i,-1,0,cnt);
        if(ans < cnt)
        {
            ans = cnt;
            ans_idx = i;
        }
    }
    cout << ans << " from " << ans_idx;
    return 0;
}   