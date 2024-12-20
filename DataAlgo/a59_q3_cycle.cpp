#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
bool vis[N];
vector<int> g[N];
int n;
int max_cycle;
bool found_cycle = false;

int find_max_cycle(vector<int> path)
{
    // cout << "path: ";
    // for(int v : path) cout << v << ' ';
    // cout << '\n';
    int len = path.size();
    int tar = path[len-1];
    // cout << "target: " << tar << '\n';
    for(int i=0;i<len;++i)
    {
        if(tar == path[i])
        {
            return len-i-1;
        }
    }
}

void dfs(int u,int par,vector<int> path)
{
    vis[u] = true;
    for(int v : g[u])
    {
        if(v != par)
        {
            path.push_back(v);
            if(!vis[v])
            {
                dfs(v,u,path);
                path.pop_back();
            }
            else
            {
                if(!found_cycle) max_cycle = max(max_cycle,find_max_cycle(path));
                found_cycle = true;
                return ;
            }
        }
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0;i<n;++i)
    {
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> tmp(1,0);
    dfs(0,-1,tmp);
    cout << max_cycle << '\n';
    return 0;
}