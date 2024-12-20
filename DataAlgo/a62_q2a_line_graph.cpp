#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
vector<int> g[N];
bool vis[N];

void dfs(int u,int par,bool &isLineGraph)
{
    vis[u] = true;
    if(g[u].size()>2)
    {
        isLineGraph = false;
        return ;
    }
    for(int v : g[u])
    {
        if(v != par)
        {
            if(vis[v])
            {
                isLineGraph = false;
                return ;
            }
            else dfs(v,u,isLineGraph);
        }
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;++i)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0;i<n;++i) vis[i] = false;
    // for(int i=0;i<n;++i)
    // {
    //     cout << i << ": ";
    //     for(int v : g[i]) cout << v << ' ';
    //     cout << '\n';
    // }
    int ans = 0;
    for(int i=0;i<n;++i)
    {
        if(!vis[i])
        {
            bool isLineGraph = true;
            dfs(i,-1,isLineGraph);
            if(isLineGraph) ++ans;
        }
    }
    cout << ans;
    return 0;
}