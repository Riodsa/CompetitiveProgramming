#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
const int K = 1e4+1;
int n,k,t;
vector<int> lvl[K];
vector<int> g[N];
int vi[N];
int ti;
bool cycle;

bool dfs(int u)
{
    if(vi[u])
        return vi[u] == 1;
    vi[u] = 1;
    ++ti;

    for(int v : g[u])
    {
        if(dfs(v))
            return true;
    }
    vi[u] = 2;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> t;
    for(int i=1;i<=n;++i)
    {
        int l,p;
        cin >> l >> p;
        lvl[l].push_back(i);
        for(int j=1;j<=p;++j)
        {
            int v; cin >> v;
            g[i].push_back(v);
        }
    }
    int ans = -1;
    for(int i=1;i<=k;++i)
    {
        for(int u : lvl[i])
        {
            if(!vi[u])
            {
                if(dfs(u)) cycle = true;
            }
        }
        if(cycle || ti > t) break;
        ans = i;
    }
    cout << ans;
    return 0;
}
