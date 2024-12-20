#include<bits/stdc++.h>
using namespace std;

int n,e;
const int N = 1e4+1;
vector<int> g[N];
bool visited[N];
int cnt_component = 0;

void dfs(int u)
{
    visited[u] = true;
    for(int v : g[u]) if(!visited[v]) dfs(v);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> e;
    while(e--)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;++i)
    {
        if(!visited[i])
        {
            cnt_component++;
            dfs(i);
        }
    }
    cout << cnt_component;
    return 0;
}   