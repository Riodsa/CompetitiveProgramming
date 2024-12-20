#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> g[],vector<bool> &visited,int u,int prev,bool &hasCycle)
{
    if(visited[u])
    {
        hasCycle = true;
        return ;
    }
    visited[u] = true;
    for(int v : g[u])
    {
        if(v != prev) dfs(g,visited,v,u,hasCycle);
    }
    return ;
}

void solve()
{
    int n,e;
    cin >> n >> e;
    vector<int> g[n+1];
    vector<bool> visited(n+1,false);
    bool hasCycle = false;
    for(int i=0;i<e;++i)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0;i<n;++i)
    {
        if(!visited[i]) dfs(g,visited,i,-1,hasCycle);
    }
    cout << (hasCycle?"YES\n":"NO\n");
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}