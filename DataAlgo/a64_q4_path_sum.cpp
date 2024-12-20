#include<bits/stdc++.h>
using namespace std;

const int N = 21;
#define pii pair<int,int>
int n,m;
int k[8];
vector<pii> g[N];
unordered_map<int,bool> has;

void print_path(vector<int> p,int sum_w)
{
    cout << "path: ";
    for(int u : p) cout << u << ' ';
    cout << " sum_w: " << sum_w << '\n';
    cout << '\n';
}

void dfs(int u,int par,int sum_w,vector<bool> vis,vector<int> path)
{
    // print_path(path,sum_w);
    has[sum_w] = true;
    for(auto [v,w] : g[u])
    {
        if(v != par && !vis[v])
        {
            vis[v] = true;
            path.push_back(v);
            dfs(v,u,sum_w+w,vis,path);
            path.pop_back();
            vis[v] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    vector<bool> vis(n+1,false);
    for(int i=0;i<8;++i) cin >> k[i];
    for(int i=0;i<n;++i) vis[i] = false;
    for(int i=0;i<m;++i)
    {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=0;i<n;++i)
    {
        vis[i] = true;
        vector<int> path(1,i);
        dfs(i,-1,0,vis,path);
        vis[i] = false;
    }
    for(int i=0;i<8;++i)
    { 
        if(has[k[i]]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}